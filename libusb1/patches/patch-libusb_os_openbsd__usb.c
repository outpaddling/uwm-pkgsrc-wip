$NetBSD: patch-libusb_os_openbsd__usb.c,v 1.3 2012/11/20 13:01:47 pettai Exp $

Fix build on Dragonfly.
Add support for non ugen(4) attached devices through usb(4) buses.

--- libusb/os/openbsd_usb.c.orig	2012-11-20 11:50:40.000000000 +0000
+++ libusb/os/openbsd_usb.c
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2011 Martin Pieuchot <mpi@openbsd.org>
+ * Copyright (c) 2011-2012 Martin Pieuchot <mpi@openbsd.org>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -36,8 +36,8 @@
 #include "libusbi.h"
 
 struct device_priv {
-	char devnode[16];
-	int fd;
+	char *devname;				/* name of the ugen(4) node */
+	int fd;					/* device file descriptor */
 
 	unsigned char *cdesc;			/* active config descriptor */
 	usb_device_descriptor_t ddesc;		/* usb device descriptor */
@@ -91,6 +91,13 @@ static int _sync_control_transfer(struct
 static int _sync_gen_transfer(struct usbi_transfer *);
 static int _access_endpoint(struct libusb_transfer *);
 
+static int _bus_open(int);
+static int _bus_get_config(int, int, int *);
+static int _bus_get_device_desc(int, int, usb_device_descriptor_t *);
+static int _bus_get_full_desc(int, int, int, int, void *);
+static int _bus_get_config_desc(int, int, int, usb_config_descriptor_t *);
+
+
 const struct usbi_os_backend openbsd_backend = {
 	"Synchronous OpenBSD backend",
 	NULL,				/* init() */
@@ -132,75 +139,102 @@ const struct usbi_os_backend openbsd_bac
 	0,				/* add_iso_packet_size */
 };
 
+#define DEVPATH	"/dev/"
+#define USBDEV	DEVPATH "usb"
+
 int
 obsd_get_device_list(struct libusb_context * ctx,
 	struct discovered_devs **discdevs)
 {
+	struct discovered_devs *dd;
 	struct libusb_device *dev;
 	struct device_priv *dpriv;
 	struct usb_device_info di;
 	unsigned long session_id;
-	char devnode[16];
-	int fd, err, i;
+	char devices[USB_MAX_DEVICES];
+	char busnode[16];
+	char *udevname;
+	int fd, addr, i, j;
 
 	usbi_dbg("");
 
-	/* Only ugen(4) is supported */
-	for (i = 0; i < USB_MAX_DEVICES; i++) {
-		/* Control endpoint is always .00 */
-		snprintf(devnode, sizeof(devnode), "/dev/ugen%d.00", i);
+	for (i = 0; i < 8; i++) {
+		snprintf(busnode, sizeof(busnode), USBDEV "%d", i);
 
-		if ((fd = open(devnode, O_RDONLY)) < 0) {
+		if ((fd = open(busnode, O_RDWR)) < 0) {
 			if (errno != ENOENT && errno != ENXIO)
-				usbi_err(ctx, "could not open %s", devnode);
+				usbi_err(ctx, "could not open %s", busnode);
 			continue;
 		}
 
-		if (ioctl(fd, USB_GET_DEVICEINFO, &di) < 0)
-			continue;
-
-		session_id = (di.udi_bus << 8 | di.udi_addr);
-		dev = usbi_get_device_by_session_id(ctx, session_id);
-
-		if (dev == NULL) {
-			dev = usbi_alloc_device(ctx, session_id);
-			if (dev == NULL)
-				return (LIBUSB_ERROR_NO_MEM);
+		bzero(devices, sizeof(devices));
+		for (addr = 1; addr < USB_MAX_DEVICES; addr++) {
+			if (devices[addr])
+				continue;
+
+			di.udi_addr = addr;
+			if (ioctl(fd, USB_DEVICEINFO, &di) < 0)
+				continue;
+
+			/*
+			 * XXX If ugen(4) is attached to the USB device
+			 * it will be used.
+			 */
+			udevname = NULL;
+			for (j = 0; j < USB_MAX_DEVNAMES; j++)
+				if (!strncmp("ugen", di.udi_devnames[j], 4)) {
+					udevname = strdup(di.udi_devnames[j]);
+					break;
+				}
+
+			session_id = (di.udi_bus << 8 | di.udi_addr);
+			dev = usbi_get_device_by_session_id(ctx, session_id);
+
+			if (dev == NULL) {
+				dev = usbi_alloc_device(ctx, session_id);
+				if (dev == NULL) {
+					close(fd);
+					return (LIBUSB_ERROR_NO_MEM);
+				}
+
+				dev->bus_number = di.udi_bus;
+				dev->device_address = di.udi_addr;
+				dev->speed = di.udi_speed;
+
+				dpriv = (struct device_priv *)dev->os_priv;
+				dpriv->fd = -1;
+				dpriv->cdesc = NULL;
+				dpriv->devname = udevname;
+
+				if (_bus_get_device_desc(fd, addr, &dpriv->ddesc)) {
+					libusb_unref_device(dev);
+					continue;
+				}
+
+				/* XXX Assume the active config is at index 0 */
+				if (_cache_active_config_descriptor(dev, 0)) {
+					libusb_unref_device(dev);
+					continue;
+				}
 
-			dev->bus_number = di.udi_bus;
-			dev->device_address = di.udi_addr;
-			dev->speed = di.udi_speed;
-
-			dpriv = (struct device_priv *)dev->os_priv;
-			strlcpy(dpriv->devnode, devnode, sizeof(devnode));
-			dpriv->fd = -1;
-
-			if (ioctl(fd, USB_GET_DEVICE_DESC, &dpriv->ddesc) < 0) {
-				err = errno;
-				goto error;
+				if (usbi_sanitize_device(dev))
+					libusb_unref_device(dev);
 			}
 
-			dpriv->cdesc = NULL;
-			if (_cache_active_config_descriptor(dev, fd)) {
-				err = errno;
-				goto error;
+			dd = discovered_devs_append(*discdevs, dev);
+			if (dd == NULL) {
+				close(fd);
+				return (LIBUSB_ERROR_NO_MEM);
 			}
 
-			if ((err = usbi_sanitize_device(dev)))
-				goto error;
+			*discdevs = dd;
+			devices[addr] = 1;
 		}
-		close(fd);
 
-		if (discovered_devs_append(*discdevs, dev) == NULL)
-			return (LIBUSB_ERROR_NO_MEM);
+		close(fd);
 	}
 
 	return (LIBUSB_SUCCESS);
-
-error:
-	close(fd);
-	libusb_unref_device(dev);
-	return _errno_to_libusb(err);
 }
 
 int
@@ -208,15 +242,21 @@ obsd_open(struct libusb_device_handle *h
 {
 	struct handle_priv *hpriv = (struct handle_priv *)handle->os_priv;
 	struct device_priv *dpriv = (struct device_priv *)handle->dev->os_priv;
+	char devnode[16];
 
-	dpriv->fd = open(dpriv->devnode, O_RDWR);
-	if (dpriv->fd < 0) {
-		dpriv->fd = open(dpriv->devnode, O_RDONLY);
+	if (dpriv->devname) {
+		/*
+		 * Only open ugen(4) attached devices read-write, all
+		 * read-only operations are done through the bus node.
+		 */
+		snprintf(devnode, sizeof(devnode), DEVPATH "%s.00",
+		    dpriv->devname);
+		dpriv->fd = open(devnode, O_RDWR);
 		if (dpriv->fd < 0)
 			return _errno_to_libusb(errno);
-	}
 
-	usbi_dbg("open %s: fd %d", dpriv->devnode, dpriv->fd);
+		usbi_dbg("open %s: fd %d", devnode, dpriv->fd);
+	}
 
 	if (pipe(hpriv->pipe) < 0)
 		return _errno_to_libusb(errno);
@@ -230,10 +270,12 @@ obsd_close(struct libusb_device_handle *
 	struct handle_priv *hpriv = (struct handle_priv *)handle->os_priv;
 	struct device_priv *dpriv = (struct device_priv *)handle->dev->os_priv;
 
-	usbi_dbg("close: fd %d", dpriv->fd);
+	if (dpriv->devname) {
+		usbi_dbg("close: fd %d", dpriv->fd);
 
-	close(dpriv->fd);
-	dpriv->fd = -1;
+		close(dpriv->fd);
+		dpriv->fd = -1;
+	}
 
 	usbi_remove_pollfd(HANDLE_CTX(handle), hpriv->pipe[0]);
 
@@ -279,34 +321,19 @@ int
 obsd_get_config_descriptor(struct libusb_device *dev, uint8_t idx,
     unsigned char *buf, size_t len, int *host_endian)
 {
-	struct device_priv *dpriv = (struct device_priv *)dev->os_priv;
-	struct usb_full_desc ufd;
 	int fd, err;
 
-	usbi_dbg("index %d, len %d", idx, len);
-
-	/* A config descriptor may be requested before opening the device */
-	if (dpriv->fd >= 0) {
-		fd = dpriv->fd;
-	} else {
-		fd = open(dpriv->devnode, O_RDONLY);
-		if (fd < 0)
-			return _errno_to_libusb(errno);
-	}
+	if ((fd = _bus_open(dev->bus_number)) < 0)
+		return _errno_to_libusb(errno);
 
-	ufd.ufd_config_index = idx;
-	ufd.ufd_size = len;
-	ufd.ufd_data = buf;
+	usbi_dbg("index %d, len %d", idx, len);
 
-	if ((ioctl(fd, USB_GET_FULL_DESC, &ufd)) < 0) {
+	if (_bus_get_full_desc(fd, dev->device_address, idx, len, buf)) {
 		err = errno;
-		if (dpriv->fd < 0)
-			close(fd);
+		close(fd);
 		return _errno_to_libusb(err);
 	}
-
-	if (dpriv->fd < 0)
-		close(fd);
+	close(fd);
 
 	*host_endian = 0;
 
@@ -316,14 +343,19 @@ obsd_get_config_descriptor(struct libusb
 int
 obsd_get_configuration(struct libusb_device_handle *handle, int *config)
 {
-	struct device_priv *dpriv = (struct device_priv *)handle->dev->os_priv;
-
-	usbi_dbg("");
+	int fd, err;
 
-	if (ioctl(dpriv->fd, USB_GET_CONFIG, config) < 0)
+	if ((fd = _bus_open(handle->dev->bus_number)) < 0)
 		return _errno_to_libusb(errno);
 
-	usbi_dbg("configuration %d", *config);
+	if (_bus_get_config(fd, handle->dev->device_address, config)) {
+		err = errno;
+		close(fd);
+		return _errno_to_libusb(err);
+	}
+	close(fd);
+
+	usbi_dbg("bConfigurationValue %d", *config);
 
 	return (LIBUSB_SUCCESS);
 }
@@ -332,13 +364,23 @@ int
 obsd_set_configuration(struct libusb_device_handle *handle, int config)
 {
 	struct device_priv *dpriv = (struct device_priv *)handle->dev->os_priv;
+	int idx;
 
-	usbi_dbg("configuration %d", config);
+	if (dpriv->devname == NULL)
+		return (LIBUSB_ERROR_NOT_SUPPORTED);
+
+	usbi_dbg("bConfigurationValue %d", config);
 
 	if (ioctl(dpriv->fd, USB_SET_CONFIG, &config) < 0)
 		return _errno_to_libusb(errno);
 
-	return _cache_active_config_descriptor(handle->dev, dpriv->fd);
+	/*
+	 * XXX Instead of assuming that the index is at bConfigurationValue
+	 * minus one, we should iterate against the possible configurations.
+	 */
+	idx = config - 1;
+
+	return _cache_active_config_descriptor(handle->dev, idx);
 }
 
 int
@@ -373,6 +415,9 @@ obsd_set_interface_altsetting(struct lib
 	struct device_priv *dpriv = (struct device_priv *)handle->dev->os_priv;
 	struct usb_alt_interface intf;
 
+	if (dpriv->devname == NULL)
+		return (LIBUSB_ERROR_NOT_SUPPORTED);
+
 	usbi_dbg("iface %d, setting %d", iface, altsetting);
 
 	memset(&intf, 0, sizeof(intf));
@@ -389,19 +434,27 @@ obsd_set_interface_altsetting(struct lib
 int
 obsd_clear_halt(struct libusb_device_handle *handle, unsigned char endpoint)
 {
-	struct device_priv *dpriv = (struct device_priv *)handle->dev->os_priv;
 	struct usb_ctl_request req;
+	int fd, err;
+
+	if ((fd = _bus_open(handle->dev->bus_number)) < 0)
+		return _errno_to_libusb(errno);
 
 	usbi_dbg("");
 
+	req.ucr_addr = handle->dev->device_address;
 	req.ucr_request.bmRequestType = UT_WRITE_ENDPOINT;
 	req.ucr_request.bRequest = UR_CLEAR_FEATURE;
 	USETW(req.ucr_request.wValue, UF_ENDPOINT_HALT);
 	USETW(req.ucr_request.wIndex, endpoint);
 	USETW(req.ucr_request.wLength, 0);
 
-	if (ioctl(dpriv->fd, USB_DO_REQUEST, &req) < 0)
-		return _errno_to_libusb(errno);
+	if (ioctl(fd, USB_REQUEST, &req) < 0) {
+		err = errno;
+		close(fd);
+		return _errno_to_libusb(err);
+	}
+	close(fd);
 
 	return (LIBUSB_SUCCESS);
 }
@@ -422,6 +475,7 @@ obsd_destroy_device(struct libusb_device
 	usbi_dbg("");
 
 	free(dpriv->cdesc);
+	free(dpriv->devname);
 }
 
 int
@@ -561,6 +615,8 @@ obsd_clock_gettime(int clkid, struct tim
 int
 _errno_to_libusb(int err)
 {
+	usbi_dbg("error: %s (%d)", strerror(err), err);
+
 	switch (err) {
 	case EIO:
 		return (LIBUSB_ERROR_IO);
@@ -570,52 +626,52 @@ _errno_to_libusb(int err)
 		return (LIBUSB_ERROR_NO_DEVICE);
 	case ENOMEM:
 		return (LIBUSB_ERROR_NO_MEM);
+	case ETIMEDOUT:
+		return (LIBUSB_ERROR_TIMEOUT);
 	}
 
-	usbi_dbg("error: %s", strerror(err));
-
 	return (LIBUSB_ERROR_OTHER);
 }
 
 int
-_cache_active_config_descriptor(struct libusb_device *dev, int fd)
+_cache_active_config_descriptor(struct libusb_device *dev, int idx)
 {
 	struct device_priv *dpriv = (struct device_priv *)dev->os_priv;
-	struct usb_config_desc ucd;
-	struct usb_full_desc ufd;
+	usb_config_descriptor_t cdesc;
 	unsigned char* buf;
-	int len;
+	int fd, len, err;
 
-	usbi_dbg("fd %d", fd);
+	if ((fd = _bus_open(dev->bus_number)) < 0)
+		return _errno_to_libusb(errno);
 
-	ucd.ucd_config_index = USB_CURRENT_CONFIG_INDEX;
+	usbi_dbg("fd %d, addr %d", fd, dev->device_address);
 
-	if ((ioctl(fd, USB_GET_CONFIG_DESC, &ucd)) < 0)
+	if (_bus_get_config_desc(fd, dev->device_address, idx, &cdesc)) {
+		err = errno;
+		close(fd);
 		return _errno_to_libusb(errno);
+	}
 
-	usbi_dbg("active bLength %d", ucd.ucd_desc.bLength);
+	usbi_dbg("active bLength %d", cdesc.bLength);
 
-	len = UGETW(ucd.ucd_desc.wTotalLength);
+	len = UGETW(cdesc.wTotalLength);
 	buf = malloc(len);
 	if (buf == NULL)
 		return (LIBUSB_ERROR_NO_MEM);
 
-	ufd.ufd_config_index = ucd.ucd_config_index;
-	ufd.ufd_size = len;
-	ufd.ufd_data = buf;
-
-	usbi_dbg("index %d, len %d", ufd.ufd_config_index, len);
-
-	if ((ioctl(fd, USB_GET_FULL_DESC, &ufd)) < 0) {
+	if (_bus_get_full_desc(fd, dev->device_address, idx, len, buf)) {
+		err = errno;
+		close(fd);
 		free(buf);
-		return _errno_to_libusb(errno);
+		return _errno_to_libusb(err);
 	}
+	close(fd);
 
 	if (dpriv->cdesc)
 		free(dpriv->cdesc);
 	dpriv->cdesc = buf;
 
-	return (0);
+	return (LIBUSB_SUCCESS);
 }
 
 int
@@ -630,12 +686,13 @@ _sync_control_transfer(struct usbi_trans
 	dpriv = (struct device_priv *)transfer->dev_handle->dev->os_priv;
 	setup = (struct libusb_control_setup *)transfer->buffer;
 
-	usbi_dbg("type %d request %d value %d index %d length %d timeout %d",
+	usbi_dbg("type %x request %x value %x index %d length %d timeout %d",
 	    setup->bmRequestType, setup->bRequest,
 	    libusb_le16_to_cpu(setup->wValue),
 	    libusb_le16_to_cpu(setup->wIndex),
 	    libusb_le16_to_cpu(setup->wLength), transfer->timeout);
 
+	req.ucr_addr = transfer->dev_handle->dev->device_address;
 	req.ucr_request.bmRequestType = setup->bmRequestType;
 	req.ucr_request.bRequest = setup->bRequest;
 	/* Don't use USETW, libusb already deals with the endianness */
@@ -647,11 +704,30 @@ _sync_control_transfer(struct usbi_trans
 	if ((transfer->flags & LIBUSB_TRANSFER_SHORT_NOT_OK) == 0)
 		req.ucr_flags = USBD_SHORT_XFER_OK;
 
-	if ((ioctl(dpriv->fd, USB_SET_TIMEOUT, &transfer->timeout)) < 0)
-		return _errno_to_libusb(errno);
+	if (dpriv->devname == NULL) {
+		/*
+		 * XXX If the device is not attached to ugen(4) it is
+		 * XXX still possible to submit a control transfer but
+		 * XXX with the default timeout only.
+		 */
+		int fd, err;
 
-	if ((ioctl(dpriv->fd, USB_DO_REQUEST, &req)) < 0)
-		return _errno_to_libusb(errno);
+		if ((fd = _bus_open(transfer->dev_handle->dev->bus_number)) < 0)
+			return _errno_to_libusb(errno);
+
+		if ((ioctl(fd, USB_REQUEST, &req)) < 0) {
+			err = errno;
+			close(fd);
+			return _errno_to_libusb(err);
+		}
+		close(fd);
+	} else {
+		if ((ioctl(dpriv->fd, USB_SET_TIMEOUT, &transfer->timeout)) < 0)
+			return _errno_to_libusb(errno);
+
+		if ((ioctl(dpriv->fd, USB_DO_REQUEST, &req)) < 0)
+			return _errno_to_libusb(errno);
+	}
 
 	itransfer->transferred = req.ucr_actlen;
 
@@ -665,7 +741,7 @@ _access_endpoint(struct libusb_transfer 
 {
 	struct handle_priv *hpriv;
 	struct device_priv *dpriv;
-	char *s, devnode[16];
+	char devnode[16];
 	int fd, endpt;
 	mode_t mode;
 
@@ -678,10 +754,9 @@ _access_endpoint(struct libusb_transfer 
 	usbi_dbg("endpoint %d mode %d", endpt, mode);
 
 	if (hpriv->endpoints[endpt] < 0) {
-		/* Pick the right node given the control one */
-		strlcpy(devnode, dpriv->devnode, sizeof(devnode));
-		s = strchr(devnode, '.');
-		snprintf(s, 4, ".%02d", endpt);
+		/* Pick the right endpoint node */
+		snprintf(devnode, sizeof(devnode), DEVPATH "%s.%02d",
+		    dpriv->devname, endpt);
 
 		/* We may need to read/write to the same endpoint later. */
 		if (((fd = open(devnode, O_RDWR)) < 0) && (errno == ENXIO))
@@ -698,9 +773,14 @@ int
 _sync_gen_transfer(struct usbi_transfer *itransfer)
 {
 	struct libusb_transfer *transfer;
+	struct device_priv *dpriv;
 	int fd, nr = 1;
 
 	transfer = USBI_TRANSFER_TO_LIBUSB_TRANSFER(itransfer);
+	dpriv = (struct device_priv *)transfer->dev_handle->dev->os_priv;
+
+	if (dpriv->devname == NULL)
+		return (LIBUSB_ERROR_NOT_SUPPORTED);
 
 	/*
 	 * Bulk, Interrupt or Isochronous transfer depends on the
@@ -729,3 +809,86 @@ _sync_gen_transfer(struct usbi_transfer 
 
 	return (0);
 }
+
+int
+_bus_open(int number)
+{
+	char busnode[16];
+
+	snprintf(busnode, sizeof(busnode), USBDEV "%d", number);
+
+	return open(busnode, O_RDWR);
+}
+
+int
+_bus_get_config(int fd, int addr, int *config)
+{
+	struct usb_ctl_request req;
+	uint8_t conf;
+	int err;
+
+	usbi_dbg("");
+
+	req.ucr_addr = addr;
+	req.ucr_request.bmRequestType = UT_READ_DEVICE;
+	req.ucr_request.bRequest = UR_GET_CONFIG;
+	USETW(req.ucr_request.wValue, 0);
+	USETW(req.ucr_request.wIndex, 0);
+	USETW(req.ucr_request.wLength, 1);
+	req.ucr_data = &conf;
+	req.ucr_flags = 0;
+
+	err = ioctl(fd, USB_REQUEST, &req);
+
+	*config = conf;
+
+	return (err);
+}
+
+static int
+_bus_get_desc(int fd, int addr, uint8_t type, uint8_t idx, int len, void *desc)
+{
+	struct usb_ctl_request req;
+
+	usbi_dbg("addr %d type %d index %d len %d", addr, type, idx, len);
+
+	req.ucr_addr = addr;
+	req.ucr_request.bmRequestType = UT_READ_DEVICE;
+	req.ucr_request.bRequest = UR_GET_DESCRIPTOR;
+	USETW2(req.ucr_request.wValue, type, idx);
+	USETW(req.ucr_request.wIndex, 0);
+	USETW(req.ucr_request.wLength, len);
+	req.ucr_data = desc;
+	req.ucr_flags = 0;
+
+	if (ioctl(fd, USB_REQUEST, &req) < 0)
+		return _errno_to_libusb(errno);
+
+	return (0);
+}
+
+int
+_bus_get_device_desc(int fd, int addr, usb_device_descriptor_t *ddesc)
+{
+	usbi_dbg("");
+
+	return _bus_get_desc(fd, addr, UDESC_DEVICE, 0,
+	    USB_DEVICE_DESCRIPTOR_SIZE, ddesc);
+}
+
+int
+_bus_get_config_desc(int fd, int addr, int idx, usb_config_descriptor_t *cdesc)
+{
+	usbi_dbg("config index %d", idx);
+
+	return _bus_get_desc(fd, addr, UDESC_CONFIG, idx,
+	    USB_CONFIG_DESCRIPTOR_SIZE, cdesc);
+}
+
+int
+_bus_get_full_desc(int fd, int addr, int idx, int size, void *desc)
+{
+	usbi_dbg("config index %d size %d", idx, size);
+
+	return _bus_get_desc(fd, addr, UDESC_CONFIG, idx, size, desc);
+}

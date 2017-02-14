# $NetBSD$
# FreeBSD Id: ports/devel/roboctl/Makefile,v 1.9 2010/03/28 06:33:38 dinoex Exp

DISTNAME=	roboctl-0.3.9
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports
COMMENT=	API and tools for communicating with Lego and Vex robots

.include "../../mk/bsd.prefs.mk"

# Enable this on NetBSD
.if ${OPSYS} == NetBSD
MAKE_ENV+=	EXTRALIBS=-lbluetooth
.endif
MAKE_ENV+=	MANPREFIX=${PREFIX}
MAKE_JOBS_UNSAFE=	yes

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANPREFIX=${DESTDIR}${PREFIX}

.if ${OPSYS} != NetBSD
SUBST_CLASSES+=		bluetooth
SUBST_STAGE.bluetooth=	post-patch
SUBST_FILES.bluetooth=	${WRKSRC}/Commands/Legoctl/Makefile
SUBST_SED.bluetooth=	-e 's|-lbluetooth||g'
.endif

pre-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} depend)

# Enable this on NetBSD and update PLIST accordingly
.if ${OPSYS} == NetBSD
post-install:
	(cd ${WRKSRC}/Commands/NXTRemote && ${SETENV} ${MAKE_ENV} ${MAKE} install)
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/lego_bluetooth_config ${PREFIX}/bin
.endif

# Not working yet
# .include "../../uwm-pkgsrc-wip/libgamepad/buildlink3.mk"
.include "../../uwm-pkgsrc-wip/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

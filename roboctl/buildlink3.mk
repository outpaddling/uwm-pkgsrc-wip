# $NetBSD$

BUILDLINK_TREE+=	roboctl

.if !defined(ROBOCTL_BUILDLINK3_MK)
ROBOCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.roboctl+=	roboctl>=0.3.8
BUILDLINK_PKGSRCDIR.roboctl?=	../../uwm-pkgsrc-wip/roboctl

# .include "../../uwm-pkgsrc-wip/libgamepad/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.endif	# ROBOCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-roboctl

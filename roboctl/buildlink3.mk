# $NetBSD$

BUILDLINK_TREE+=	roboctl

.if !defined(ROBOCTL_BUILDLINK3_MK)
ROBOCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.roboctl+=	roboctl>=0.3.8
BUILDLINK_PKGSRCDIR.roboctl?=	../../jb-wip/roboctl

# .include "../../jb-wip/libgamepad/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.endif	# ROBOCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-roboctl

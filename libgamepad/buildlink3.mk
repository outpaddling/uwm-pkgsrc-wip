# $NetBSD$

BUILDLINK_TREE+=	libgamepad

.if !defined(LIBGAMEPAD_BUILDLINK3_MK)
LIBGAMEPAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgamepad+=	libgamepad>=0.1.2
BUILDLINK_PKGSRCDIR.libgamepad?=	../../uwm-pkgsrc-wip/libgamepad
.endif	# LIBGAMEPAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgamepad

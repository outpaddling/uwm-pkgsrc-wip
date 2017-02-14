# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.nco?=	build

BUILDLINK_TREE+=	nco

.if !defined(NCO_BUILDLINK3_MK)
NCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nco+=	nco>=4.4.8
BUILDLINK_PKGSRCDIR.nco?=	../../uwm-pkgsrc-wip/nco
.endif	# NCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-nco

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
# XXX	BUILDLINK_DEPMETHOD.pbdagcon?=	build

BUILDLINK_TREE+=	pbdagcon

.if !defined(PBDAGCON_BUILDLINK3_MK)
PBDAGCON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pbdagcon+=	pbdagcon>=2015.08.19
BUILDLINK_PKGSRCDIR.pbdagcon?=	../../uwm-pkgsrc-wip/pbdagcon
.endif	# PBDAGCON_BUILDLINK3_MK

BUILDLINK_TREE+=	-pbdagcon

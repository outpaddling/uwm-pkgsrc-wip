# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.17.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gflags?=	build

BUILDLINK_TREE+=	gflags

.if !defined(GFLAGS_BUILDLINK3_MK)
GFLAGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gflags+=	gflags>=2.1.2
BUILDLINK_PKGSRCDIR.gflags?=	../../jb-wip/gflags
.endif	# GFLAGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gflags

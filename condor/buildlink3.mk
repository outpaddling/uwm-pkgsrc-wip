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
# XXX	BUILDLINK_DEPMETHOD.condor?=	build

BUILDLINK_TREE+=	condor

.if !defined(CONDOR_BUILDLINK3_MK)
CONDOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.condor+=	condor>=8.2.6
BUILDLINK_PKGSRCDIR.condor?=	../../jb-wip/condor
.endif	# CONDOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-condor

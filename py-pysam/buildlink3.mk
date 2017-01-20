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
# XXX	BUILDLINK_DEPMETHOD.pysam?=	build

BUILDLINK_TREE+=	pysam

.if !defined(PYSAM_BUILDLINK3_MK)
PYSAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pysam+=	${PYPKGPREFIX}-pysam>=0.8.3
BUILDLINK_PKGSRCDIR.pysam?=	../../jb-wip/py-pysam

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/ncurses/buildlink3.mk"
.endif	# PYSAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-pysam

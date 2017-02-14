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
# XXX	BUILDLINK_DEPMETHOD.tophat?=	build

BUILDLINK_TREE+=	tophat

.if !defined(TOPHAT_BUILDLINK3_MK)
TOPHAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tophat+=	tophat>=2.0.11
BUILDLINK_PKGSRCDIR.tophat?=	../../uwm-pkgsrc-wip/tophat

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../wip/samtools/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../wip/bowtie/buildlink3.mk"
.endif	# TOPHAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tophat

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
# XXX	BUILDLINK_DEPMETHOD.liblemon?=	build

BUILDLINK_TREE+=	liblemon

.if !defined(LIBLEMON_BUILDLINK3_MK)
LIBLEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblemon+=	liblemon>=1.3.1
BUILDLINK_PKGSRCDIR.liblemon?=	../../jb-wip/liblemon

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../math/coinmp/buildlink3.mk"
#.include "../../math/glpk/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../archivers/bzip2/buildlink3.mk"
.endif	# LIBLEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblemon

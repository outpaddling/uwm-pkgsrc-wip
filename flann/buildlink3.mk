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
# XXX	BUILDLINK_DEPMETHOD.flann?=	build

BUILDLINK_TREE+=	flann

.if !defined(FLANN_BUILDLINK3_MK)
FLANN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flann+=	flann>=1.8.4
BUILDLINK_PKGSRCDIR.flann?=	../../uwm-pkgsrc-wip/flann

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/hdf5/buildlink3.mk"
#.include "../../archivers/szip/buildlink3.mk"
#.include "../../devel/googletest/buildlink3.mk"
.endif	# FLANN_BUILDLINK3_MK

BUILDLINK_TREE+=	-flann

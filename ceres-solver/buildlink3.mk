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
# XXX	BUILDLINK_DEPMETHOD.ceres-solver?=	build

BUILDLINK_TREE+=	ceres-solver

.if !defined(CERES_SOLVER_BUILDLINK3_MK)
CERES_SOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ceres-solver+=	ceres-solver>=1.11.0
BUILDLINK_PKGSRCDIR.ceres-solver?=	../../uwm-pkgsrc-wip/ceres-solver

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../math/eigen3/buildlink3.mk"
#.include "../../devel/google-glog/buildlink3.mk"
#.include "../../wip/gflags/buildlink3.mk"
#.include "../../wip/suitesparse/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.endif	# CERES_SOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ceres-solver

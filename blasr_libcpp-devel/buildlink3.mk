# $NetBSD$

BUILDLINK_TREE+=	blasr_libcpp

.if !defined(BLASR_LIBCPP_BUILDLINK3_MK)
BLASR_LIBCPP_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.blasr_libcpp?=	build

BUILDLINK_API_DEPENDS.blasr_libcpp+=	blasr_libcpp>=2016.09.07
BUILDLINK_PKGSRCDIR.blasr_libcpp?=	../../uwm-pkgsrc-wip/blasr_libcpp-devel

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/hdf5/buildlink3.mk"
#.include "../../uwm-pkgsrc-wip/hdf5-c++/buildlink3.mk"
.endif	# BLASR_LIBCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-blasr_libcpp

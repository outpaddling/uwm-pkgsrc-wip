# $NetBSD$

BUILDLINK_TREE+=	py27-h5py

.if !defined(PY27_H5PY_BUILDLINK3_MK)
PY27_H5PY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-h5py+=	py27-h5py>=2.4.0
BUILDLINK_PKGSRCDIR.py27-h5py?=	../../jb-wip/py-h5py

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/py-cython/buildlink3.mk"
#.include "../../devel/hdf5/buildlink3.mk"
#.include "../../math/py-numpy/buildlink3.mk"
.endif	# PY27_H5PY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-h5py

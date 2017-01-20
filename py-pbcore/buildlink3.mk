# $NetBSD$

BUILDLINK_TREE+=	py27-pbcore

.if !defined(PY27_PBCORE_BUILDLINK3_MK)
PY27_PBCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-pbcore+=	py27-pbcore>=0.9.1
BUILDLINK_PKGSRCDIR.py27-pbcore?=	../../jb-wip/py-pbcore

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../jb-wip/py-h5py/buildlink3.mk"
.include "../../jb-wip/py-pysam/buildlink3.mk"
.endif	# PY27_PBCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-pbcore

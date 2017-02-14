# $NetBSD$

BUILDLINK_TREE+=	py27-pypeflow

.if !defined(PY27_PYPEFLOW_BUILDLINK3_MK)
PY27_PYPEFLOW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-pypeflow+=	py27-pypeflow>=2015.08.17
BUILDLINK_PKGSRCDIR.py27-pypeflow?=	../../uwm-pkgsrc-wip/py-pypeflow
.endif	# PY27_PYPEFLOW_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-pypeflow

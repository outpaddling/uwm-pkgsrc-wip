# $NetBSD$

BUILDLINK_TREE+=	py27-pbfalcon

.if !defined(PY27_PBFALCON_BUILDLINK3_MK)
PY27_PBFALCON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-pbfalcon+=	py27-pbfalcon>=2015.08.17
BUILDLINK_PKGSRCDIR.py27-pbfalcon?=	../../uwm-pkgsrc-wip/py-pbfalcon
.endif	# PY27_PBFALCON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-pbfalcon

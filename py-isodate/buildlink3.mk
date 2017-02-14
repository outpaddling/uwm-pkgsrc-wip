# $NetBSD$

BUILDLINK_TREE+=	py27-isodate

.if !defined(PY27_ISODATE_BUILDLINK3_MK)
PY27_ISODATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-isodate+=	py27-isodate>=0.5.0
BUILDLINK_PKGSRCDIR.py27-isodate?=	../../uwm-pkgsrc-wip/py-isodate
.endif	# PY27_ISODATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-isodate

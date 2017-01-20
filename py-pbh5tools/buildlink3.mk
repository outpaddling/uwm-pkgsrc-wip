# $NetBSD$

BUILDLINK_TREE+=	py27-pbh5tools

.if !defined(PY27_PBH5TOOLS_BUILDLINK3_MK)
PY27_PBH5TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-pbh5tools+=	py27-pbh5tools>=2.3.0p4
BUILDLINK_PKGSRCDIR.py27-pbh5tools?=	../../jb-wip/py-pbh5tools

.include "../../math/py-numpy/buildlink3.mk"
.include "../../jb-wip/py-avro/buildlink3.mk"
.include "../../jb-wip/py-pbcore/buildlink3.mk"
.endif	# PY27_PBH5TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-pbh5tools

# $NetBSD$

BUILDLINK_DEPMETHOD.convert-lib?=	build

BUILDLINK_TREE+=	convert-lib

.if !defined(CONVERT_LIB_BUILDLINK3_MK)
CONVERT_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.convert-lib+=	convert-lib>=0.1
BUILDLINK_PKGSRCDIR.convert-lib?=	../../jb-wip/convert-lib
.endif	# CONVERT_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-convert-lib

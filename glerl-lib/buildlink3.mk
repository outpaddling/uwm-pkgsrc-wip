# $NetBSD$
# Packages that only install static libraries or headers should
# include the following line:
BUILDLINK_DEPMETHOD.glerl-lib?=	build

BUILDLINK_TREE+=	glerl-lib

.if !defined(GLERL_LIB_BUILDLINK3_MK)
GLERL_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glerl-lib+=	glerl-lib>=1.0
BUILDLINK_PKGSRCDIR.glerl-lib?=	../../uwm-pkgsrc-wip/glerl-lib
.endif	# GLERL_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-glerl-lib

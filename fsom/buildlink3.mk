# $NetBSD$
# XXX	BUILDLINK_DEPMETHOD.fsom?=	build

BUILDLINK_TREE+=	fsom

.if !defined(FSOM_BUILDLINK3_MK)
FSOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fsom+=	fsom>=23c8bb0b0a1de866ef05ed2be283f67bca4d2f47
BUILDLINK_PKGSRCDIR.fsom?=	../../uwm-pkgsrc-wip/fsom
.endif	# FSOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-fsom

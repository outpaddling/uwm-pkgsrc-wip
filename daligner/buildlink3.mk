# $NetBSD$

BUILDLINK_TREE+=	daligner

.if !defined(DALIGNER_BUILDLINK3_MK)
DALIGNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.daligner+=	daligner-2015.10.28{,nb*}
BUILDLINK_PKGSRCDIR.daligner?=	../../uwm-pkgsrc-wip/daligner
.endif	# DALIGNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-daligner

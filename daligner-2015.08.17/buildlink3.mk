# $NetBSD$

BUILDLINK_TREE+=	daligner

.if !defined(DALIGNER_BUILDLINK3_MK)
DALIGNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.daligner+=	daligner>=2015.08.17
BUILDLINK_PKGSRCDIR.daligner?=	../../uwm-pkgsrc-wip/daligner-2015.08.17
.endif	# DALIGNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-daligner

# $NetBSD$

BUILDLINK_TREE+=	ddocent

.if !defined(DDOCENT_BUILDLINK3_MK)
DDOCENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ddocent+=	ddocent>=2015.11.30
BUILDLINK_PKGSRCDIR.ddocent?=	../../uwm-pkgsrc-wip/ddocent
.endif	# DDOCENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ddocent

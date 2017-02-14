# $NetBSD$

BUILDLINK_TREE+=	pyfasta

.if !defined(PYFASTA_BUILDLINK3_MK)
PYFASTA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pyfasta+=	pyfasta>=0.5.2
BUILDLINK_PKGSRCDIR.pyfasta?=	../../uwm-pkgsrc-wip/pyfasta
.endif	# PYFASTA_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyfasta

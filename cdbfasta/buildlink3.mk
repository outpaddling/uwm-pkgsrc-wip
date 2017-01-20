# $NetBSD$

BUILDLINK_TREE+=	cdbfasta

.if !defined(CDBFASTA_BUILDLINK3_MK)
CDBFASTA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cdbfasta+=	cdbfasta>=2010.07.22
BUILDLINK_PKGSRCDIR.cdbfasta?=	../../jb-wip/cdbfasta
.endif	# CDBFASTA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cdbfasta

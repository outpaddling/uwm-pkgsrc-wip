# $NetBSD$

BUILDLINK_TREE+=	fastafasta-splitter

.if !defined(FASTAFASTA_SPLITTER_BUILDLINK3_MK)
FASTAFASTA_SPLITTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fastafasta-splitter+=	fastafasta-splitter>=0.2.4
BUILDLINK_PKGSRCDIR.fastafasta-splitter?=	../../uwm-pkgsrc-wip/p5-fasta-splitter
.endif	# FASTAFASTA_SPLITTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-fastafasta-splitter

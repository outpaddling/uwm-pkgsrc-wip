# $NetBSD$

BUILDLINK_TREE+=	samtools

.if !defined(SAMTOOLS_BUILDLINK3_MK)
SAMTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.samtools+=	samtools>=1.2
BUILDLINK_PKGSRCDIR.samtools?=	../../jb-wip/samtools

.include "../../wip/htslib/buildlink3.mk"
.endif	# SAMTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-samtools

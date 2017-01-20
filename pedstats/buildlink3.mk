# $NetBSD$

BUILDLINK_TREE+=	pedstats

.if !defined(PEDSTATS_BUILDLINK3_MK)
PEDSTATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pedstats+=	pedstats>=0.6.12
BUILDLINK_PKGSRCDIR.pedstats?=	../../jb-wip/pedstats
.endif	# PEDSTATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pedstats

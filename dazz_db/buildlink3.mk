# $NetBSD$

BUILDLINK_TREE+=	dazz_db

.if !defined(DAZZ_DB_BUILDLINK3_MK)
DAZZ_DB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dazz_db+=	dazz_db>=2015.08.17
BUILDLINK_PKGSRCDIR.dazz_db?=	../../jb-wip/dazz_db
.endif	# DAZZ_DB_BUILDLINK3_MK

BUILDLINK_TREE+=	-dazz_db

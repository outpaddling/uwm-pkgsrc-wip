# $NetBSD$

BUILDLINK_TREE+=	monitor-core

.if !defined(MONITOR_CORE_BUILDLINK3_MK)
MONITOR_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.monitor-core+=	monitor-core>=3.7.2
BUILDLINK_PKGSRCDIR.monitor-core?=	../../uwm-pkgsrc-wip/ganglia-monitor-core

.endif	# MONITOR_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-monitor-core

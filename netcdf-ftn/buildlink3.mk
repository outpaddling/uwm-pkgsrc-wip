# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:24 joerg Exp $

BUILDLINK_TREE+=	netcdf-ftn

.if !defined(NETCDF_BUILDLINK3_MK)
NETCDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netcdf-ftn+=	netcdf-ftn>=4.1.3
BUILDLINK_ABI_DEPENDS.netcdf-ftn+=	netcdf-ftn>=4.1.3
BUILDLINK_PKGSRCDIR.netcdf-ftn?=	../../jb-wip/netcdf-ftn
.endif # NETCDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-netcdf-ftn

# $NetBSD$

BUILDLINK_TREE+=	smithwaterman

.if !defined(SMITHWATERMAN_BUILDLINK3_MK)
SMITHWATERMAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.smithwaterman+=	smithwaterman>=8e667291798b785d698f0875e58da2710d740567
BUILDLINK_PKGSRCDIR.smithwaterman?=	../../uwm-pkgsrc-wip/smithwaterman
.endif	# SMITHWATERMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-smithwaterman

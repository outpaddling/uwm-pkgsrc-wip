# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.papp?=	build

BUILDLINK_TREE+=	papp

.if !defined(PAPP_BUILDLINK3_MK)
PAPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.papp+=	papp>=0.3.2
BUILDLINK_PKGSRCDIR.papp?=	../../uwm-pkgsrc-wip/papp
.endif	# PAPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-papp

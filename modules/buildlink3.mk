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
# XXX	BUILDLINK_DEPMETHOD.modules?=	build

BUILDLINK_TREE+=	modules

.if !defined(MODULES_BUILDLINK3_MK)
MODULES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.modules+=	modules>=3.2.10
BUILDLINK_PKGSRCDIR.modules?=	../../jb-wip/modules
.endif	# MODULES_BUILDLINK3_MK

BUILDLINK_TREE+=	-modules

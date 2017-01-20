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
# XXX	BUILDLINK_DEPMETHOD.ea-utils?=	build

BUILDLINK_TREE+=	ea-utils

.if !defined(EA_UTILS_BUILDLINK3_MK)
EA_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ea-utils+=	ea-utils>=1.1.2
BUILDLINK_PKGSRCDIR.ea-utils?=	../../jb-wip/ea-utils
.endif	# EA_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ea-utils

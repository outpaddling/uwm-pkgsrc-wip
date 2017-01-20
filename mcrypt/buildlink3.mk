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
# XXX	BUILDLINK_DEPMETHOD.mcrypt?=	build

BUILDLINK_TREE+=	mcrypt

.if !defined(MCRYPT_BUILDLINK3_MK)
MCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mcrypt+=	mcrypt>=2.6.8nb2
BUILDLINK_PKGSRCDIR.mcrypt?=	../../jb-wip/mcrypt

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../security/libmcrypt/buildlink3.mk"
#.include "../../security/mhash/buildlink3.mk"
.endif	# MCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mcrypt

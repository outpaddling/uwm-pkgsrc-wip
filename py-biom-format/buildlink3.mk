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
# XXX	BUILDLINK_DEPMETHOD.biom?=	build

BUILDLINK_TREE+=	biom

.if !defined(BIOM_BUILDLINK3_MK)
BIOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biom+=	biom>=2.1
BUILDLINK_PKGSRCDIR.biom?=	../../uwm-pkgsrc-wip/py-biom-format
.endif	# BIOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-biom

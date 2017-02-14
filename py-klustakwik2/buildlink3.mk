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
# XXX	BUILDLINK_DEPMETHOD.klustakwik2?=	build

BUILDLINK_TREE+=	klustakwik2

.if !defined(KLUSTAKWIK2_BUILDLINK3_MK)
KLUSTAKWIK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.klustakwik2+=	klustakwik2>=0.2.4
BUILDLINK_PKGSRCDIR.klustakwik2?=	../../uwm-pkgsrc-wip/py-klustakwik2
.endif	# KLUSTAKWIK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-klustakwik2

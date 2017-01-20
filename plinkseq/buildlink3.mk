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
# XXX	BUILDLINK_DEPMETHOD.plinkseq?=	build

BUILDLINK_TREE+=	plinkseq

.if !defined(PLINKSEQ_BUILDLINK3_MK)
PLINKSEQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plinkseq+=	plinkseq>=0.10
BUILDLINK_PKGSRCDIR.plinkseq?=	../../jb-wip/plinkseq
.endif	# PLINKSEQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-plinkseq

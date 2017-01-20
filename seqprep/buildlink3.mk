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
# XXX	BUILDLINK_DEPMETHOD.seqprep?=	build

BUILDLINK_TREE+=	seqprep

.if !defined(SEQPREP_BUILDLINK3_MK)
SEQPREP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.seqprep+=	seqprep>=1.1
BUILDLINK_PKGSRCDIR.seqprep?=	../../jb-wip/seqprep
.endif	# SEQPREP_BUILDLINK3_MK

BUILDLINK_TREE+=	-seqprep

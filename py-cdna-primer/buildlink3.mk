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
# XXX	BUILDLINK_DEPMETHOD.py27-cDNA_primer?=	build

BUILDLINK_TREE+=	py27-cDNA_primer

.if !defined(PY27_CDNA_PRIMER_BUILDLINK3_MK)
PY27_CDNA_PRIMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-cDNA_primer+=	py27-cDNA_primer>=2015.08.17
BUILDLINK_PKGSRCDIR.py27-cDNA_primer?=	../../uwm-pkgsrc-wip/py-cdna-primer

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/py-cython/buildlink3.mk"
#.include "../../uwm-pkgsrc-wip/py-pbh5tools/buildlink3.mk"
#.include "../../uwm-pkgsrc-wip/blasr/buildlink3.mk"
#.include "../../math/py-numpy/buildlink3.mk"
.endif	# PY27_CDNA_PRIMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-cDNA_primer

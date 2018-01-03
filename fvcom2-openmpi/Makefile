# $NetBSD$
#

PKGNAME=	fvcom-openmpi-2.7.1
DISTNAME=	sourcecode1
CATEGORIES=	science
MASTER_SITES=	http://fvcom.smast.umassd.edu/FVCOM/password_required/t2/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://fvcom.smast.umassd.edu/FVCOM/password_required/t2/
COMMENT=	Prognostic coastal ocean circulation model
#LICENSE=	fvcom-license

WRKSRC=		${WRKDIR}/FVCOM2.7.1/FVCOM_source

USE_TOOLS+=	make
USE_LANGUAGES=	c fortran77
FC=		mpif77
MAKE_ENV+=	OPT=-I${MPI_PREFIX}/lib

# Use bundled metis
# DEPENDS+=	metis>=4.0:../../math/metis

AUTO_MKDIRS=	yes

FETCH_MESSAGE=  "Please download the files"
FETCH_MESSAGE+= "    "${DISTFILES:Q}
FETCH_MESSAGE+= "manually from "${MASTER_SITES:Q}"."

SUBST_CLASSES+=		log2
SUBST_FILES.log2=	METIS_source/coarsen.c \
			METIS_source/kmetis.c \
			METIS_source/kvmetis.c \
			METIS_source/metis_source.c \
			METIS_source/mkmetis.c \
			METIS_source/proto.h \
			METIS_source/rename.h \
			METIS_source/util.c
SUBST_STAGE.log2=	post-patch
SUBST_MESSAGE.log2=	Fixing log2 conflict
SUBST_SED.log2=		-e 's|log2|metis_log2|g'

pre-patch:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	${MV} ${WRKDIR}/FVCOM2.7.1/METIS_source ${WRKSRC}

# FIXME: Should not have to copy mpi.mod to WRKSRC.
# -I${MPI_PREFIX}/lib should cover  this.
pre-build:
	(cd ${WRKSRC}/METIS_source && make)
	${CP} ${MPI_PREFIX}/lib/mpi.mod ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fvcom ${DESTDIR}${PREFIX}/bin

# Current netcdf package missing mod file
# No netcdf support until this is resolved
#.include "../../devel/netcdf/buildlink3.mk"
.include "../../uwm-pkgsrc-wip/openmpi-prefixed/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

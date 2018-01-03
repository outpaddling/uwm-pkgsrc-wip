# $NetBSD$
#

DISTNAME=	trilinos-10.10.2-Source
CATEGORIES=	science
# Requires registration
MASTER_SITES=	http://trilinos.sandia.gov/download/trilinos-10.10.html/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://trilinos.sandia.gov/index.html
COMMENT=	Object-oriented math libraries
#LICENSE=	# lgpl and bsd, working toward bsd for all

FETCH_MESSAGE=  "Please download the files"
FETCH_MESSAGE+= "    "${DISTFILES:Q}
FETCH_MESSAGE+= "manually from "${MASTER_SITES:Q}"."

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++ fortran

CMAKE_SOURCE_PATH=      ${WRKDIR}/${DISTNAME}
WRKSRC=         ${WRKDIR}/trilinos-build

# /usr/bin/ld can't find libgcc for non-base compiler
LD=		${CC}

CMAKE_ARGS+= \
        -D CMAKE_BUILD_TYPE=DEBUG \
        -D Trilinos_ENABLE_ALL_PACKAGES:BOOL=ON \
        -D TPL_ENABLE_MPI:BOOL=OFF \
	-D BLAS_LIBRARY_DIRS:PATH=${LOCALBASE}/lib \
	-D LAPACK_LIBRARY_DIRS:PATH=${LOCALBASE}/lib

#        -D MPI_BASE_DIR:PATH=${LOCALBASE}/mpi/openmpi

# Make this unnecessary by updating cmake.mk to allow 
# CMAKE_INSTALL_PREFIX override
SUBST_CLASSES+=	prefix
SUBST_FILES.prefix=	CMakeCache.txt
SUBST_STAGE.prefix=	post-configure
SUBST_SED.prefix=	-e "s|CMAKE_INSTALL_PREFIX:PATH=${PREFIX}|CMAKE_INSTALL_PREFIX:PATH=${PREFIX}/trilinos|g"

pre-configure:
	${MKDIR} -p ${WRKSRC}

do-configure:
	cd ${WRKSRC} && ${CMAKE} ${CMAKE_ARGS} ${CMAKE_SOURCE_PATH}

# TODO: determine other dependencies
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

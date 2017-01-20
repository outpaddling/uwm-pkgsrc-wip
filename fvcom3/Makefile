# $NetBSD$
#

PKGNAME=	fvcom-${VERSION}
DISTNAME=	sourcecode
CATEGORIES=	math
MASTER_SITES=	http://fvcom.smast.umassd.edu/FVCOM/password_required/t2/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://fvcom.smast.umassd.edu/FVCOM/password_required/t2/
COMMENT=	Prognostic coastal ocean circulation model
#LICENSE=	fvcom-license

WRKSRC=		${WRKDIR}/FVCOM${VERSION}/FVCOM_source

USE_TOOLS+=	gmake
# Code is actually Fortran77, even though the build system generates .f90 files
USE_LANGUAGES=	c fortran77

# Use bundled metis
# DEPENDS+=	metis>=4.0:../../math/metis

AUTO_MKDIRS=	yes

FETCH_MESSAGE=  "Please download the files"
FETCH_MESSAGE+= "    "${DISTFILES:Q}
FETCH_MESSAGE+= "manually from "${MASTER_SITES:Q}"."

SUBST_CLASSES+=		log2
SUBST_FILES.log2=	../METIS_source/kmetis.c \
			../METIS_source/kvmetis.c \
			../METIS_source/metis_source.c \
			../METIS_source/mkmetis.c \
			../METIS_source/proto.h \
			../METIS_source/rename.h \
			../METIS_source/util.c
SUBST_STAGE.log2=	post-patch
SUBST_MESSAGE.log2=	Fixing log2 conflict
SUBST_SED.log2=		-e 's|log2|metis_log2|g'

SUBST_CLASSES+=		metis-gcc
SUBST_FILES.metis-gcc=	../METIS_SOURCE/makefile
SUBST_STAGE.metis-gcc=	post-patch
SUBST_SED.metis-gcc=	-e 's|CC = icc|CC = gcc|g'

VERSION=		3.1.6

pre-patch:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	#${MV} ${WRKDIR}/FVCOM${VERSION}/METIS_source ${WRKSRC}

pre-build:
	(cd ${WRKDIR}/FVCOM${VERSION}/METIS_source && make)
	cp ${FILESDIR}/make.inc-openmpi ${WRKSRC}/make.inc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fvcom ${DESTDIR}${PREFIX}/bin

# Current netcdf package missing mod file
# No netcdf support until this is resolved
#.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

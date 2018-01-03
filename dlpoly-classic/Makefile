# $NetBSD$
#

DISTNAME=	dl_class_1.8
PKGNAME=	dlpoly-classic-1.8
CATEGORIES=	science parallel
MASTER_SITES=	http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/
COMMENT=	General purpose classical molecular dynamics
LICENSE=	original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c fortran
USE_TOOLS+=	gmake

# Force use of gfortran installation outside pkgsrc
# Toolchain wrappers handle this fine where gfortran doesn't actually exist
FC=		gfortran

BUILD_WRKSRC=	${WRKSRC}/source

AUTO_MKDIRS=	yes

do-build:
	(cd ${BUILD_WRKSRC} && \
	        ${CP} -f ${WRKSRC}/build/MakeSEQ Makefile && \
		${MAKE} ${FC})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic \
		${DESTDIR}${PREFIX}/bin

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"

# $NetBSD$
#

DISTNAME=	dl_poly_4.03
PKGNAME=	dlpoly-4.03
CATEGORIES=	math parallel
MASTER_SITES=	http://www.stfc.ac.uk/CSE/randd/ccg/software/DL_POLY/25526.aspx
DISTFILES=	decrypt.c.gz \
		dl_poly_4.03.tar.gE

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://www.stfc.ac.uk/CSE/randd/ccg/software/DL_POLY/25526.aspx
COMMENT=	General purpose classical molecular dynamics
#LICENSE=	dlpoly-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c fortran
USE_TOOLS+=	gmake

# Force use of gfortran installation outside pkgsrc
# Toolchain wrappers handle this fine where gfortran doesn't actually exist
FC=		gfortran

BUILD_WRKSRC=	${WRKSRC}/source

AUTO_MKDIRS=	yes

do-extract:
	WRKDIR=${WRKDIR} DISTDIR=${DISTDIR} ${FILESDIR}/extract

do-build:
	(cd ${BUILD_WRKSRC} && \
	        ${CP} -f ${WRKSRC}/build/Makefile_SRL1 Makefile && \
		${MAKE} ${FC})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic \
		${DESTDIR}${PREFIX}/bin

# url2pkg-marker (please do not remove this line.)

# Temporary hack to use openmpi from outside pkgsrc
# Link fails with non-pkgsrc openmpi on RHEL
# mpif77 cannot find -lmpi_f77
#.include "../../mk/bsd.prefs.mk"
#.if ${OPSYS} != "Linux"
.include "../../parallel/openmpi-prefixed/buildlink3.mk"
#.endif
.include "../../mk/bsd.pkg.mk"

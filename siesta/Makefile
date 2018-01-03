# $NetBSD$

DISTNAME=	siesta-3.2-pl-4
CATEGORIES=	science
MASTER_SITES=	http://departments.icmab.es/leem/siesta/CodeAccess/Code/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://departments.icmab.es/leem/siesta/CodeAccess/Code/
COMMENT=	Electronic structure calculations and ab initio molecular dynamics
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	fortran c
USE_TOOLS=	gmake

FETCH_MESSAGE=  "Please download the files"
FETCH_MESSAGE+= "    "${DISTFILES:Q}
FETCH_MESSAGE+= "manually from "${MASTER_SITES:Q}"."

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--srcdir=../Src

FCFLAGS+=	-DGRID_DP -DPHI_GRID_SP

WRKSRC=		${WRKDIR}/${DISTNAME}/Obj

MAKE_ENV+=	TARGET=""

INSTALLATION_DIRS=	bin

pre-configure:
	(cd ${WRKSRC} && sh ../Src/obj_setup.sh && ${CP} ../Src/configure .)

do-build:
	(cd ${WRKSRC} && ${GMAKE} siesta)
	(cd ${WRKSRC} && ${MV} siesta siesta.save)
	(cd ${WRKSRC} && ${GMAKE} clean transiesta)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/siesta.save ${DESTDIR}${PREFIX}/bin/siesta
	${INSTALL_PROGRAM} ${WRKSRC}/transiesta ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
.include "../../math/lapack/buildlink3.mk"

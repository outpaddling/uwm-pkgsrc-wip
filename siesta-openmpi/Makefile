# $NetBSD$

DISTNAME=	siesta-3.2-pl-4
CATEGORIES=	science
MASTER_SITES=	http://departments.icmab.es/leem/siesta/CodeAccess/Code/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://departments.icmab.es/leem/siesta/CodeAccess/Code/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	fortran c
USE_TOOLS=	gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--srcdir=../Src

FCFLAGS+=	-DGRID_DP -DPHI_GRID_SP

WRKSRC=		${WRKDIR}/${DISTNAME}/Obj

MAKE_ENV+=	TARGET=""

pre-configure:
	(cd ${WRKSRC} && sh ../Src/obj_setup.sh && ${CP} ../Src/configure .)

do-build:
	(cd ${WRKSRC} && ${GMAKE} siesta)
	(cd ${WRKSRC} && ${MV} siesta siesta.save)
	(cd ${WRKSRC} && ${GMAKE} clean transiesta)

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/siesta.save ${DESTDIR}${PREFIX}/bin/siesta
	${INSTALL_PROGRAM} ${WRKSRC}/transiesta ${DESTDIR}${PREFIX}/bin

.include "../../math/lapack/buildlink3.mk"
.include "../../wip/openmpi163/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

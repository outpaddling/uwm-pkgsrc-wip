# $NetBSD$
#

DISTNAME=	scotch_5.1.12b_esmumps
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/28978/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://gforge.inria.fr/frs/download.php/28978/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/scotch_5.1.12_esmumps
USE_LANGUAGES=	c fortran
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${DISTNAME:C/b_/_/}

BUILD_TARGET=	scotch

CFLAGS+=	-I${LOCALBASE}/include

do-build:
	(cd ${WRKSRC}/src && ${MAKE})

.include "../../mk/bsd.pkg.mk"

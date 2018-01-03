# $NetBSD$
#

DISTNAME=	epc-0.1
CATEGORIES=	emulators
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c

EXTRACT_SUFX=	.tar.xz

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

MAKE_FLAGS+=	"CFLAGS=-Wall -O2"

pre-build:
	(cd ${WRKSRC} && make depend)

.include "../../wip/twintk/buildlink3.mk"
.include "../../wip/libbacon/buildlink3.mk"
.include "../../uwm-pkgsrc-wip/plasm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$
#

DISTNAME=	plasm-0.1
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	PortabLe ASseMbler
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c c++

CFLAGS+=	-Wall -g

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

pre-build:
	(cd ${WRKSRC} && ${MAKE} depend)

.include "../../uwm-pkgsrc-wip/papp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

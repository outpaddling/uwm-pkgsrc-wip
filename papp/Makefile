# $NetBSD$
#

DISTNAME=	papp-0.3.2
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c++

EXTRACT_SUFX=	.tar.xz

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX} \
			STAGEDIR=${DESTDIR}

do-configure:
	printenv

.include "../../mk/bsd.pkg.mk"

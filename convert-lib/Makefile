# $NetBSD$
#

DISTNAME=	convert-lib-0.1
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Convert between static and dynamic libraries
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=	yes

# Not working
#AUTO_MKDIRS=	yes

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/convert-lib ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

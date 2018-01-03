# $NetBSD$
#

DISTNAME=	KlustaKwik-2.0.1
CATEGORIES=	science
MASTER_SITES=	http://downloads.sourceforge.net/project/klustakwik/klustakwik/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://downloads.sourceforge.net/project/klustakwik/klustakwik/
COMMENT=	Unsupervised classification of multidimensional continuous data
LICENSE=	gnu-gpl-v1

USE_LANGUAGES=	c c++

do-build:
	(cd ${WRKSRC} && ${MAKE})

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/KlustaKwik ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

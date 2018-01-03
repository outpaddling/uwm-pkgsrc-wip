# $NetBSD$
#

DISTNAME=	klustakwik-${PORTVERSION}
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_GITHUB:=klusta-team/}
PORTVERSION=	0.3.0.rc3

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://downloads.sourceforge.net/project/klustakwik/klustakwik/
COMMENT=	Unsupervised classification of multidimensional continuous data
LICENSE=	gnu-gpl-v1

MAKE_FILE=	makefile

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

do-build:
	(cd ${WRKSRC} && ${MAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KlustaKwik ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

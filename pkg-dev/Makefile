# $NetBSD$
#

DISTNAME=	pkg-dev-0.1
CATEGORIES=	pkg-tools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	# none

DEPENDS=	url2pkg:../../pkgtools/url2pkg \
		pkglint:../../pkgtools/pkglint \
		pkgdiff:../../pkgtools/pkgdiff \
		createbuildlink:../../pkgtools/createbuildlink \
		fbsd2pkg:../../uwm-pkgsrc-wip/fbsd2pkg

NO_BUILD=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_SED.prefix=	-e 's|/usr/pkgsrc|${WRKDIR}/../../..|g'
SUBST_FILES.prefix=	Scripts/*

post-patch:
	echo ${SRCPREFIX}

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"

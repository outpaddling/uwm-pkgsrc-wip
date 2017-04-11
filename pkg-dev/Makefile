# $NetBSD$
#

DISTNAME=	pkg-dev-0.1
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Tools for pkgsrc development and testing
LICENSE=	original-bsd

EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	# none

DEPENDS=	url2pkg>0:../../pkgtools/url2pkg \
		pkglint>0:../../pkgtools/pkglint \
		pkgdiff>0:../../pkgtools/pkgdiff \
		createbuildlink>0:../../pkgtools/createbuildlink \
		fbsd2pkg>0:../../uwm-pkgsrc-wip/fbsd2pkg

NO_BUILD=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_SED.prefix=	-e 's|/usr/pkgsrc|${BUILD_DIR}/../..|g'
SUBST_FILES.prefix=	Scripts/pkg-grep

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"

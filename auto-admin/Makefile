# $NetBSD$
#

DISTNAME=	auto-admin-0.4.0
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Automate common systems administration tasks
#LICENSE=	original-bsd
EXTRACT_SUFX=	.tar.xz

LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes
REPLACE_SH=	*/Scripts/*

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	${WRKSRC}/Common/Scripts/auto-denyhosts-remove-ip
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|g"

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	post-patch
SUBST_FILES.pkgsrc=	${WRKSRC}/Common/Scripts/auto-clean-pkgsrc
SUBST_SED.pkgsrc=	-e "s|/usr/pkgsrc|${BUILD_DIR}/../..|g"

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Common/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
#	ls ${WRKSRC}/${OPSYS}/Scripts
# This does not work
#.if exists(${WRKSRC}/${OPSYS}/Scripts)
# This does not work
#.if exists(/usr/pkgsrc/wip/auto-admin/work/auto-admin-0.4.0)
# This works
# .if exists(/usr/pkgsrc/wip/auto-admin/work)
# This works after mkdir /etc/auto-admin-0.4.0
# .if exists(/etc/auto-admin-0.4.0)
# Temporary hack
.if ${OPSYS} == NetBSD
	${INSTALL_SCRIPT} ${WRKSRC}/${OPSYS}/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
.endif
.if exists(/etc/redhat-release)
	${INSTALL_SCRIPT} ${WRKSRC}/CentOS/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
.endif

.include "../../mk/bsd.pkg.mk"

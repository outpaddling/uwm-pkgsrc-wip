# $NetBSD$

DISTNAME=	auto-admin-0.4.10
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://outpaddling.mooo.com/~bacon/Acadix/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/
COMMENT=	Automate common systems administration tasks
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Common/Scripts/* ${DESTDIR}${PREFIX}/sbin
	if ${TEST} -d ${WRKSRC}/${OPSYS}/Scripts; then \
		${INSTALL_SCRIPT} ${WRKSRC}/${OPSYS}/Scripts/* \
			${DESTDIR}${PREFIX}/sbin; \
	fi

.include "../../mk/bsd.pkg.mk"

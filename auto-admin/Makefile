# $NetBSD$

DISTNAME=	auto-admin-0.4.8
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://outpaddling.mooo.com/~bacon/Acadix/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz
COMMENT=	Automate common systems administration tasks
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	sbin
PLIST_VARS+=	redhat

.include "../../mk/bsd.prefs.mk"

SCRIPTS=	${WRKSRC}/Common/Scripts/*
.if exists(/etc/redhat-release)
PLIST.redhat=	yes
SCRIPTS+=	${WRKSRC}/CentOS/Scripts/*
.elif exists(${WRKSRC}/${OPSYS}/Scripts)
SCRIPTS+=	${WRKSRC}/${OPSYS}/Scripts/*
.endif

do-install:
	${INSTALL_SCRIPT} ${SCRIPTS} ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"

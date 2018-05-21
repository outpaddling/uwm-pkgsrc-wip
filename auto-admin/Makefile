# $NetBSD$

DISTNAME=	auto-admin-0.4.3
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Automate common systems administration tasks
LICENSE=	2-clause-bsd
EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	# none

NO_BUILD=	yes
REPLACE_SH=	*/Scripts/*

INSTALLATION_DIRS=	sbin

.include "../../mk/bsd.prefs.mk"

SCRIPTS=	${WRKSRC}/Common/Scripts/*
.if ${OS_VARIANT} == "redhat"
PLIST.redhat=	yes
SCRIPTS+=	${WRKSRC}/CentOS/Scripts/*
.else
SCRIPTS+=	${WRKSRC}/${OPSYS}/Scripts/*
.endif

do-install:
	${INSTALL_SCRIPT} ${SCRIPTS} ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"

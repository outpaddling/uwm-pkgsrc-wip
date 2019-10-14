# $NetBSD: Makefile,v 1.4 2014/01/15 02:33:47 outpaddling Exp $
#

DISTNAME=	twintk-0.9.4
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://outpaddling.mooo.com/~bacon/Acadix/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

EXTRACT_SUFX=	.tar.xz

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-patch:
	${MV} ${WRKSRC}/terminfo/M ${WRKSRC}/terminfo/m
	${MV} ${WRKSRC}/terminfo/N ${WRKSRC}/terminfo/n
	${MV} ${WRKSRC}/terminfo/P ${WRKSRC}/terminfo/p
	${MV} ${WRKSRC}/terminfo/Q ${WRKSRC}/terminfo/q
	${MV} ${WRKSRC}/terminfo/T ${WRKSRC}/terminfo/t
	${MV} ${WRKSRC}/terminfo/X ${WRKSRC}/terminfo/x
.endif

.include "../../uwm-pkgsrc-wip/libbacon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.7 2014/04/03 01:21:22 outpaddling Exp $

DISTNAME=	ape-3.5.3
CATEGORIES=	editors
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Another Programmer's Editor
LICENSE=	2-clause-bsd

MAKE_ENV+=	STAGEDIR=${DESTDIR}

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${PREFIX} depend

.include "../../uwm-pkgsrc-wip/libpare/buildlink3.mk"
.include "../../uwm-pkgsrc-wip/libbacon/buildlink3.mk"
.include "../../uwm-pkgsrc-wip/twintk/buildlink3.mk"
.include "../../uwm-pkgsrc-wip/webbrowser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

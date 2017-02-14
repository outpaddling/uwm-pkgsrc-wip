# $NetBSD: Makefile,v 1.4 2014/01/15 02:33:47 outpaddling Exp $
#

DISTNAME=	twintk-0.9.4
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

EXTRACT_SUFX=	.tar.xz

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../uwm-pkgsrc-wip/libbacon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

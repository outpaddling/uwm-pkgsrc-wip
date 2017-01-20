# $NetBSD$
#

DISTNAME=	xml-format-0.2
CATEGORIES=	textproc
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	XML Beautifier
#LICENSE=	# TODO: (see mk/license.mk)

# No destdir here!  Sets path compiled into code.
MAKE_ENV+=	DATADIR=${PREFIX}/share/xml-format
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			DATADIR=${DESTDIR}${PREFIX}/share/xml-format

.include "../../wip/libbacon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

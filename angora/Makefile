# $NetBSD$
#

DISTNAME=	angora-0.18.5
CATEGORIES=	math
MASTER_SITES=	http://angorafdtd.org/angora/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://angorafdtd.org/angora/
COMMENT=	FDTD simulator
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake

DEPENDS+=	blitz++:../../math/blitz++
BUILD_DEPENDS+=	hdf5-c++:../../devel/hdf5-c++

.include "../../mk/bsd.prefs.mk"

#CXXFLAGS+=	-I/Users/bacon/Pkgsrc/pkg-1/include
#LDFLAGS+=	-L${LOCALBASE}/lib -largp

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/argp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	openvex-0.5.3
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/openvex.php
COMMENT=	Open firmware for Vex robotics controllers

BUILD_DEPENDS=	sdcc:../../devel/sdcc \
		gputils:../../devel/gputils
RUN_DEPENDS=	vexctl:../../devel/roboctl \
		sdcc:../../devel/sdcc \
		gpasm:../../devel/gputils

# MAKE_ENV	+= PIC_LIB=pic18f8520.lib

# USE_TOOLS+=	gsed

SUBST_CLASSES+=	prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	openvex-new-project \
			Doc/openvex.man
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|g"

.include "../../uwm-pkgsrc-wip/roboctl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

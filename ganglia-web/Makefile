# $NetBSD: Makefile,v 1.2 2015/04/03 17:39:25 outpaddling Exp $

DISTNAME=	ganglia-web-${PORTVERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ganglia/}

MAINTAINER=	bacon@NetBSD.org

COMMENT=	Ganglia network monitor web interface
LICENSE=	original-bsd

# Are pcre, xml, etc. included with the base php5?
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.1:../../www/ap-php
DEPENDS+=	monitor-core-3.7.2{,nb*}:../../uwm-pkgsrc-wip/ganglia-monitor-core
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.0:../../graphics/php-gd

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	post-patch
SUBST_FILES.makefile=	${WRKSRC}/Makefile
SUBST_SED.makefile=	-e 's|/usr/share/ganglia-webfrontend|${PREFIX}/${WEBDIR}|g'
SUBST_SED.makefile+=	-e 's|/etc|${PREFIX}/etc|g'
SUBST_SED.makefile+=	-e 's|www-data|${APACHE_USER}|g'
SUBST_SED.makefile+=	-e 's|/var/lib/ganglia|${PREFIX}/var/lib/ganglia|g'

SUBST_CLASSES+=		conf_php
SUBST_STAGE.conf_php=	post-patch
SUBST_FILES.conf_php=	${WRKSRC}/conf_default.php
SUBST_SED.conf_php=	-e 's|/usr/bin/rrdtool|${PREFIX}/bin/rrdtool|g'

#		-e 's|/var/lib/ganglia|/var/db/ganglia|g'

BUILD_DEFS+=	APACHE_USER

WEBDIR=		share/httpd/htdocs/ganglia
PORTVERSION=	3.7.3

.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"

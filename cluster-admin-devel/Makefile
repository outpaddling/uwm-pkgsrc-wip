# $NetBSD$

DISTNAME=	cluster-admin-0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	HPC cluster admin tools
LICENSE=	2-clause-bsd

DATADIR=	${PREFIX}/share/cluster-admin

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	post-patch
SUBST_FILES.datadir=	${WRKSRC}/CentOS/Sys-scripts/ganglia-web-setup \
			${WRKSRC}/Common/Sys-scripts/slurm-update-idle-nodes
SUBST_SED.datadir=	-e 's|%%DATADIR%%|${PREFIX}/share/cluster-admin|g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	${WRKSRC}/Common/User-scripts/slurm-shell
SUBST_FILES.prefix+=	${WRKSRC}/Common/Src/cluster-passwd.c
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

DEPENDS+=	auto-admin>=0.4.5:../../uwm-pkgsrc-wip/auto-admin

USE_TOOLS+=	bash

REPLACE_BASH=	Common/Sys-scripts/cluster-adduser

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include "../../mk/bsd.pkg.mk"

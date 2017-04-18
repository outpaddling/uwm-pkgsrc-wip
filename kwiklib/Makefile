# $NetBSD$

PKGNAME=	kwiklib
DISTNAME=	${GHCOMMIT}
GHCOMMIT=	2c249f8c31e913ce8f48f2e3a3b6ac9d9c274a39
CATEGORIES=	science
#MASTER_SITES=	https://github.com/klusta-team/spikedetekt2/archive/
MASTER_SITES=	${MASTER_SITE_GITHUB:=klusta-team/kwiklib/archive/}
PKGNAME=    ${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	dsiercks@uwm.edu
#HOMEPAGE=	https://github.com/klusta-team/spikedetekt2/archive/
COMMENT=	Electrophysiological spike detection for large dense electrode arrays
LICENSE=	gnu-gpl-v1

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/kwiklib-${GHCOMMIT}
#USE_LANGUAGES=	python
REPLACE_PYTHON=	*.py

PYDISTUTILSPKG=	yes

PYSETUP=	setup.py

DEPENDS+=		klustakwik:../../uwm-pkgsrc-wip/klustakwik030

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

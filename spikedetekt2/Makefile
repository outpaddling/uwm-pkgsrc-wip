# $NetBSD$

DISTNAME=	v0.3.0
CATEGORIES=	jb-wip
#MASTER_SITES=	https://github.com/klusta-team/spikedetekt2/archive/
MASTER_SITES=	${MASTER_SITE_GITHUB:=klusta-team/spikedetekt2/archive/}
PKGNAME=    ${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	dsiercks@uwm.edu
#HOMEPAGE=	https://github.com/klusta-team/spikedetekt2/archive/
COMMENT=	Electrophysiological spike detection for large dense electrode arrays
LICENSE=	gnu-gpl-v1

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/spikedetekt2-0.3.0
#USE_LANGUAGES=	python
REPLACE_PYTHON=	*.py

PYDISTUTILSPKG=	yes

PYSETUP=	setup.py

DEPENDS+=		klustakwik:../../jb-wip/klustakwik030

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

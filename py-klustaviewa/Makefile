# $NetBSD$

PKGNAME=	klustaviewa
DISTNAME=	${GHCOMMIT}
GHCOMMIT=	e1c02e8b8cacfd1c0c565d4cbbd5cd7b19b54d45
CATEGORIES=	jb-wip
#MASTER_SITES=	https://github.com/klusta-team/spikedetekt2/archive/
MASTER_SITES=	${MASTER_SITE_GITHUB:=klusta-team/klustaviewa/archive/}
PKGNAME=    ${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	dsiercks@uwm.edu
#HOMEPAGE=	https://github.com/klusta-team/spikedetekt2/archive/
COMMENT=	Electrophysiological spike detection for large dense electrode arrays
LICENSE=	gnu-gpl-v1

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/klustaviewa-${GHCOMMIT}
#USE_LANGUAGES=	python
REPLACE_PYTHON=	*.py

PYDISTUTILSPKG=	yes

PYSETUP=	setup.py

DEPENDS+=		klustakwik:../../jb-wip/klustakwik030
DEPENDS+=		py27-qtools:../../jb-wip/py-qtools

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

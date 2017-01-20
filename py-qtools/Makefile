# $NetBSD$

DISTNAME=	master
CATEGORIES=	jb-wip
MASTER_SITES=	https://github.com/rossant/qtools/archive/
EXTRACT_SUFX=	.zip
#PKGNAME=	qtools
PKGNAME=    ${PYPKGPREFIX}-qtools

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://github.com/rossant/qtools/archive/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/qtools-master
USE_LANGUAGES=	# none


NO_BUILD=	yes

#USE_LANGUAGES=	python
REPLACE_PYTHON=	*.py

#PYDISTUTILSPKG=	yes

PYSETUP=	setup.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

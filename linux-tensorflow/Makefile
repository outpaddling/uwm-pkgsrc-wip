# $NetBSD$

#DISTNAME=	tensorflow_gpu-1.0.0-cp34-cp34m-linux_x86_64
DISTNAME=	tensorflow-1.0.0-cp34-cp34m-linux_x86_64
CATEGORIES=	math
#MASTER_SITES=	https://storage.googleapis.com/tensorflow/linux/gpu/
MASTER_SITES=	https://storage.googleapis.com/tensorflow/linux/cpu/
EXTRACT_SUFX=	.whl

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://storage.googleapis.com/tensorflow/linux/gpu/
COMMENT=	TODO: Short description of the package

LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	34

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	base compat

DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

do-extract:

do-build:

do-install:
	pip3.4 install --no-deps --isolated --ignore-installed \
		--root=${DESTDIR}${PREFIX} ${DISTDIR}/${DISTFILES}

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

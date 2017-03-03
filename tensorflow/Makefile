# $NetBSD$

DISTNAME=	tensorflow_gpu-1.0.0-cp34-cp34m-linux_x86_64
CATEGORIES=	uwm-pkgsrc-wip
MASTER_SITES=	https://storage.googleapis.com/tensorflow/linux/gpu/
EXTRACT_SUFX=	.whl

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://storage.googleapis.com/tensorflow/linux/gpu/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

PYTHON_VERSIONS_INCOMPATIBLE=	27 35 36

do-extract:
	pip3.4 install --no-deps --isolated --ignore-installed --root=${WRKDIR} ${DISTDIR}/${DISTFILES}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	cuda-repo-rhel6-7-5-local-7.5-18.x86_64
CATEGORIES=	uwm-pkgsrc-wip
MASTER_SITES=	http://developer.download.nvidia.com/compute/cuda/7.5/Prod/local_installers/
EXTRACT_SUFX=	.rpm

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://developer.download.nvidia.com/compute/cuda/7.5/Prod/local_installers/
COMMENT=	CUDA GPU drivers and software for RHEL 6
#LICENSE=	# TODO: (see mk/license.mk)

NO_EXTRACT=	yes
NO_BUILD=	yes

do-install:
	yum install ${DISTFILE}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"

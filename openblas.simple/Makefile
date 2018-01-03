# $NetBSD$

DISTNAME=	openblas-${PORTVERSION}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=xianyi/}
GITHUB_PROJECT=	OpenBLAS
GITHUB_TAG=	v${PORTVERSION}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/xianyi/OpenBLAS
COMMENT=	Optimized BLAS library based on GotoBLAS2
# Check this
LICENSE=	modified-bsd

# Test and change if necessary.
# MAKE_JOBS_SAFE=	no

USE_LANGUAGES=	c fortran
USE_TOOLS+=	gmake perl:build

WRKSRC=		${WRKDIR}/OpenBLAS-${PORTVERSION}

CFLAGS=		-fopenmp 
CXXFLAGS=	-fopenmp 
FFLAGS=		-fopenmp 

PORTVERSION=	0.2.20

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1

# .include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

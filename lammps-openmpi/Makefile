# $NetBSD$
#

DISTNAME=	lammps-2012.09.14
PKGNAME=	lammps-openmpi-2012.09.14
CATEGORIES=	science
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Large-scale Atomic/Molecular Massively Parallel Simulator
LICENSE=	gnu-gpl-v1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# CXX=		mpic++

BUILD_TARGET=	pkgsrc-openmpi

WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-patch:
	cp ${FILESDIR}/Makefile.pkgsrc-openmpi ${WRKSRC}/MAKE

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lmp_pkgsrc-openmpi \
		${DESTDIR}${PREFIX}/bin/lmp-openmpi

post-install:
	@${CAT} pkg-message

.include "../../wip/openmpi163/buildlink3.mk"
.include "../../wip/fftw2-openmpi/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

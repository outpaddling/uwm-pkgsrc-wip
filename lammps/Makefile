# $NetBSD$
#

DISTNAME=	lammps-2013.04.04
CATEGORIES=	science
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Large-scale Atomic/Molecular Massively Parallel Simulator
LICENSE=	gnu-gpl-v1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++ fortran
USE_TOOLS+=	gmake

BUILD_TARGET=	pkgsrc-serial

WRKSRC=		${WRKDIR}/lammps-3Apr13
BUILD_WRKSRC=	${WRKSRC}/src

SUBST_CLASSES+=	compilers
SUBST_FILES.compilers=	${WRKSRC}/tools/Makefile \
			${BUILD_WRKSRC}/STUBS/Makefile \
			${WRKSRC}/lib/*/Makefile.* \
			${BUILD_WRKSRC}/MAKE/Makefile.${BUILD_TARGET} \
			${WRKSRC}/tools/msi2lmp/src/Makefile
SUBST_SED.compilers=	-e "s|g++|${CXX}|g" \
			-e "s|gcc|${CC}|g" \
			-e "s|gfortran|${FC}|g" \
			-e "s|ifort|${FC}|g" \
			-e "s|LOCALBASE|${LOCALBASE}|g" \
			-e "s|-lg77||g" \
			-e "s|\.exe||g"
SUBST_STAGE.compilers=	post-patch

SUBST_CLASSES+=		shell
SUBST_FILES.shell=	${BUILD_WRKSRC}/Makefile
SUBST_SED.shell=	-e "s|/bin/bash|/bin/sh|g"
SUBST_STAGE.shell=	post-patch


.include "../../mk/bsd.prefs.mk"

# Hack to prevent pkgsrc from adding -lf77
.if exists(/usr/bin/gfortran) || exists(/usr/local/bin/gfortran)
FC=		gfortran
.else
SUBST_CLASSES+=		f2c
SUBST_FILES.f2c=	${WRKSRC}/lib/linalg/Makefile.gfortran
SUBST_SED.f2c=		-e 's|-march=native||g' -e 's|-mpc64||g'
SUBST_STAGE.f2c=	post-patch
.endif

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		scripts
SUBST_FILES.scripts=	${BUILD_WRKSRC}/*/Install.sh
SUBST_SED.scripts=	-e 's|sed -i|gsed -i|g' -e 's|==|=|g'
SUBST_STAGE.scripts=	post-patch
.endif

.if ${BUILD_TARGET} == pkgsrc-openmpi
SUBST_SED.compilers+=	-e "s|mpic++|${LOCALBASE}/mpi/openmpi/bin/mpic++|g"
SUBST_SED.files+=	${WRKSRC}/lib/awpmd/Makefile.openmpi
.endif

MAKE_ENV+=	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}

pre-patch:
	${CP} ${FILESDIR}/Makefile.${BUILD_TARGET} ${BUILD_WRKSRC}/MAKE

do-build:
# asphere body class2 colloid dipole fld gpu granular kim kspace manybody
# mc meam molecule opt peri poems reax replica rigid shock srd voronoi xtc
# gpu requires CUDA
# kim needs openkim-api
# voronoi needs voro++
# ${GMAKE} stubs will fail on case-insensitive filesystems because the
# directory STUBS is seen as the target
.for package in asphere body class2 colloid dipole fld granular kspace \
		manybody mc meam molecule opt peri poems reax replica \
		rigid shock srd xtc
	(cd ${BUILD_WRKSRC} && ${GMAKE} yes-${package})
.endfor
	(cd ${BUILD_WRKSRC} && ${GMAKE} package-status)
.if ${BUILD_TARGET} == "pkgsrc-serial"
	(cd ${BUILD_WRKSRC}/STUBS && ${GMAKE})
	(cd ${WRKSRC}/tools && ${GMAKE})
.endif
	(cd ${WRKSRC}/lib/atc && ${GMAKE} -f Makefile.serial)
.if ${BUILD_TARGET} == "pkgsrc-openmpi"
	(cd ${WRKSRC}/lib/awpmd && ${GMAKE} -f Makefile.openmpi)
.endif
	(cd ${WRKSRC}/lib/colvars && ${GMAKE} -f Makefile.g++)
	(cd ${WRKSRC}/lib/linalg && ${GMAKE} -f Makefile.gfortran)
	(cd ${WRKSRC}/lib/meam && ${GMAKE} -f Makefile.gfortran && cp Makefile.lammps.gfortran Makefile.lammps)
	(cd ${WRKSRC}/lib/poems && ${GMAKE} -f Makefile.g++)
	(cd ${WRKSRC}/lib/reax && ${GMAKE} -f Makefile.gfortran && cp Makefile.lammps.gfortran Makefile.lammps)
	(cd ${BUILD_WRKSRC} && ${GMAKE} ${BUILD_TARGET})
	(cd ${WRKSRC}/tools/msi2lmp/src && ${GMAKE})

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin \
		${DESTDIR}${PREFIX}/share/examples/lammps \
		${DESTDIR}${PREFIX}/share/doc \
		${DESTDIR}${PREFIX}/share/lammps
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/lmp_pkgsrc-serial \
		${DESTDIR}${PREFIX}/bin/lmp
	${CP} -R ${WRKSRC}/doc ${DESTDIR}${PREFIX}/share/doc/lammps
	${CP} -R ${WRKSRC}/examples ${DESTDIR}${PREFIX}/share/examples/lammps
	${CP} -R ${WRKSRC}/bench ${DESTDIR}${PREFIX}/share/examples/lammps
	${CP} -R ${WRKSRC}/potentials ${DESTDIR}${PREFIX}/share/lammps
	${INSTALL_PROGRAM} ${WRKSRC}/tools/binary2txt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/chain ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/data2xmovie ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/micelle2d ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/restart2data ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/msi2lmp/src/msi2lmp ${DESTDIR}${PREFIX}/bin

.include "../../math/fftw2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$
#

DISTNAME=	openmx3.7
PKGNAME=	openmx-openmpi-3.7p7
CATEGORIES=	science
DISTFILES=	openmx3.7.tar.gz patch3.7.7.tar.gz
EXTRACT_ONLY=	openmx3.7.tar.gz
MASTER_SITES=	http://www.openmx-square.org/ \
		http://www.openmx-square.org/bugfixed/14Jan31/
MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.openmx-square.org/
COMMENT=	Nano-scale material simulations based on DFT
LICENSE=	gnu-gpl-v1

WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAKE_FILE=	makefile
# check_lead and MAIN_TRAN_Display targets fail to build
BUILD_TARGET=	All \
		DosMain \
		jx \
		analysis_example \
		esp \
		OpticalConductivityMain \
		polB \
		test_mpi \
		TranMain \
		TranMain_NC
USE_TOOLS+=	gmake

# FIXME: CentOS installation didn't notice that fortran was missing from
# USE_LANGUAGES, but RHEL 5 did.
USE_LANGUAGES=	c fortran

SUBST_CLASSES+=		compile
SUBST_FILES.compile=	${WRKSRC}/makefile
SUBST_STAGE.compile=	post-patch
SUBST_SED.compile=	-e "s|-openmp -O3 -I/usr/local/include|-fopenmp ${CFLAGS}|g"
SUBST_SED.compile+=	-e "s|-lg2c -static||g"
SUBST_SED.compile+=	-e "s|-L/usr/local/lib|-Wl,-rpath=${PREFIX}/lib|g"
SUBST_SED.compile+=	-e 's|$$(CC) $$(OBJS)|$$(FC) $$(OBJS)|g'

post-extract:
	(cd ${WRKSRC} && tar zxvf ${DISTDIR}/patch3.7.4.tar.gz)

# Some build targets "install" binaries into ${WRKDIR}/${DISTNAME}/work
do-install:
	${MKDIR} ${DESTDIR}${MPI_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/openmx ${DESTDIR}${MPI_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/TranMain ${DESTDIR}${MPI_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/TranMain_NC ${DESTDIR}${MPI_PREFIX}/bin
	${MKDIR} ${DESTDIR}${MPI_PREFIX}/share/openmx
	${CP} -R ${WRKDIR}/${DISTNAME}/work/* ${DESTDIR}${MPI_PREFIX}/share/openmx
.for f in DosMain jx analysis_example esp OpticalConductivityMain polB test_mpi
	${CP} ${WRKDIR}/${DISTNAME}/work/${f} ${DESTDIR}${MPI_PREFIX}/bin
	${RM} ${DESTDIR}${MPI_PREFIX}/share/openmx/${f}
.endfor

# url2pkg-marker (please do not remove this line.)
.include "../../wip/openmpi163/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
# Investigate: Any advantage to using fftw-openmpi?
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

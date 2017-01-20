# $NetBSD$
#

DISTNAME=	petsc-3.4.1
CATEGORIES=	math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.mcs.anl.gov/petsc/petsc-as/
COMMENT=	Portable, Extensible Toolkit for  Scientific Computation
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

# GNU_CONFIGURE overrides --prefix in configure
HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran
USE_TOOLS+=		perl
CONFIG_SHELL=		${PYTHONBIN}

MAKE_FILE=		makefile
BUILD_MAKE_FLAGS+=	PETSC_DIR=${WRKSRC}

# Notes for openmpi build on petsc website
# conftests using mpicc will fail unless LD_LIBRARY_PATH includes the MPI dir
CONFIGURE_ENV+=		LD_LIBRARY_PATH=/sharedapps/uwm/common/gcc-compiler/4.5.1-v1/lib:${LOCALBASE}/openmpi/lib:${LOCALBASE}/lib:/usr/lib:/lib

# Control build options for consistency across platforms and petsc versions
#--with-debugger=gdb
CONFIGURE_ARGS+= \
	--doCleanup=0 \
	--with-ranlib=/usr/bin/ranlib \
	--search-dirs=[${MPI_PREFIX}/bin,${PREFIX}/bin,${PREFIX}/sbin] \
	--prefix=${PREFIX} \
	--with-make=${MAKE} \
	--with-clanguage='C' \
	--with-fortran=1 \
	--with-errorchecking=1 \
	--with-chud=0 \
	--with-timer=mpi \
	--with-ctable=1 \
	--with-fortran-kernels=0 \
	--with-64-bit-indices=1 \
	--with-precision=double \
	--with-shared-libraries=1 \
	--with-dynamic-loading=0 \
	--with-proc-filesystem=0 \
	--with-fortran-datatypes=0 \
	--with-fortran-interfaces=1 \
	--with-cmake=${PREFIX}/bin/cmake \
	--with-gnu-compilers=0 \
	--with-large-file-io=1 \
	--with-pic=1 \
	--with-debugging=1 \
	--LIBS=-Wl,-rpath,/sharedapps/uwm/common/gcc-compiler/4.5.1-v1/lib \
	--with-blas-lapack-dir=${PREFIX} \
	--with-mpi=1 \
	--with-mpi-dir=${PREFIX}/openmpi \
	--with-mpi-compilers=1 \
	--with-f2c-blaslapack=1 \
	--with-x=0 \
	--with-sundials=0 \
	--with-superlu_dist=0 \
	--with-parmetis=0 \
	--with-metis=0 \
	--with-threadcomm=0 \
	--with-zoltan=0 \
	--with-spai=0 \
	--with-p3dlib=0 \
	--with-hwloc=0 \
	--with-tetgen=0 \
	--with-sowing=0 \
	--with-pthreadclasses=0 \
	--with-pthread=1 \
	--with-mumps=0 \
	--with-scalapack=0 \
	--with-ptscotch=0 \
	--with-lgrind=0 \
	--with-pastix=0 \
	--with-numpy=0 \
	--with-pvode=0 \
	--with-cuda=0 \
	--with-cusp=0 \
	--with-thrust=0 \
	--with-sprng=0 \
	--with-afterimage=0 \
	--with-txtpetscgpu=0 \
	--with-openmp=0 \
	--with-glut=0 \
	--with-opengl=0 \
	--with-triangle=0 \
	--with-ccafe=0 \
	--with-generator=0 \
	--with-sieve=0 \
	--with-boost=0 \
	--with-petsc4py=0 \
	--with-pami=0 \
	--with-mathematic=0 \
	--with-clique=0 \
	--with-elemental=0 \
	--with-babel=0 \
	--with-ams=0 \
	--with-java=0 \
	--with-mpe=0 \
	--with-matlab-engine=0 \
	--with-matlab=0 \
	--with-ml=0 \
	--with-hypre=0 \
	--with-yaml=0 \
	--with-oske=0 \
	--with-suggar=0 \
	--with-expat=0 \
	--with-cproto=0 \
	--with-papi=0 \
	--with-ctetgen=0 \
	--with-ffc=0 \
	--with-fiat=0 \
	--with-scientificpython=0 \
	--with-server=0 \
	--with-pcbddc=0 \
	--with-superlu=0 \
	--with-party=0 \
	--with-c2html=0 \
	--with-chaco=0 \
	--with-valgrind=0 \
	--with-parms=0 \
	--with-fftw=0 \
	--with-mpi4py=0 \
	--with-chomod=0 \
	--with-exodusii=0 \
	--with-netcdf=0 \
	--with-hdf5=0 \
	--with-moab=0 \
	--with-umfpack=0 \
	--with-netcdf-cxx=0

.include "../../lang/python/pyversion.mk" # get python
.include "../../devel/cmake/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../wip/openmpi163/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

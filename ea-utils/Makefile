# $NetBSD$

###########################################################
#               Generated by fbsd2pkg                     #
###########################################################

PKGNAME=	ea-utils-${PORTVERSION}
DISTNAME=	ea-utils.${PORTVERSION}-806
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon@NetBSD.org

COMMENT=	Command-line tools for processing fastq sequence data
LICENSE=	mit

# Pessimistic assumption.  Test and change if possible.
MAKE_JOBS_SAFE=	no

# Just assuming C and C++: Adjust this!
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl
#SHEBANG_FILES=	t/*.sh t/*.pl t/check-fastqs \
REPLACE_SH=	t/*.sh
REPLACE_BASH=	t/*.sh
REPLACE_PERL=	t/*.pl

#post-patch:
SUBST_CLASSES+=		rscript
SUBST_STAGE.rscript=	post-patch
SUBST_FILES.rscript=	${WRKSRC}/fastx-graph
SUBST_SED.rscript=	-e 's|/usr/bin/Rscript|${LOCALBASE}/bin/Rscript|'

# _WITH_GETLINE is for FreeBSD stdio.h
CXXFLAGS+=	-I${LOCALBASE}/include -D_WITH_GETLINE

PORTVERSION=	1.1.2

# Sets OPSYS, OS_VERSION, MACHINE_ARCH, etc..
#.include "../../mk/bsd.prefs.mk"

# Keep this if there are user-selectable options.
#.include "options.mk"

# You may need this, especially if using do-install.
#AUTO_MKDIRS=	yes

test:
	${MAKE} build
	cd ${WRKSRC} && ${GMAKE} check

# Add any _DEPENDS that have a buildlink3.mk
.include "../../wip/samtools0119/buildlink3.mk"
.include "../../devel/sparsehash/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

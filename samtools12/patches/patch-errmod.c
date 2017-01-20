$NetBSD$

# Older base compilers lack full math functions
--- errmod.c.orig	2015-02-02 15:18:41.000000000 +0000
+++ errmod.c
@@ -24,6 +24,15 @@ FROM, OUT OF OR IN CONNECTION WITH THE S
 DEALINGS IN THE SOFTWARE.  */
 
 #include <math.h>
+
+#include <sys/param.h>
+#ifdef __FreeBSD__
+#	if __FreeBSD_version < 1000034
+#		define logl(x) log(x)
+#		define expl(x) exp(x)
+#	endif
+#endif
+
 #include "errmod.h"
 #include "htslib/ksort.h"
 KSORT_INIT_GENERIC(uint16_t)

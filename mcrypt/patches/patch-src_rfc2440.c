$NetBSD$

--- src/rfc2440.c.orig	2008-11-16 19:50:01.000000000 +0000
+++ src/rfc2440.c
@@ -23,7 +23,9 @@
 #include <zlib.h>
 #endif
 #include <stdio.h>
+#if !defined(__APPLE__)
 #include <malloc.h>
+#endif
 
 #include "xmalloc.h"
 #include "keys.h"

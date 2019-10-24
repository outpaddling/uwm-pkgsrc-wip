$NetBSD$

--- edit.h.orig	2019-10-24 22:27:28.000000000 +0000
+++ edit.h
@@ -86,7 +86,7 @@
 #define TWC_SHORT_NAME_LEN  14
 #define SEARCH_STR_LEN      80
 #define SEARCH_WIN_LEN      30
-#define CMD_LEN             256
+#define CMD_LEN             1024
 #define MCRYPT_KEY_LEN      64  /* FIXME: Allow longer keys? */
 #define MCRYPT_ALGO_LEN     32
 #define MESG_LEN            80

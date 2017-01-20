$NetBSD$

--- fastq-join.cpp.orig	2014-09-04 15:44:33.000000000 +0000
+++ fastq-join.cpp
@@ -53,15 +53,26 @@ int main (int argc, char **argv) {
     bool norevcomp = false;
     bool allow_ex = false;
 
-	while (	(c = getopt (argc, argv, "-dRnbeo:t:v:m:p:r:xV")) != -1) {
+        /*
+         * The leading '-' in optstr for processing non-option args as
+         * option 1 is a GNU extension and doesn't work on BSD, OS X, etc.
+         * A simple alternative in many cases is to replace case 1 with
+         * case -1 and continue the loop until optind == argc after
+         * getopt returns -1.  The global optarg is not set in this
+         * case, but we can access the argument as argv[optind++] instead.
+         */
+	setenv("POSIXLY_CORRECT", "1", 1);
+	while (	((c = getopt (argc, argv, "dRnbeo:t:v:m:p:r:xV")) != -1) 
+		|| (optind < argc) ) {
+		// printf("c = %d (%c) optind = %d\n", c, c, optind);
 		switch (c) {
-		case '\1':
+		case -1:
 			if (!in[0]) 
-				in[0]=optarg;
+				in[0]=argv[optind++];
 			else if (!in[1])		
-				in[1]=optarg;
+				in[1]=argv[optind++];
 			else if (!in[2])		
-				in[2]=optarg;
+				in[2]=argv[optind++];
 			else {
 				usage(stderr); return 1;
 			}
@@ -125,7 +136,7 @@ int main (int argc, char **argv) {
 			out[i]=(char *)malloc(strlen(pre)+10);
 			strcpy(out[i], pre);
 			char *p;
-			if (p=strchr(out[i], '%')) {
+			if ( (p=strchr(out[i], '%')) != NULL ) {
 				// substiture instead of append
 				strcpy(p, suffix[i]);
 				strcpy(p+strlen(suffix[i]), pre+(p-out[i])+1);
@@ -180,7 +191,7 @@ int main (int argc, char **argv) {
 	meminit(rc);
 
 	// read in 1 record from each file
-	while (read_ok=read_fq(fin[0], nrec, &fq[0])) {
+	while ( (read_ok=read_fq(fin[0], nrec, &fq[0])) != 0 ) {
 		for (i=1;i<in_n;++i) {
 		int mate_ok=read_fq(fin[i], nrec, &fq[i]);
 		if (read_ok != mate_ok) {

$NetBSD$

--- fastq-clipper.cpp.orig	2014-09-04 15:44:33.000000000 +0000
+++ fastq-clipper.cpp
@@ -54,13 +54,23 @@ int main (int argc, char **argv) {
 	int i;
 	
 	char *a = NULL, *f = NULL;
-	while (	(c = getopt (argc, argv, "-hedbp:i:o:l:m:x::")) != -1) {
+	/*
+	 * The leading '-' in optstr for processing non-option args as
+	 * option 1 is a GNU extension and doesn't work on BSD, OS X, etc.
+	 * A simple alternative in many cases is to replace case 1 with
+	 * case -1 and continue the loop until optind == argc after
+	 * getopt returns -1.  The global optarg is not set in this
+	 * case, but we can access the argument as argv[optind++] instead.
+	 */
+	setenv("POSIXLY_CORRECT", "1", 1);
+	while (	( (c = getopt (argc, argv, "hedbp:i:o:l:m:x::")) != -1) 
+		|| (optind < argc) ) {
 		switch (c) {
-		case '\1': 
+		case -1: 
 			if (!f) 
-				f=optarg; 
+				f=argv[optind++]; 
 			else if (!a) 
-				a=optarg; 
+				a=argv[optind++]; 
 			else {
 				usage(stderr); return 1;
 			}
@@ -115,7 +125,7 @@ int main (int argc, char **argv) {
 	int adapter_len[MAX_ADAPTER_NUM+1];
 	char *p;
 	int adapter_count=0;
-	while (p=strtok(a,":")) {
+	while ( (p=strtok(a,":")) != NULL ) {
 		a = NULL;					// strtok requirement
                 adapters[adapter_count] = p;
                 adapter_len[adapter_count] = strlen(p);         // append to list

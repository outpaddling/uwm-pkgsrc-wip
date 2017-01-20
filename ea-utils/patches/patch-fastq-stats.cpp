$NetBSD$

--- fastq-stats.cpp.orig	2014-09-04 15:44:33.000000000 +0000
+++ fastq-stats.cpp
@@ -156,15 +156,15 @@ float gcSum;
 int gcTotal;
 
 int show_max = 10;
-bool debug = 0;
-bool fastx = 0;
+bool debug = false;
+bool fastx = false;
 char *fastx_outfile = NULL;
-bool brkdown = 0;
+bool brkdown = false;
 char *brkdown_outfile = NULL;
-bool len_hist = 0;
+bool len_hist = false;
 vector<int> vlen; //all read lengths
 char *lenhist_outfile = NULL;
-bool gc = 0;
+bool gc = false;
 char *gc_outfile = NULL;
 
 int main( int argc, char**argv ) {
@@ -177,17 +177,18 @@ int main( int argc, char**argv ) {
 // bad change to working syntax... breaks things!
 //	if(argc < 2) {usage(stdout); return 0;}
 
+	setenv("POSIXLY_CORRECT", "1", 1);
 	while ( (c = getopt (argc, argv, "?DdL:g:x:b:c:w:s:h")) != -1) {
 		switch (c) {
 			case 'c': cyclemax = atoi(optarg); break;
-			case 'D': ++nodup; break;
-			case 'd': ++debug; break;
+			case 'D': nodup = true; break;
+			case 'd': debug = true; break;
 			case 'w': window = atoi(optarg); break;
 			case 's': show_max = atoi(optarg); break;
-			case 'x': fastx_outfile = optarg; ++fastx; break;
-			case 'b': brkdown_outfile = optarg; ++brkdown; break;
-			case 'L': ++len_hist; lenhist_outfile = optarg; break;
-			case 'g': gc_outfile = optarg; ++gc; break;
+			case 'x': fastx_outfile = optarg; fastx = true; break;
+			case 'b': brkdown_outfile = optarg; brkdown = true; break;
+			case 'L': len_hist = true; lenhist_outfile = optarg; break;
+			case 'g': gc_outfile = optarg; gc = true; break;
 			case 'h': usage(stdout); return 0;
 			case '?':
 					  if (!optopt) {

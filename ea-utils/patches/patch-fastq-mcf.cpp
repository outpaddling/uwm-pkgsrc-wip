$NetBSD$

--- fastq-mcf.cpp.orig	2014-09-04 15:44:33.000000000 +0000
+++ fastq-mcf.cpp
@@ -265,7 +265,17 @@ int main (int argc, char **argv) {
     meminit(phred_adjust);
 
     int option_index = 0;
-    while (	(c = getopt_long(argc, argv, "-nf0uXUVHKSRdbehp:o:O:l:s:m:t:k:x:P:q:L:C:w:F:D:",long_options,&option_index)) != -1) {
+
+    /*
+     * The leading '-' in optstr for processing non-option args as
+     * option 1 is a GNU extension and doesn't work on BSD, OS X, etc.
+     * A simple alternative in many cases is to replace case 1 with
+     * case -1 and continue the loop until optind == argc after
+     * getopt returns -1.  The global optarg is not set in this
+     * case, but we can access the argument as argv[optind++] instead.
+     */
+    setenv("POSIXLY_CORRECT", "1", 1);
+    while ( ((c = getopt_long(argc, argv, "nf0uXUVHKSRdbehp:o:O:l:s:m:t:k:x:P:q:L:C:w:F:D:",long_options,&option_index)) != -1) || (optind < argc) ) {
 		switch (c) {
 			case '\0':
                 { 
@@ -338,11 +348,17 @@ int main (int argc, char **argv) {
                     }
                     break;
                 }
-			case '\1': 
+			case -1: 
 				if (!afil) 
-					afil = optarg; 
+				{
+					afil = argv[optind++]; 
+					// fprintf(stderr, "afil = %s\n", afil);
+				}
 				else if (i_n<MAX_FILES) 
-					ifil[i_n++] = optarg; 
+				{
+					ifil[i_n++] = argv[optind++]; 
+					// fprintf(stderr, "ifile[%u] = %s\n",i_n,ifil[i_n-1]);
+				}
 				else {
 					usage(stderr, "Too many input files."); return 1;
 				}
@@ -370,9 +386,13 @@ int main (int argc, char **argv) {
 			case 'P': phred = (char) atoi(optarg); break;
 			case 'D': duplen = atoi(optarg); break;
 			case 'h': usage(stdout); return 1; 
-			case 'o': if (!o_n < MAX_FILES) 
-						  ofil[o_n++] = optarg;
-					  break;
+			case 'o':
+				if (o_n < MAX_FILES) 
+				{
+					ofil[o_n++] = optarg;
+					// fprintf(stderr, "ofil = %s\n", ofil[o_n-1]);
+				}
+				break;
                		case 'O': nreadsout = atoi(optarg); break;
 			case 's': scale = atof(optarg); break;
 			case 'S': skipb = 1; break;
@@ -408,7 +428,7 @@ int main (int argc, char **argv) {
 	}
 
 	if (!noclip && o_n != i_n) {
-		fprintf(stderr, "Error: number of input files must match number of '-o' output files.\n");
+		fprintf(stderr, "Error: number of input files (%u) must match number of '-o' output files (%u).\n", i_n, o_n);
 		return 1;
 	}
 
@@ -685,7 +705,7 @@ int main (int argc, char **argv) {
 				for(a=0;a<acnt;++a) {
 					char *p;
 					// search whole seq for 15 char "end" of adap string
-					if (p = strstr(s+1, ad[a].escan)) { 
+					if ( (p = strstr(s+1, ad[a].escan)) != NULL ) { 
 						if (debug > 1) fprintf(stderr, "  END S: %s A: %s (%s), P: %d, SL: %d, Z:%d\n", s, ad[a].id, ad[a].escan, (int) (p-s), ns, (p-s) == ns-SCANLEN);
                         // found at the very end
 						if ((p-s) == ns-SCANLEN) 
@@ -838,12 +858,12 @@ int main (int argc, char **argv) {
 				}
 
                 char *p;
-                if (p=strstr(ad[a].id, "_3p")) {
+                if ( (p=strstr(ad[a].id, "_3p")) != NULL ) {
                     if (p[3] == '\0' || p[3] == '_') {
                         ad[a].end[i]='e'; 
 					    cnt = ad[a].ecnt[i];
                     }
-                } else if (p=strstr(ad[a].id, "_5p")) {
+                } else if ( (p=strstr(ad[a].id, "_5p")) != NULL ) {
                     if (p[3] == '\0' || p[3] == '_') {
                         ad[a].end[i]='b';
                         cnt = ad[a].bcnt[i];
@@ -961,7 +981,7 @@ int main (int argc, char **argv) {
     google::sparse_hash_map <std::string, int>::const_iterator lookup_it;
 
     bool io_ok = true;
-    while (read_ok=fin[0].read_fq(nrec, &fq[0])) {
+    while ( (read_ok=fin[0].read_fq(nrec, &fq[0])) != 0 ) {
                 if (nreadsout && (wrec == nreadsout)) break;
 		for (i=1;i<i_n;++i) {
 			int mok=fin[1].read_fq(nrec, &fq[i]);
@@ -1686,7 +1706,7 @@ void valid_arg(char opt, const char *arg
 }
 
 bool  arg_int_pair(const char *optarg, int &a, int&b) {
-    if (!strchr(optarg, ',')) {
+    if ( strchr(optarg, ',') == NULL ) {
         return false;
     }
     a=atoi(optarg);

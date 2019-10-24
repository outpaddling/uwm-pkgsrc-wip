$NetBSD$

--- build_m.c.orig	2019-10-24 22:25:16.000000000 +0000
+++ build_m.c
@@ -861,7 +861,7 @@ void    set_makefile(proj_t *project, ch
 void    init_makefile(proj_t *project,char *makefile,file_t *file,opt_t *options)
 
 {
-    strlcpy(project->make_cmd, "make", PATH_MAX);
+    strlcpy(project->make_cmd, "make", CMD_LEN);
     strlcpy(project->makefile, makefile, PATH_MAX);
     
     /*

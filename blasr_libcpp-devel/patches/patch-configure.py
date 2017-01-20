$NetBSD$

# Remove linuxism

--- configure.py.orig	2016-08-31 05:05:31 UTC
+++ configure.py
@@ -93,7 +93,7 @@ nohdf         ?=1
 """%(dict(thisdir=thisdir))
 
 def get_OS_STRING():
-    G_BUILDOS_CMD = """bash -c 'set -e; set -o pipefail; id=$(lsb_release -si | tr "[:upper:]" "[:lower:]"); rel=$(lsb_release -sr); case $id in ubuntu) printf "$id-%04d\n" ${rel/./};; centos) echo "$id-${rel%%.*}";; *) echo "$id-$rel";; esac' 2>/dev/null"""
+    G_BUILDOS_CMD = """printf `uname`-`uname -r | cut -d - -f 1`'\n'"""
     return shell(G_BUILDOS_CMD)
 
 def get_PBBAM(env, prefix):

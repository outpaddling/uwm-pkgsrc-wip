$NetBSD$

# Patch to all build on CentOS 6.7 with base GCC 4.4.7
# https://patchwork.ozlabs.org/patch/563039/
--- libs/container/src/pool_resource.cpp.orig	2016-04-27 17:14:16.420319116 +0000
+++ libs/container/src/pool_resource.cpp
@@ -32,11 +32,11 @@ namespace pmr {
 class pool_data_t
    : public block_slist_base<>
 {
-   typedef block_slist_base<> block_slist_base;
+   typedef block_slist_base<> block_slist_base_t;
 
    public:
    explicit pool_data_t(std::size_t initial_blocks_per_chunk)
-      : block_slist_base(), next_blocks_per_chunk(initial_blocks_per_chunk)
+      : block_slist_base_t(), next_blocks_per_chunk(initial_blocks_per_chunk)
    {  slist_algo::init_header(&free_slist);  }
 
    void *allocate_block() BOOST_NOEXCEPT
@@ -59,7 +59,7 @@ class pool_data_t
    void release(memory_resource &upstream)
    {
       slist_algo::init_header(&free_slist);
-      this->block_slist_base::release(upstream);
+      this->block_slist_base_t::release(upstream);
       next_blocks_per_chunk = pool_options_minimum_max_blocks_per_chunk;
    }
 
@@ -72,7 +72,7 @@ class pool_data_t
       
       //Minimum block size is at least max_align, so all pools allocate sizes that are multiple of max_align,
       //meaning that all blocks are max_align-aligned.
-      char *p = static_cast<char *>(block_slist_base::allocate(blocks_per_chunk*pool_block, mr));
+      char *p = static_cast<char *>(block_slist_base_t::allocate(blocks_per_chunk*pool_block, mr));
 
       //Create header types. This is no-throw
       for(std::size_t i = 0, max = blocks_per_chunk; i != max; ++i){

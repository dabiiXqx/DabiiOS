#pragma once
#include <stddef.h>

extern int end_of_krnl_img;

#define ALLOCATED 1
#define FREE 0
#define ALLIGN 4

//this chunk is also on hopes and dreams. please ignore my futile attempts of making an allocator for now
struct HeapChunk {
    uint32_t header; //bit 0 is the allocated bit
    struct HeapChunk *prev_block;
    uint32_t footer;
    uint32_t payload[];
};

void *kmemset(void *s, int c, size_t n);
void heap_init();
void *kalloc(size_t bytes);
void *kfree(void* ptr);
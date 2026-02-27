#pragma once
#include <stddef.h>

extern int end_of_krnl_img;

#define ALLOCATED 1

//this chunk is also on hopes and dreams. please ignore my futile attempts of making an allocator for now
struct AllocHeapChunk {
    uint32_t header; //bit 0 is the allocated bit
    uint32_t payload[];
};
struct FreeHeapChunk {
    uint32_t header;
    struct FreeHeapChunk* prev_block;
    struct FreeHeapChunk* next_block;
};

void *kmemset(void *s, int c, size_t n);
void heap_init();
void *kalloc(size_t bytes);
void *kfree(void* ptr);
#include "../HeaderFiles/kernel32.h"
static void* heap_base;
static void* heap_top;

void *kmemset(void *s, int c, size_t n){
    unsigned char* p = (unsigned char*)s;
    while(n--){
        *p++ = c;
    }
    return s;
}

void heap_init(){
    heap_base = &end_of_krnl_img;
    heap_top = heap_base;
}
void *kalloc(size_t bytes){
    //This allocator is genuinely running on hopes and dreams 😭
    struct HeapChunk *heapchunk = (struct HeapChunk*)heap_top;
    heapchunk->header = bytes | ALLOCATED;
    heapchunk->footer = heapchunk->header;
    void* ptr = &heapchunk->payload;
    heap_top += sizeof(struct HeapChunk) + bytes;

    return ptr;
}
void *kfree(void* ptr){
    //still didn't make it because the allocator itself is running on hopes and dreams.

}
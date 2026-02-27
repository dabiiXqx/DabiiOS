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
    if(bytes == 0){
        return NULL;
    }

    struct AllocHeapChunk *heapchunk = (struct AllocHeapChunk*)heap_top;
    bytes = (bytes + 3) & ~3;

    heapchunk->header = bytes | ALLOCATED;
    void* payload = heapchunk->payload;

    uint32_t* footer = (uint32_t*)((char*)payload + bytes);
    *footer = heapchunk->header;

    heap_top = ((char*)heap_top + sizeof(struct AllocHeapChunk) + bytes + sizeof(uint32_t));

    return payload;
}
void *kfree(void* ptr){
    

}
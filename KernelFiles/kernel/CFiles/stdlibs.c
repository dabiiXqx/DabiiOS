#include "../HeaderFiles/kernel32.h"

void *kmemset(void *s, int c, size_t n){
    unsigned char* p = (unsigned char*)s;
    while(n--){
        *p++ = c;
    }
    return s;
}
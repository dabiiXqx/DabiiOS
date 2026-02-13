#include "../HeaderFiles/stdlibs.h"

void *kmemset(void *s, int c, size_t n) {
    unsigned char *p = (unsigned char *)s; //converts void pointer into unsigned char pointer
    while (n--) {
        *p++ = (unsigned char)c; /*increments value of p by 1 byte (size of char)
                                 *and replaces it with c casted as unsigned char */
    }
    return s; //returns modified char array
}
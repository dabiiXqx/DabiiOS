#include "../HeaderFiles/kernel32.h"
#include <stdint.h>

void *kmemset(void *s, int c, size_t n) {
    unsigned char *p = (unsigned char *)s; //converts void pointer into unsigned char pointer
    while (n--) {
        *p++ = (unsigned char)c; /*increments value of p by 1 byte (size of char)
                                 *and replaces it with c casted as unsigned char */
    }
    return s; //returns modified char array
}
void VGA(const char* text, uint8_t fg, uint8_t bg, _Bool Halt) {
    volatile uint16_t* VGA_base = (volatile uint16_t*)0xb8000;
    uint16_t attr = (bg << 4) | fg;
    for (int i = 0; i < 80*25; i++) {
        VGA_base[i] = (attr << 8) | ' ';
    }
    for (int i = 0; text[i] != 0; i++) {
        VGA_base[i] = (attr << 8) | text[i];
    }
    if (Halt) {
        while (1) {
            asm("hlt");
        }
    }

}
#include "../HeaderFiles/kernel32.h"
#include <stdint.h>


//trust me, i know the code is horrible. like i actually know it. i just don't know any "good" ways to code ig

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_FULL VGA_HEIGHT * VGA_WIDTH
static inline int get_index();

volatile uint16_t* VGA_base = (volatile uint16_t*)0xb8000;

void scroll(volatile uint16_t* vga);
void clear_screen(volatile uint16_t* vga, uint16_t attr);

void VGA(const char* text, uint8_t fg, uint8_t bg, _Bool clear, _Bool Halt) {
    uint16_t attr = (bg << 4) | fg;
    if(clear){
        clear_screen(VGA_base, attr);
    }
    for (int i = 0; text[i] != 0; i++) {
        VGA_base[i] = (attr << 8) | text[i];
    }
    if (Halt) {
        while (1) {
            asm volatile("hlt");
        }
    }

}

static int cursor[2] = {0, 8}; //[0] is row [1] is column

void console_putc(char c, uint8_t fg, uint8_t bg, _Bool Halt){
    int index = get_index();
    uint16_t attr = (bg << 4) | fg;
    if(c == 0){
        return;
    }
    VGA_base[index] = (attr << 8) | c;
    cursor[1]++;
    if(cursor[1] >= 80){
        cursor[1] = 0;
        cursor[0]++;
        if(cursor[0] >= 25){
            scroll(VGA_base);
            for(int i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_FULL; i++){
                VGA_base[i] = (attr << 8) | 0x0;
            }
            cursor[0] = 24;
        }
    }
    if (Halt) {
        while (1) {
            asm volatile("hlt");
        }
    }
}
void console_backc(uint8_t fg, uint8_t bg){
    uint16_t attr = (bg << 4) | fg;
    int index = get_index();
    cursor[1]--;
    if(cursor[1] < 8 && cursor[0] == 0){
        cursor[1] = 8;
        if (cursor[0] < 0){
            cursor[0] = 0;
        }
    }
    else{
        index--;
        VGA_base[index] = (attr << 8) | ' ';
    }
    return;
}

void newline(uint8_t fg, uint8_t bg){
    uint16_t attr = (bg << 4) | fg;
    int index = get_index();
    cursor[0]++;
    cursor[1] = 0;
    if(cursor[0] >= 25){
        scroll(VGA_base);
        for(int i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_FULL; i++){
            VGA_base[i] = (attr << 8) | 0x0;
        }
        cursor[0] = 24;
    }
    return;
}

void scroll(volatile uint16_t* vga){
    for(int i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++){
        vga[i] = vga[i + 80];
    }
}

void clear_screen(volatile uint16_t* vga, uint16_t attr){
    for (int i = 0; i < VGA_FULL; i++) {
        vga[i] = (attr << 8) | ' ';
    }
}
static inline int get_index() {
    return cursor[0] * VGA_WIDTH + cursor[1];
}
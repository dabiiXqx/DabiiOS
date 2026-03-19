#pragma once
#include "../HeaderFiles/kernel32.h"
#include <stddef.h>
#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_FULL VGA_HEIGHT * VGA_WIDTH

extern _Bool prompt_valid;
extern volatile uint16_t* VGA_base;
extern int cursor[2];

#define get_index() cursor[0] * VGA_WIDTH + cursor[1]
#define set_index(y, x) cursor[0] = y; cursor[1] = x; get_index();

void VGA(const char* text, uint8_t fg, uint8_t bg);
void console_putc(char c, uint8_t fg, uint8_t bg);
void console_backc(uint8_t fg, uint8_t bg);
void newline(uint8_t fg, uint8_t bg);
void do_cursor(int index);
void clear_screen(uint16_t attribute);

int kprintf(char *format, ...);
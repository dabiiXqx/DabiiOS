#pragma once
#include "../HeaderFiles/kernel32.h"
#include <stddef.h>
#include <stdint.h>

extern _Bool prompt_valid;
void VGA(const char* text, uint8_t fg, uint8_t bg, _Bool clear, _Bool Halt, _Bool use_index);
void console_putc(char c, uint8_t fg, uint8_t bg, _Bool Halt);
void console_backc(uint8_t fg, uint8_t bg);
void newline(uint8_t fg, uint8_t bg);

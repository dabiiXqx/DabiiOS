#pragma once
#include "../HeaderFiles/kernel32.h"
#include <stddef.h>
#include <stdint.h>

void *kmemset(void *s, int c, size_t n);
void WriteToVGA(const char* text, uint8_t fg, uint8_t bg, _Bool Halt);

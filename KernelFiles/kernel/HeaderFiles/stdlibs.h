#pragma once
#include <stddef.h>

extern int end_of_krnl_img;

void *kmemset(void *s, int c, size_t n);

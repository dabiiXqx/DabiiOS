#pragma once
#include <stddef.h>

extern int end_of_krnl_img;

void *kmemset(void *s, int c, size_t n);

int kstrlen(char *string);
void reverse(char s[]);

void itoa(int n, char s[]);
void itox(unsigned int n, char s[]);
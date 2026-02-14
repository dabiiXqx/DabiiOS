#include "../HeaderFiles/kernel32.h"
#include <stdint.h>

//I have no idea what i'm doing with my life.

extern void load_idt(void);

struct idt_entry idt[256];

struct idt_ptr idtp;

void setIDTgate(uint8_t vector, uint32_t base, uint8_t flags, uint8_t type) {
    idt[vector].base_low = base & 0xFFFF;
    idt[vector].base_high = (base >> 16) & 0xFFFF;
    idt[vector].flags = flags;
    idt[vector].selector = 0x08;
    idt[vector].always0 = 0;
}

//Right now, the install function isn't finished, im finishing it later.
void install_idt(void) {
    kmemset(idt, 0, sizeof(idt));
    idtp.limit = sizeof(idt) - 1;
    idtp.base = (uint32_t)idt;
	load_idt();
}

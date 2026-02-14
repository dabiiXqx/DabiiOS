#include "../HeaderFiles/idt.h"
#include "../HeaderFiles/stdlibs.h"
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
__attribute__ ((interrupt)) void dummy_handler(struct interrupt_frame *frame) {
    volatile uint16_t* Screen = (volatile uint16_t*)0xb8000;
    uint8_t fg = 0xF;
    uint8_t bg = 0x1;
    uint16_t attr = (bg << 4) | fg;
    const char *text = "If i'm called, that means the IDT worked!";
    for (int i = 0; i < 80*25; i++) {
        Screen[i] = (attr << 8) | ' ';
    }
    for (int i = 0; text[i] != 0; i++) {
        Screen[i] = (attr << 8) | text[i];
    }
    while (1) {
        asm("hlt");
    }
}

//Right now, the install function isn't finished, im finishing it later.
void install_idt(void) {
    kmemset(idt, 0, sizeof(idt));
    idtp.limit = sizeof(idt) - 1;
    idtp.base = (uint32_t)idt;

	for (int i = 0; i < 32; i++) {
		setIDTgate(i, (uint32_t)&dummy_handler, (uint8_t)0, (uint8_t)0x8E);
	}
	load_idt();
}

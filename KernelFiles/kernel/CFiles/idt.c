#include "../HeaderFiles/kernel32.h"
#include <stdint.h>

struct idt_gate idt[256];

struct idt_descriptor idtp;

void set_idt_gate(void *handler, uint8_t vector, uint8_t attributes){
	idt[vector].offset_low = (uint32_t)handler & 0xffff; //grabs least significant 16 bits
	idt[vector].selector = 0x8;
	idt[vector].zero = 0;
	idt[vector].attributes = attributes;
	idt[vector].offset_high = ((uint32_t)handler >> 16) & 0xffff;
}


void idt_flush(struct idt_descriptor *idtp){
	//THE IDT POINTER IS NORMAL
	asm volatile("lidt %0" : : "m" (idtp));
	asm volatile("sidt %0" : : "m" (idtp));
}
void pic_init(void){
	/* currently not used, testing IDT and ISRs before enabling
	 * hardware peripheral/software interrupts. */
	outb(0x20, 0x11);
	outb(0xA0, 0x11);

	outb(0x21, 32);
	outb(0xA1, 40);

	outb(0x21, 4);
	outb(0xA1, 2);

	outb(0x21, 1);
	outb(0xA1, 1);

	outb(0x21, 0xFD);
	outb(0xA1, 0xFF);
}

void (*isr_functions[32])(void) = {
	isr0, isr1, isr2, isr3, isr4, isr5, isr6, isr7, isr8, isr9,
	isr10, isr11, isr12, isr13, isr14, isr15, isr16, isr17,
	isr18, isr19, isr20, isr21, isr22, isr23, isr24, isr25,
	isr26, isr27, isr28, isr29, isr30, isr31
};

void idt_init(void){
	kmemset(&idt, 0, sizeof(idt));
	idtp.limit = sizeof(idt) - 1;
	idtp.base = (uint32_t)&idt;
	for(int i = 0; i < 32; i++){
		set_idt_gate(isr_functions[i], i, 0x8E);
	}
	idt_flush(&idtp);
}
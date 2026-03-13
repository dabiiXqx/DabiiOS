#include "../HeaderFiles/kernel32.h"
#include <stdint.h>

//I dont know what i'm doing with my life, but i know what this IDT is doing

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
	asm volatile("lidt %0" : : "m" (*idtp));
	asm volatile("sidt %0" : : "m" (*idtp));
}

void (*isr_functions[32])(void) = {
	isr0, isr1, isr2, isr3, isr4, isr5, isr6, isr7, isr8, isr9,
	isr10, isr11, isr12, isr13, isr14, isr15, isr16, isr17,
	isr18, isr19, isr20, isr21, isr22, isr23, isr24, isr25,
	isr26, isr27, isr28, isr29, isr30, isr31
};

void(*irq_functions[16])(void) = {
	irq0, irq1, irq2, irq3, irq4, irq5, irq6, irq7, 
	irq8, irq9, irq10, irq11, irq12, irq13, irq14, irq15
};

void idt_init(void){
	kmemset(&idt, 0, sizeof(idt));
	idtp.limit = sizeof(idt) - 1;
	idtp.base = (uint32_t)&idt;
	for(int i = 0; i < 32; i++){
		set_idt_gate(isr_functions[i], i, 0x8E);
	}
	set_idt_gate(irq0, 32, 0x8E);
	set_idt_gate(irq1, 33, 0x8E);
	idt_flush(&idtp);
}
//!!!!!!!!!!!!!!!!!!!!PIC STUFF!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void pic_init(void){
	outb(0x20, 0x11); // initializes pics in cascade mode (master-slave)
	outb(0xA0, 0x11);

	outb(0x21, 32); // master offset
	outb(0xA1, 40); // slave offset

	outb(0x21, 4); // tells master there's a slave at irq 2
	outb(0xA1, 2); // tells slave it is a slave

	outb(0x21, 1); // make the pics be in 8086 mode
	outb(0xA1, 1);

	outb(0x21, 0xFF); //masks PICs, since i will not use all of the IRQs.
	outb(0xA1, 0xFF);
}
void pic_eoi(uint8_t irq){
	if(irq >= 8){
		outb(0xA0, 0x20);
	}

	outb(0x20, 0x20);
}

void pic_disable(void){
	outb(0x21, 0xFF);
	outb(0xA1, 0xFF);
}

void irq_mask(uint8_t irq){
	uint16_t port;
	uint8_t value;

	if(irq < 8){
		port = 0x21;
	}
	else {
		port = 0xA1;
		irq -= 8;
	}
	value = inb(port) | 1 << irq;
	outb(port, value);
}
void irq_clear(uint8_t irq){
	uint16_t port;
	uint8_t value;
	if(irq < 8){
		port = 0x21;
	}
	else {
		port = 0xA1;
		irq -= 8;
	}

	value = inb(port) & ~(1 << irq);
	outb(port, value);
}

uint16_t pic_get_irr(void) {
    return __pic_get_irq_reg(0x0a);
}

uint16_t pic_get_isr(void)
{
    return __pic_get_irq_reg(0x0b);
}
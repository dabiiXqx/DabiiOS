#include "../HeaderFiles/kernel32.h"
#include <stdint.h>

//I have no idea what i'm doing with my life.


struct idt_entry idt[256];

struct idt_ptr idtp;

void setIDTgate(uint8_t vector, uint32_t base, uint8_t flags) {
    idt[vector].base_low = base & 0xFFFF;
    idt[vector].base_high = (base >> 16) & 0xFFFF;
    idt[vector].flags = flags;
    idt[vector].selector = 0x08;
    idt[vector].always0 = 0;
}

void idt_flush(struct idt_ptr *idtp) {
	__asm__ __volatile__("lidt %0" : : "m"(*idtp) :);
}

void install_idt(void) {
    kmemset(idt, 0, sizeof(idt));
    idtp.limit = sizeof(idt) - 1;
    idtp.base = (struct idt_entry*)&idt;

    setIDTgate(0, (uint32_t)isr_noerr0, 0x8E);
    setIDTgate(1, (uint32_t)isr_noerr1, 0x8E);
    setIDTgate(2, (uint32_t)isr_noerr2, 0x8E);
    setIDTgate(3, (uint32_t)isr_noerr3, 0x8E);
    setIDTgate(4, (uint32_t)isr_noerr4, 0x8E);
    setIDTgate(5, (uint32_t)isr_noerr5, 0x8E);
    setIDTgate(6, (uint32_t)isr_noerr6, 0x8E);
    setIDTgate(7, (uint32_t)isr_noerr7, 0x8E);
    setIDTgate(8, (uint32_t)isr_err8, 0x8E);
    setIDTgate(9, (uint32_t)isr_noerr9, 0x8E);
    setIDTgate(10, (uint32_t)isr_err10, 0x8E);
    setIDTgate(11, (uint32_t)isr_err11, 0x8E);
    setIDTgate(12, (uint32_t)isr_err12, 0x8E);
    setIDTgate(13, (uint32_t)isr_err13, 0x8E);
    setIDTgate(14, (uint32_t)isr_err14, 0x8E);
    setIDTgate(15, (uint32_t)isr_noerr15, 0x8E);
    setIDTgate(16, (uint32_t)isr_noerr16, 0x8E);
    setIDTgate(17, (uint32_t)isr_err17, 0x8E);
    setIDTgate(18, (uint32_t)isr_noerr18, 0x8E);
    setIDTgate(19, (uint32_t)isr_noerr19, 0x8E);
    setIDTgate(20, (uint32_t)isr_noerr20, 0x8E);
    setIDTgate(21, (uint32_t)isr_err21, 0x8E);
    setIDTgate(22, (uint32_t)isr_noerr22, 0x8E);
    setIDTgate(23, (uint32_t)isr_noerr23, 0x8E);
    setIDTgate(24, (uint32_t)isr_noerr24, 0x8E);
    setIDTgate(25, (uint32_t)isr_noerr25, 0x8E);
    setIDTgate(26, (uint32_t)isr_noerr26, 0x8E);
    setIDTgate(27, (uint32_t)isr_noerr27, 0x8E);
    setIDTgate(28, (uint32_t)isr_noerr28, 0x8E);
    setIDTgate(29, (uint32_t)isr_noerr29, 0x8E);
    setIDTgate(30, (uint32_t)isr_noerr30, 0x8E);
    setIDTgate(31, (uint32_t)isr_noerr31, 0x8E);

	idt_flush((struct idt_ptr*)&idtp);
}

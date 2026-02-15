#include "../HeaderFiles/kernel32.h"
#include <stdint.h>

//I have no idea what i'm doing with my life.


struct idt_entry idt[256];

struct idt_ptr idtp;

void setIDTgate(uint8_t vector, void* isr, uint8_t flags) {
    idt[vector].base_low = ((uint32_t)isr & 0xFFFF);
    idt[vector].base_high = ((uint32_t)isr >> 16) & 0xFFFF;
    idt[vector].flags = flags;
    idt[vector].selector = (uint16_t)0x08;
    idt[vector].always0 = 0;
}

void idt_flush(struct idt_ptr idtp) {
	asm volatile (
        "lidt %0"
        : : "m"(idtp)
    );
}

void install_idt(void) {
    kmemset(idt, 0, sizeof(idt));
    idtp.limit = sizeof(idt) - 1;
    idtp.base = (struct idt_entry*)&idt;

    setIDTgate(0, isr_noerr0, 0x8E);
    setIDTgate(1, isr_noerr1, 0x8E);
    setIDTgate(2, isr_noerr2, 0x8E);
    setIDTgate(3, isr_noerr3, 0x8E);
    setIDTgate(4, isr_noerr4, 0x8E);
    setIDTgate(5, isr_noerr5, 0x8E);
    setIDTgate(6, isr_noerr6, 0x8E);
    setIDTgate(7, isr_noerr7, 0x8E);
    setIDTgate(8, isr_err8, 0x8E);
    setIDTgate(9, isr_noerr9, 0x8E);
    setIDTgate(10, isr_err10, 0x8E);
    setIDTgate(11, isr_err11, 0x8E);
    setIDTgate(12, isr_err12, 0x8E);
    setIDTgate(13, isr_err13, 0x8E);
    setIDTgate(14, isr_err14, 0x8E);
    setIDTgate(15, isr_noerr15, 0x8E);
    setIDTgate(16, isr_noerr16, 0x8E);
    setIDTgate(17, isr_err17, 0x8E);
    setIDTgate(18, isr_noerr18, 0x8E);
    setIDTgate(19, isr_noerr19, 0x8E);
    setIDTgate(20, isr_noerr20, 0x8E);
    setIDTgate(21, isr_err21, 0x8E);
    setIDTgate(22, isr_noerr22, 0x8E);
    setIDTgate(23, isr_noerr23, 0x8E);
    setIDTgate(24, isr_noerr24, 0x8E);
    setIDTgate(25, isr_noerr25, 0x8E);
    setIDTgate(26, isr_noerr26, 0x8E);
    setIDTgate(27, isr_noerr27, 0x8E);
    setIDTgate(28, isr_noerr28, 0x8E);
    setIDTgate(29, isr_noerr29, 0x8E);
    setIDTgate(30, isr_noerr30, 0x8E);
    setIDTgate(31, isr_noerr31, 0x8E);

	idt_flush((struct idt_ptr)idtp);
}

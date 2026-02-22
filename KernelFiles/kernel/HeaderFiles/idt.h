#pragma once
#include "../HeaderFiles/kernel32.h"
#include <stdint.h>

struct idt_gate {
	uint16_t offset_low;
	uint16_t selector;
	uint8_t zero;
	uint8_t attributes;
	uint16_t offset_high;
}__attribute__((packed));

struct idt_descriptor {
	uint16_t limit; //2 bytes
	uint32_t base; //6 bytes
}__attribute__((packed));

void idt_init(void);
void pic_init(void);
void pic_disable(void);
void irq_mask(uint8_t irq);
void irq_clear(uint8_t irq);
void pic_eoi(uint8_t irq);

extern void isr0(void);
extern void isr1(void);
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr8(void);
extern void isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!PIC STUFF!!!!!!!!!!!!!!!!!!!!!!!!!!!

static uint16_t __pic_get_irq_reg(int ocw3)
{

    outb(0x20, ocw3);
    outb(0xA0, ocw3);
    return (inb(0xA0) << 8) | inb(0x20);
}

extern void irq0(void);
extern void irq1(void);
extern void irq2(void);
extern void irq3(void);
extern void irq4(void);
extern void irq5(void);
extern void irq6(void);
extern void irq7(void);
extern void irq8(void);
extern void irq9(void);
extern void irq10(void);
extern void irq11(void);
extern void irq12(void);
extern void irq13(void);
extern void irq14(void);
extern void irq15(void);
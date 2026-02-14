#pragma once
#include "../HeaderFiles/kernel32.h"
#include <stdint.h>

struct idt_entry {
	uint16_t base_low;
	uint16_t selector;
	uint8_t always0;
	uint8_t flags;
	uint16_t base_high;
} __attribute__((packed));

struct idt_ptr {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

void install_idt(void);

//ISR stubs to hook to IDT
extern void isr_noerr0(void);
extern void isr_noerr1(void);
extern void isr_noerr2(void);
extern void isr_noerr3(void);
extern void isr_noerr4(void);
extern void isr_noerr5(void);
extern void isr_noerr6(void);
extern void isr_noerr7(void);
extern void isr_err8(void);
extern void isr_noerr9(void);
extern void isr_err10(void);
extern void isr_err11(void);
extern void isr_err12(void);
extern void isr_err13(void);
extern void isr_err14(void);
extern void isr_noerr15(void);
extern void isr_noerr16(void);
extern void isr_err17(void);
extern void isr_noerr18(void);
extern void isr_noerr19(void);
extern void isr_noerr20(void);
extern void isr_err21(void);
extern void isr_noerr22(void);
extern void isr_noerr23(void);
extern void isr_noerr24(void);
extern void isr_noerr25(void);
extern void isr_noerr26(void);
extern void isr_noerr27(void);
extern void isr_noerr28(void);
extern void isr_noerr29(void);
extern void isr_noerr30(void);
extern void isr_noerr31(void);

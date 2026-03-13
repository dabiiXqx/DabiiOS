//i swear im not copying windows

//obviously incomplete
#include "../HeaderFiles/kernel32.h"
__attribute__ ((section (".kernel_main")))
void kernel_main(){
	clear_screen(0x1f);
	VGA("Kernel> ", 0xf, 0x1);
	do_cursor(8);
	idt_init();
	pic_init();
	irq_clear(0);
	irq_clear(1);
	asm volatile("sti");
	halt();
}

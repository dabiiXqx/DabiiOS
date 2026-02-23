//i swear im not copying windows

//obviously incomplete
#include "../HeaderFiles/kernel32.h"
__attribute__ ((section (".kernel_main")))
void kernel_main(){
	VGA("Kernel", 0xf, 0x1, 0);
	idt_init();
	pic_init();
	irq_clear(0);
	irq_clear(1);
	asm volatile("sti");
	while(1){
		asm volatile("hlt");
	}
}
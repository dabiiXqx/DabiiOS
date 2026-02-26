//i swear im not copying windows

//obviously incomplete
#include "../HeaderFiles/kernel32.h"
__attribute__ ((section (".kernel_main")))
void kernel_main(){
	do_cursor(8);
	VGA("Kernel> ", 0xf, 0x1, 1, 0, 0);
	idt_init();
	pic_init();
	irq_clear(0);
	irq_clear(1);
	asm volatile("sti");
	heap_init();
	void* pointer = kalloc(5);
	char* ptr = (char*)pointer;
	for(int i = 0; i < 5; i++){
		ptr[i] = '3';
	}
	while(1){
		asm volatile("hlt");
	}
}
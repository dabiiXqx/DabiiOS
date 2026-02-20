//i swear im not copying windows


//obviously incomplete
#include "../HeaderFiles/kernel32.h"
__attribute__ ((section (".kernel_main")))
void kernel_main(){
	VGA("Kernel", 0xf, 0x1, 0);
	idt_init();
	asm volatile("ud2"); //tests if ISRs work with exception vector 6
	while(1){
		asm volatile("hlt");
	}
}

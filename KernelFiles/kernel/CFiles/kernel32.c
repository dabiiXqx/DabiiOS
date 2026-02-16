//i swear im not copying windows


//obviously incomplete
#include "../HeaderFiles/kernel32.h"
void kernel_main(){
	VGA("Kernel", 0xf, 0x1, 0);
	install_idt();
	asm volatile ("ud2");
	while(1){
		asm volatile("hlt");
	}
}

//i swear im not copying windows


//obviously incomplete
#include "../HeaderFiles/kernel32.h"
void kernel_main(){
	VGA("Kernel", 0xf, 0x1, 0);
	install_idt();
	while(1){
		asm volatile("hlt");
	}
}

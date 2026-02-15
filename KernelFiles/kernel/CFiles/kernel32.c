//i swear im not copying windows


//obviously incomplete
#include "../HeaderFiles/kernel32.h"
void kernel_main(){
	install_idt();
	VGA("Kernel :D", 0xf, 0x1, 1);
	while (1) {
		asm("hlt");
	}
}

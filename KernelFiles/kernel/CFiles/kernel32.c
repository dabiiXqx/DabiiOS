//i swear im not copying windows


//obviously incomplete, implementing IDT and attempting repairs later on.
#include "../HeaderFiles/kernel32.h"
void kernel_main(){
	install_idt();
	VGA("Kernel :D", 0xf, 0x1, 1);
}

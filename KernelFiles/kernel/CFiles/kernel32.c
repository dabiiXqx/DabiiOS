//i swear im not copying windows
#include <stdint.h>
void kernel_main(){
	volatile uint16_t* Screen = (volatile uint16_t*)0xb8000;
	const char* text = "I hate my life i hate my life i hate my life i hate the IDT";
	uint8_t fg = 0xF; // white
	uint8_t bg = 0x1; // blue
	uint16_t attr = (bg << 4) | fg; // HIGH BYTE 0001 0000 OR 00001111 = 0001(0x1) 1111 (0xf)

	// Clear screen
	for (int i = 0; i < 80 * 25; i++) {
		Screen[i] = (attr << 8) | ' ';
	}

	// Write text
	for (int i = 0; text[i] != 0; i++) {
		Screen[i] = (attr << 8) | text[i];
	}
	for(;;);
}

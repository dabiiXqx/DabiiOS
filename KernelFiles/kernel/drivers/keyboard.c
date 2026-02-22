#include "../HeaderFiles/kernel32.h"
void keyboard_handler(void) {
    int scancode = inb(0x60);
    VGA("Keyboard", 0xf, 0x1, 0);
    return;
}
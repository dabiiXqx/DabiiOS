#include "../HeaderFiles/kernel32.h"
void keyboard_handler(void) {
    //Is implemented, but will improved later, ignore for now
    VGA("Keyboard", 0xf, 0x1, 1);
}
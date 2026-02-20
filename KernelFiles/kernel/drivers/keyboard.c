#include "../HeaderFiles/kernel32.h"
void keyboard_handler() {
    //Will be implemented and improved later, ignore for now
    VGA("Keyboard", 0x1, 0xf, 1);
}
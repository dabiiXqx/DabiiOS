#include "../HeaderFiles/kernel32.h"
char scan(int scancode);

//CURRENTLY THE DRIVER IS INCOMPLETE

typedef enum {

    KEY_ESC_PRES = 0x01,
    KEY_1_PRES = 0x02,
    KEY_2_PRES = 0x03,
    KEY_3_PRES = 0x04,
    KEY_4_PRES = 0x05,
    KEY_5_PRES = 0x06,
    KEY_6_PRES = 0x07,
    KEY_7_PRES = 0x08,
    KEY_8_PRES = 0x09,
    KEY_9_PRES = 0x0A,
    KEY_0_PRES = 0x0B,
    KEY_DASH_PRES = 0x0C,
    KEY_EQUALS_PRES = 0x0D,
    KEY_BACKSPACE_PRES = 0x0E,
    KEY_TAB_PRES = 0x0F

} key_map;

void keyboard_handler(void) {
    int scancode = inb(0x60);
    char c = scan(scancode);
    putc(c, 0xf, 0x1, 0);
    pic_eoi(1);
    return;
}
char scan(int scancode){
    char c;

    switch(scancode){

        case KEY_0_PRES:
            c = 0x30;
            break;
        case KEY_1_PRES:
            c = 0x31;
            break;
        case KEY_2_PRES:
            c = 0x32;
            break;
        case KEY_3_PRES:
            c = 0x33;
            break;
        case KEY_4_PRES:
            c = 0x34;
            break;
        case KEY_5_PRES:
            c = 0x35;
            break;
        case KEY_6_PRES:
            c = 0x36;
            break;
        case KEY_7_PRES:
            c = 0x37;
            break;
        case KEY_8_PRES:
            c = 0x38;
            break;
        case KEY_9_PRES:
            c = 0x39;
            break;
        case KEY_DASH_PRES:
            c = 0x2D;
            break;
        case KEY_EQUALS_PRES:
            c = 0x3D;
            break;

        default:
            c = 0x0;
    }

    return c;
}
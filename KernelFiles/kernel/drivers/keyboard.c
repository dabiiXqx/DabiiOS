#include "../HeaderFiles/kernel32.h"
char scan(int scancode);

//CURRENTLY THE DRIVER IS INCOMPLETE

//TODO: ADD NEWLINES cursor_pos = (cursor_pos / VGA_WIDTH) * VGA_WIDTH + VGA_WIDTH

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
    KEY_TAB_PRES = 0x0F,
    KEY_Q_PRES = 0x10,
    KEY_W_PRES = 0x11,
    KEY_E_PRES = 0x12,
    KEY_R_PRES = 0x13,
    KEY_T_PRES = 0x14,
    KEY_Y_PRES = 0x15,
    KEY_U_PRES = 0x16,
    KEY_I_PRES = 0x17,
    KEY_O_PRES = 0x18,
    KEY_P_PRES = 0x19,
    KEY_OPNBRACK_PRES = 0x1A,
    KEY_CLSDBRACK_PRES = 0x1B,
    KEY_ENTR_PRES = 0x1C,
    KEY_LFTCTRL_PRES = 0x1D,
    KEY_A_PRES = 0x1E,
    KEY_S_PRES = 0x1F,
    KEY_D_PRES = 0x20,
    KEY_F_PRES = 0x21,
    KEY_G_PRES = 0x22,
    KEY_H_PRES = 0x23,
    KEY_J_PRES = 0x24,
    KEY_K_PRES = 0x25,
    KEY_L_PRES = 0x26,
    KEY_SEMICOLON_PRES = 0x27,
    KEY_SINGLEQUOTE_PRES = 0x28,
    KEY_BACKTICK_PRES = 0x29

} key_map;

void keyboard_handler(void) {
    int scancode = inb(0x60);
    char c = scan(scancode);
    putc(c, 0xf, 0x1, 0);
    pic_eoi(1);
    return;
}

//right now this function is long and i know it, i'll try to shorten it later.
char scan(int scancode){
    char c = 0;

    switch(scancode){
        
        case KEY_ESC_PRES:
            outb(0x64, 0xFE);
            break;
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
        case KEY_Q_PRES:
            c = 0x71;
            break;
        case KEY_W_PRES:
            c = 0x77;
            break;
        case KEY_E_PRES:
            c = 0x65;
            break;
        case KEY_R_PRES:
            c = 0x72;
            break;
        case KEY_T_PRES:
            c = 0x74;
            break;
        case KEY_Y_PRES:
            c = 0x79;
            break;
        case KEY_U_PRES:
            c = 0x75;
            break;
        case KEY_I_PRES:
            c = 0x69;
            break;
        case KEY_O_PRES:
            c = 0x6F;
            break;
        case KEY_P_PRES:
            c = 0x70;
            break;
        case KEY_OPNBRACK_PRES:
            c = 0x5B;
            break;
        case KEY_CLSDBRACK_PRES:
            c = 0x5D;
            break;
        case KEY_ENTR_PRES:
            c = 0x0;
            break;

        default:
            c = 0x0;
    }

    return c;
}
#include "../HeaderFiles/kernel32.h"
#include <stddef.h>
char scan(int scancode);

//THE DRIVER IS ALMOST COMPLETE, NEEDS A FEW MORE FEATURES.

//TODO: ADD KEY COMBOS

//This enum maps raw scancodes to readable labels
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
    KEY_BACKTICK_PRES = 0x29,
    KEY_LFTSHIFT_PRES = 0x2A,
    KEY_BACKSLASH_PRES = 0x2B,
    KEY_Z_PRES = 0x2C,
    KEY_X_PRES = 0x2D,
    KEY_C_PRES = 0x2E,
    KEY_V_PRES = 0x2F,
    KEY_B_PRES = 0x30,
    KEY_N_PRES = 0x31,
    KEY_M_PRES = 0x32,
    KEY_COMMA_PRES = 0x33,
    KEY_PERIOD_PRES = 0x34,
    KEY_SLASH_PRES = 0x35,
    KEY_RGHTSHIFT_PRES = 0x36,
    KEY_KEYPAD_ASTERISK_PRES = 0x37,
    KEY_LEFTALT_PRES = 0x38,
    KEY_SPACE_PRES = 0x39,
    KEY_CAPSLOCK_PRES = 0x3A,

} key_map;

void keyboard_handler(void) {
    int scancode = inb(0x60);
    char c = scan(scancode);
    console_putc(c, 0xf, 0x1, 0); //this API is defined in KernelFiles/kernel/drivers/terminal.c
    return;
}

/*This array contains all the currently supported keys of the driver. 
  It's designed in a way that it can be indexed easily using the scancode.*/
char keys[58] = {
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0, 0,
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 0, 0, 'a', 's',
    'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 'c', 'v',
    'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

//This variable is supposed to hold the numerical representation of a physical key. unused currently.
uint16_t key_id;

uint64_t key_down[2] = {0, 0};

char scan(int scancode){
    char c = 0;

    if (scancode >= sizeof(keys)){
        return 0;
    }
    else if (scancode <= 0){
        return 0;
    }

    switch(scancode){
        case KEY_ESC_PRES:
            VGA("Shutting down..", 0xf, 0x7, 1, 0);
            while(inb(0x64) & 0x02){
                io_wait();
            }
            //This does a cpu reset
            outb(0x64, 0xFE);
            break;
        case KEY_BACKSPACE_PRES:
            console_backc(0xf, 0x1); //in terminal.c
            break;
        case KEY_ENTR_PRES:
            newline(0xf, 0x1); //in terminal.c
            break;
    }

    c = keys[scancode];

    return c;
}
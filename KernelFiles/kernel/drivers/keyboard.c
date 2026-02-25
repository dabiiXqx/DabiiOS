#include "../HeaderFiles/kernel32.h"
#include <stddef.h>
char scan(int scancode);

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
            VGA("Shutting down..", 0xf, 0x7, 1, 0, 0);
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
#include "../HeaderFiles/kernel32.h"
#include <stdint.h>
#include <stdarg.h>


//trust me, i know the code is horrible. like i actually know it. i just don't know any "good" ways to code ig
//i've been reading The c programming language, and im actually learning
//i'll be coding better soon :)


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VGA STUFF!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int cursor[2] = {0, 0}; //[0] is row [1] is column
volatile uint16_t* VGA_base = (volatile uint16_t*)0xb8000;

_Bool prompt_valid = 1;

static void scroll();
void clear_screen(uint16_t attr);
void do_cursor(int index);

void console_putc(char c, uint8_t fg, uint8_t bg){
    int index = get_index();
    uint16_t attr = (bg << 4) | fg;
    if(c == 0){
        return;
    }
    VGA_base[index] = (attr << 8) | c;
    cursor[1]++;
    if(cursor[1] >= 80){
        cursor[1] = 0;
        cursor[0]++;
        prompt_valid = 0;
        if(cursor[0] >= 25){
            scroll();
            for(int i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_FULL; i++){
                VGA_base[i] = (attr << 8) | ' ';
            }
            prompt_valid = 0;
            cursor[0] = 24;
        }
    }
    do_cursor(index + 1);
}


/*_______________________________________________________________________________________________*/


void VGA(const char* text, uint8_t fg, uint8_t bg) {
    int i;
    i = 0;
    while(text[i] != '\0'){
        console_putc(text[i++], fg, bg);
    }
}

void console_backc(uint8_t fg, uint8_t bg){
    uint16_t attr = (bg << 4) | fg;
    int index = get_index();
    cursor[1]--;
    if(cursor[1] < 8 && prompt_valid == 1){
        cursor[1] = 8;
        if (cursor[0] < 0){
            cursor[0] = 0;
        }
    }
    else if(index <= 0){
        cursor[0]= 0;
        cursor[1] = 0;
        index = get_index();
    }
    else{
        index--;
        VGA_base[index] = (attr << 8) | ' ';
    }
    do_cursor(index);
    return;
}

void newline(uint8_t fg, uint8_t bg){
    uint16_t attr = (bg << 4) | fg;
    prompt_valid = 1;
    int index = get_index();
    cursor[0]++;
    cursor[1] = 0;
    if(cursor[0] >= 25){
        scroll();
        for(int i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_FULL; i++){
            VGA_base[i] = (attr << 8) | ' ';
        }
        cursor[0] = 24;
    }
    kprintf("Kernel> ");
    cursor[1] = 8;

    index = get_index();
    do_cursor(index);
    return;
}


/*_______________________________________________________________________________________________*/


static void scroll(){
    for(int i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++){
        VGA_base[i] = VGA_base[i + 80];
    }
}

void clear_screen(uint16_t attr){
    for (int i = 0; i < VGA_FULL; i++) {
        VGA_base[i] = (attr << 8) | ' ';
    }
}

void do_cursor(int index){
    outb(0x3D4, 0x0F); //Selects index CRTC register and tells it we will give 0x0f (cursor low byte)
    outb(0x3D5, index & 0xFF); // we give the data register index low byte

    outb(0x3D4, 0x0E); //Selects same register, but we want the cursor high byte now.
    outb(0x3D5, (index >> 8) & 0xFF);
}

/*_______________________________________________________________________________________________*/

/* kprintf can be used for formatted output and uses the default color scheme (0x1f) */
/*Unlike VGA, where you can choose a custom color scheme, but can't format output.*/

int kprintf(char *fmt, ...){
    va_list ap;

    char *p, *sval, temp[32];
    char c;
    int ival;
    unsigned int uival;

    va_start(ap, fmt);
    for(p = fmt; *p; p++){
        if(*p != '%'){
            console_putc(*p, 0xf, 0x1);
            continue;
        }
        switch(*++p){
            case 'd':
                ival = va_arg(ap, int);
                itoa(ival, temp);
                VGA(temp, 0xf, 0x1);
                kmemset(temp, 0, sizeof temp);
                break;
            case 's':
                sval = va_arg(ap, char*);
                VGA(sval, 0xf, 0x1);
                break;
            case 'x':
                uival = va_arg(ap, unsigned int);
                itox(uival, temp);
                VGA(temp, 0xf, 0x1);
                kmemset(temp, 0, sizeof temp);
                break;
            case 'c':
                c = (char)va_arg(ap, int);
                console_putc(c, 0xf, 0x1);
                break;
            default:
                VGA("Invalid format specifier", 0xf, 0x1);
        }
    }

    va_end(ap);
    return 0;
}
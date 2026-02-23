#include "../HeaderFiles/kernel32.h"
#include <stdint.h>

#define PIT_HZ 1193182

volatile uint64_t ticks;

void timer(void){
    ticks += 1;
}
void pit_init(void){
    ticks = 0;
    volatile uint16_t divisor = PIT_HZ / 100;
    outb(0x43, 0x36); //0x36 = 0011 0110
    outb(0x40, (uint8_t)(divisor & 0xff));
    outb(0x40, (uint8_t)((divisor >> 8) & 0xff));
}
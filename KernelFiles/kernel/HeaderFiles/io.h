#pragma once

#include <stdint.h>

static inline void outb(uint16_t port, uint8_t value){
    asm volatile("outb %b0, %w1" :: "a"(value), "Nd"(port) : "memory");
}

static inline uint8_t inb(uint16_t port){
    uint8_t value = 0;
    asm volatile("inb %w1, %b0" : "=a"(value) : "Nd"(port) : "memory");
    return value;
}

static inline void io_wait(){
    outb(0x80, 0);
}
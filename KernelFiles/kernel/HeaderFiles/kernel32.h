#pragma once

#define halt() while(1) { asm volatile("hlt"); }

#include "../HeaderFiles/io.h"
#include "../HeaderFiles/idt.h"
#include "../drivers/driverHeader/terminal.h"
#include "../drivers/driverHeader/timer.h"
#include "../HeaderFiles/util.h"
#include "../drivers/driverHeader/keyboard.h"

void kernel_main(void);
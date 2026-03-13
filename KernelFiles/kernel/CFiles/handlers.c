#include "../HeaderFiles/kernel32.h"
#include "../HeaderFiles/handlers.h"

typedef void (*Handlers)(void);

const char* emsg[32] = {
    "Division By Zero", // 0
    "Debug", // 1
    "Non Maskable Interrupt", // 2
    "Breakpoint", // 3
    "Overflow", // 4
    "Bound Range Exceeded", // 5
    "Invalid Opcode", // 6
    "Device Not Available", // 7
    "Double Fault", // 8
    "Coprocessor Segment Overrun", // 9
    "Invalid TSS", // 10
    "Segment Not Present", // 11
    "Stack-Segment fault", // 12
    "General Protection Fault", // 13
    "Page Fault", // 14
    "Reserved", // 15
    "x87 FPU Floating-Point Error", // 16
    "Alignment Check", // 17
    "Machine Check", // 18
    "SIMD Floating-Point Exception", // 19
    "Virtualization Exception", // 20
    "Control Protection Exception", // 21
    "Reserved", // 22
    "Reserved", // 23
    "Reserved", // 24
    "Reserved", // 25
    "Reserved", // 26
    "Reserved", // 27
    "Reserved", // 28
    "Reserved",	// 29
    "Reserved", // 30
    "Reserved", // 31
};

void DE_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[0], 0xf, 0x7);
	halt();
}

void DB_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[1], 0xf, 0x7);
	halt();
}

void NMI_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[2], 0xf, 0x7);
	halt();
}

void BP_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[3], 0xf, 0x7);
	halt();
}

void OF_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[4], 0xf, 0x7);
	halt();
}

void BR_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[5], 0xf, 0x7);
	halt();
}

void UD_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[6], 0xf, 0x7);
	halt();

}

void NM_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[7], 0xf, 0x7);
	halt();

}

void DF_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[8], 0xf, 0x7);
	halt();
}

void CSO_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[9], 0xf, 0x7);
	halt();
}

void TS_exception(){
	VGA(emsg[10], 0xf, 0x7);
	halt();
}

void NP_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[11], 0xf, 0x7);
	halt();
}

void SS_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[12], 0xf, 0x7);
	halt();
}

void GP_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[13], 0xf, 0x7);
	halt();
}

void PF_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[14], 0xf, 0x7);
	halt();
}

void res15_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[15], 0xf, 0x7);
	halt();
}

void MF_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[16], 0xf, 0x7);
	halt();
}

void AC_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[17], 0xf, 0x7);
	halt();
}

void MC_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[18], 0xf, 0x7);
	halt();
}

void XM_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[19], 0xf, 0x7);
	halt();
}

void VE_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[20], 0xf, 0x7);
	halt();
}

void CP_exception(){ //CP doesn't mean CSAM material here, it's an exception mnemonic.
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[21], 0xf, 0x7);
	halt();
}

void res22_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[22], 0xf, 0x7);
	halt();
}

void res23_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[23], 0xf, 0x7);
	halt();
}

void res24_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[24], 0xf, 0x7);
	halt();
}

void res25_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[25], 0xf, 0x7);
	halt();
}

void res26_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[26], 0xf, 0x7);
	halt();
}

void res27_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[27], 0xf, 0x7);
	halt();
}

void res28_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[28], 0xf, 0x7);
	halt();
}

void res29_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[29], 0xf, 0x7);
	halt();
}

void res30_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[30], 0xf, 0x7);
	halt();
}

void res31_exception(){
	clear_screen(0x7f);
	set_index(0, 0);
	VGA(emsg[31], 0xf, 0x7);
	halt();
}
//IRQ FUNCTIONS HERE
void irq0_int(){
	timer();
	pic_eoi(0);
	return;
}
void irq1_int(){
	keyboard_handler();
	pic_eoi(1);
	return;
}

Handlers func_table[34] = {
	DE_exception,
	DB_exception,
	NMI_exception,
	BP_exception,
	OF_exception,
	BR_exception,
	UD_exception,
	NM_exception,
	DF_exception,
	CSO_exception,
	TS_exception,
	NP_exception,
	SS_exception,
	GP_exception,
	PF_exception,
	res15_exception,
	MF_exception,
	AC_exception,
	MC_exception,
	XM_exception,
	VE_exception,
	CP_exception,
	res22_exception,
	res23_exception,
	res24_exception,
	res25_exception,
	res26_exception,
	res27_exception,
	res28_exception,
	res29_exception,
	res30_exception,
	res31_exception,
	irq0_int,
	irq1_int
};
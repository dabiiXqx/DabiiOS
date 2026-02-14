#include "../headerFiles/kernel32.h"
typedef void (*Handlers)(void);
//Now handlers are valid, but dont do anything. in beta phase
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
	VGA(emsg[0], 0xf, 0x7, 1);
}

void DB_exception(){
	VGA(emsg[1], 0xf, 0x7, 1);
}

void NMI_exception(){
	VGA(emsg[2], 0xf, 0x7, 1);
}

void BP_exception(){
	VGA(emsg[3], 0xf, 0x7, 1);
}

void OF_exception(){
	VGA(emsg[4], 0xf, 0x7, 1);
}

void BR_exception(){
	VGA(emsg[5], 0xf, 0x7, 1);
}

void UD_exception(){
	VGA(emsg[6], 0xf, 0x7, 1);
}

void NM_exception(){
	VGA(emsg[7], 0xf, 0x7, 1);
}

void DF_exception(){
	VGA(emsg[8], 0xf, 0x7, 1);
}

void CSO_exception(){
	VGA(emsg[9], 0xf, 0x7, 1);
}

void TS_exception(){
	VGA(emsg[10], 0xf, 0x7, 1);
}

void NP_exception(){
	VGA(emsg[11], 0xf, 0x7, 1);
}

void SS_exception(){
	VGA(emsg[12], 0xf, 0x7, 1);
}

void GP_exception(){
	VGA(emsg[13], 0xf, 0x7, 1);
}

void PF_exception(){
	VGA(emsg[14], 0xf, 0x7, 1);
}

void res15_exception(){
	VGA(emsg[15], 0xf, 0x7, 1);
}

void MF_exception(){
	VGA(emsg[16], 0xf, 0x7, 1);
}

void AC_exception(){
	VGA(emsg[17], 0xf, 0x7, 1);
}

void MC_exception(){
	VGA(emsg[18], 0xf, 0x7, 1);
}

void XM_exception(){
	VGA(emsg[19], 0xf, 0x7, 1);
}

void VE_exception(){
	VGA(emsg[20], 0xf, 0x7, 1);
}

void CP_exception(){ //CP doesn't mean CSAM material here, it's an exception mnemonic.
	VGA(emsg[21], 0xf, 0x7, 1);
}

void res22_exception(){
	VGA(emsg[22], 0xf, 0x7, 1);
}

void res23_exception(){
	VGA(emsg[23], 0xf, 0x7, 1);
}

void res24_exception(){
	VGA(emsg[24], 0xf, 0x7, 1);
}

void res25_exception(){
	VGA(emsg[25], 0xf, 0x7, 1);
}

void res26_exception(){
	VGA(emsg[26], 0xf, 0x7, 1);
}

void res27_exception(){
	VGA(emsg[27], 0xf, 0x7, 1);
}

void res28_exception(){
	VGA(emsg[28], 0xf, 0x7, 1);
}

void res29_exception(){
	VGA(emsg[29], 0xf, 0x7, 1);
}

void res30_exception(){
	VGA(emsg[30], 0xf, 0x7, 1);
}

void res31_exception(){
	VGA(emsg[31], 0xf, 0x7, 1);
}
Handlers func_table[32] = {
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
};



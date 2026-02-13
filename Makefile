VERSION=4.0.3

CC=x86_64-elf-gcc
LD=x86_64-elf-ld
NASM=nasm
OBJCOPY=x86_64-elf-objcopy
CFLAGS = -m32 \
	-mno-sse \
	-mno-sse2 \
	-mno-mmx \
	-msoft-float \
	-g \
	-I KernelFiles/kernel/HeaderFiles \
	-ffreestanding \
	-nostdlib \
	-fno-stack-protector \
	-c \
	-fno-pie

C_SOURCES:=$(wildcard KernelFiles/kernel/CFiles/*.c)
C_OBJECTS:= $(C_SOURCES:.c=.o)

ASM_SOURCES:= $(wildcard KernelFiles/kernel/Assembly/*.asm)
ASM_OBJECTS:= $(ASM_SOURCES:.asm=.o)

OBJECTS:= $(C_OBJECTS) $(ASM_OBJECTS)

default: all

all: kernel

KernelFiles/kernel/CFiles/%.o: KernelFiles/kernel/CFiles/%.c
	$(CC) $(CFLAGS) $< -o $@

KernelFiles/kernel/Assembly/%.o: KernelFiles/kernel/Assembly/%.asm
	$(NASM) -f elf32 $< -o $@

kernel: $(OBJECTS)
	$(LD) -m elf_i386 -nostdlib -T KernelFiles/kernel/LinkerScript/linker.ld -o kernel32.elf $(OBJECTS)
	$(OBJCOPY) -O binary kernel32.elf bin/kernel32.bin

boot:
	$(NASM) -f bin boot.asm -o bin/boot.bin
disk:
	dd if=/dev/zero of=disk.img bs=1M count=8
	dd if=bin/boot.bin of=disk.img bs=512 count=1 conv=notrunc
	dd if=bin/kernel32.bin of=disk.img bs=512 seek=1 count=7 conv=notrunc
clean:
	rm -f KernelFiles/kernel/Assembly/*.o
	rm -f KernelFiles/kernel/CFiles/*.o

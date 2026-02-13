[bits 16]
org 0x7c00
KERNELOC equ 0x9000

xor ax, ax
mov es, ax
mov fs, ax
mov ss, ax
mov sp, 0x7c00
mov bp, sp

in al, 0x92
or al, 00000010b
out 0x92, al

mov bx, KERNELOC
mov ah, 0x02
mov al, 7
mov ch, 0
mov dh, 0
mov cl, 2
mov dl, 0x80
int 0x13
jc disk_error
jmp clear
disk_error:
    mov ah, 0x0e
    mov al, 'B'
    int 0x10
    hlt
clear:
    mov ah, 0x0
    mov al, 0x03
    int 0x10
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

cli
lgdt[gdt_desc]
mov eax, cr0
or eax, 1
mov cr0, eax
jmp CODE_SEG:protect

gdt_start:
    gdt_null:
        dd 00
        dd 00
    gdt_code:
        dw 0xffff
        dw 0x0
        db 0x0
        db 10011010b
        db 11001111b
        db 0x0
    gdt_data:
        dw 0xffff
        dw 0x0
        db 0x0
        db 10010010b
        db 11001111b
        db 0x0
    gdt_end:

    gdt_desc:
        dw gdt_end - gdt_start - 1
        dd gdt_start

    [bits 32]
    protect:
        mov ax, DATA_SEG
        mov ds, ax
        mov ss, ax
        mov es, ax
        mov fs, ax
        mov gs, ax


        mov ebp, 0x90000
        mov esp, ebp

        jmp 0x9000

times 510-($-$$) db 0
dw 0xaa55

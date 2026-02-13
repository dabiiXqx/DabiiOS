global load_idt
extern idtp
load_idt:
    lidt [idtp]
    ret

%macro ISR_ERR 1
global idt_err%1
idt_err%1:
    push %1
    jmp isr_common_stub
%endmacro

%macro ISR_NOERR 1
global idt_noerr%1
idt_noerr%1:
    push 0
    push %1
    jmp isr_common_stub
%endmacro

extern dummy_handler

ISR_NOERR 0
ISR_NOERR 1
ISR_NOERR 2
ISR_NOERR 3
ISR_NOERR 4
ISR_NOERR 5
ISR_NOERR 6
ISR_NOERR 7
ISR_ERR 8
ISR_NOERR 9
ISR_ERR 10
ISR_ERR 11
ISR_ERR 12
ISR_ERR 13
ISR_ERR 14
ISR_NOERR 15
ISR_NOERR 16
ISR_ERR 17
ISR_NOERR 18
ISR_NOERR 19
ISR_NOERR 20
ISR_ERR 21
ISR_NOERR 22
ISR_NOERR 23
ISR_NOERR 24
ISR_NOERR 25
ISR_NOERR 26
ISR_NOERR 27
ISR_NOERR 28
ISR_NOERR 29
ISR_NOERR 30
ISR_NOERR 31

isr_common_stub:
    pushad
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    jmp dummy_handler

    popad
    iret


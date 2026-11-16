
; AditiOS boot entry

BITS 32

section .multiboot
align 4

MAGIC    equ 0x1BADB002
FLAGS    equ 0x00000003
CHECKSUM equ -(MAGIC + FLAGS)

dd MAGIC
dd FLAGS
dd CHECKSUM

section .text
global _start
extern aditi_kernel

_start:
    cli

    mov esp, stack_top
    and esp, 0xFFFFFFF0

    xor ebp, ebp

    ; Enter C kernel
    call aditi_kernel

.hang:
    hlt
    jmp .hang

section .bss
align 16

stack_bottom:
    resb 16384
stack_top:

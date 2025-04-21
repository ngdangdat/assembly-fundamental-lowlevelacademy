.global _start
.section .text

_start:
    mov r0, pc
    sub r0, r0, #8
    bx r0

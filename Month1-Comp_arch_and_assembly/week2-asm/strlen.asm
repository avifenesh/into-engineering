%include "common.inc"
; size_t my_strlen(const char *s);
; rdi: pointer to string; return in rax
global G(my_strlen)
section .text
G(my_strlen):
    mov rax, rdi
.loop:
    cmp byte [rax], 0
    je .done
    inc rax
    jmp .loop
.done:
    sub rax, rdi
    ret

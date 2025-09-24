%include "common.inc"
; int add(int a, int b);
; SysV AMD64: a in edi, b in esi, return in eax
global G(add)
section .text
G(add):
    mov eax, edi
    add eax, esi
    ret

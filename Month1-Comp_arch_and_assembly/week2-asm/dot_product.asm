%include "common.inc"
; float dot_product(const float* a, const float* b, int n);
; rdi=a, rsi=b, edx=n; return xmm0
global G(dot_product)
section .text
G(dot_product):
    pxor xmm0, xmm0        ; sum = 0.0
    test edx, edx
    jle .ret
.loop:
    movss xmm1, [rdi]
    mulss xmm1, [rsi]
    addss xmm0, xmm1
    add rdi, 4
    add rsi, 4
    dec edx
    jg .loop
.ret:
    ret

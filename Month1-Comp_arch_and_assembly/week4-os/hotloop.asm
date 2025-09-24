%ifdef DARWIN
  %define G(x) _ %+ x
%else
  %define G(x) x
%endif
; int mem_has(const char* hay, int hlen, const char* needle, int nlen);
; returns 1 if found, else 0
; rdi=hay, rsi=hlen, rdx=needle, rcx=nlen

global G(mem_has)
section .text
G(mem_has):
    test rcx, rcx
    jle .notfound
    test rsi, rsi
    jle .notfound
    mov r8, rsi
    sub r8, rcx
    jl .notfound
    xor r9, r9            ; i = 0
.outer:
    xor r10, r10          ; j = 0
.inner:
    mov al, [rdi + r9 + r10]
    cmp al, [rdx + r10]
    jne .next_i
    inc r10
    cmp r10, rcx
    jl .inner
    mov eax, 1
    ret
.next_i:
    inc r9
    cmp r9, r8
    jle .outer
.notfound:
    xor eax, eax
    ret

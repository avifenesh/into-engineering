; void sys_exit(int code);
; Linux x86-64: rdi=code; rax=60 (SYS_exit)

global sys_exit
section .text
sys_exit:
    mov rax, 60
    syscall
    hlt

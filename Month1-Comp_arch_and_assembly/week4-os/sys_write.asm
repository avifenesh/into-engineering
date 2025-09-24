; ssize_t sys_write(int fd, const void* buf, size_t len);
; Linux x86-64: rdi=fd, rsi=buf, rdx=len; rax=1 (SYS_write)
; NOTE: Linux only. macOS uses different syscall numbers.

global sys_write
section .text
sys_write:
    mov rax, 1
    syscall
    ret

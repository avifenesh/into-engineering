#include <stddef.h>
#include <stdint.h>
ssize_t sys_write(int fd, const void* buf, size_t len);
void sys_exit(int code);
int main(void){
    const char msg[] = "Hello via raw syscalls\n";
    sys_write(1, msg, sizeof(msg)-1);
    sys_exit(0);
    return 0;
}

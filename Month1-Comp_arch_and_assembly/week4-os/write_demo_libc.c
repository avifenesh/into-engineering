#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    const char msg[] = "Hello via libc write() (macOS)\n";
    write(1, msg, (size_t)strlen(msg));
    return 0;
}

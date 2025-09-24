#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int mem_has(const char* hay, int hlen, const char* needle, int nlen);

int main(int argc, char** argv){
    if(argc < 3){ fprintf(stderr, "Usage: %s <needle> <file>\n", argv[0]); return 2; }
    const char* needle = argv[1];
    int nlen = (int)strlen(needle);

    int fd = open(argv[2], O_RDONLY);
    if(fd < 0){ perror("open"); return 1; }

    const int B = 8192; // 8 KiB chunk
    char *buf = (char*)malloc(B);
    if(!buf){ perror("malloc"); close(fd); return 1; }

    ssize_t r;
    while((r = read(fd, buf, B)) > 0){
        if(mem_has(buf, (int)r, needle, nlen)) {
            write(1, buf, (size_t)r);
        }
    }
    if(r < 0) perror("read");
    free(buf);
    close(fd);
    return 0;
}

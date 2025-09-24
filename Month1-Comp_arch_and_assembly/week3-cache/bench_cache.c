#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>

static void* aligned_malloc(size_t align, size_t size){
    void* p = NULL;
    if (posix_memalign(&p, align, size) != 0) return NULL;
    return p;
}

static double now_s(void){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec/1e9;
}

int main(int argc, char** argv){
    int n = (argc > 1) ? atoi(argv[1]) : 2048;
    int stride_col = (argc > 2) ? atoi(argv[2]) : 1;
    int i, j;
    double t;

    int **a = malloc((size_t)n * sizeof(*a));
    if (!a) {
        perror("malloc");
        return 1;
    }

    for (i = 0; i < n; i++) {
        a[i] = (int*)aligned_malloc(64, (size_t)n * sizeof(int));
        if (!a[i]) {
            perror("aligned_malloc");
            while (i-- > 0) free(a[i]);
            free(a);
            return 1;
        }
        for (j = 0; j < n; j++) {
            a[i][j] = i + j;
        }
    }

    volatile long long sum = 0;
    t = now_s();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum += a[i][j];
        }
    }
    double row = now_s() - t;

    t = now_s();
    for (j = 0; j < n; j += stride_col) {
        for (i = 0; i < n; i++) {
            sum += a[i][j];
        }
    }
    double col = now_s() - t;

    printf("n=%d stride_col=%d row=%.6f s col=%.6f s sink=%lld\n", n, stride_col, row, col, sum);

    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}

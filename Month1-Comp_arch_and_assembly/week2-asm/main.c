#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

int add(int a, int b);
size_t my_strlen(const char *s);
float dot_product(const float* a, const float* b, int n);

int main(void) {
    printf("add(2,3) = %d\n", add(2,3));
    const char *s = "hello";
    printf("my_strlen('hello') = %zu\n", my_strlen(s));
    float a[4] = {1,2,3,4}, b[4] = {4,3,2,1};
    printf("dot_product = %.2f\n", dot_product(a,b,4));
    return 0;
}

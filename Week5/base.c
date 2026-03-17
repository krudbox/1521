#include <stdio.h>

int main(void) {

    int a = 255;
    int b = 0xFF;
    int c = 0377;
    int d = 0b11111111;

    printf("%d %d %d %d\n", a, b, c, d);
    printf("%x %x %x %x\n", a, b, c, d);
    printf("%o %o %o %o\n", a, b, c, d);

    return 0;
}
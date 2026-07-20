#include <stdio.h>
#include <stdint.h>


int main(void) {
    uint32_t input;
    scanf("%d", &input);

    uint32_t mask2 = 0x3F << 14;
    uint32_t r = input & mask2;
    uint32_t x = r >> 14;

}
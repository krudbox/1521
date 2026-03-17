#include <stdio.h>
#include <stdint.h>


int main(void) {
  uint32_t input;
  scanf("%d", &input);

  // TODO: extract miidle 6 bits 32b int
  uint32_t mask = 0b111111;
  mask = mask << 14;
  uint32_t result = input & mask;
  result = result >> 14;

  return 0;
}
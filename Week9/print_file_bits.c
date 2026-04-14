#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("");
    exit(1);
  }

  int32_t x;
  while (fscanf(f, "%x", &x) == 1) {
    int8_t b = x & 0xff;
    printf("%d\n", b);
  }

  fclose(f);


  return 0;
}
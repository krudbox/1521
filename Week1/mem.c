/**
 *
 * Determine the memory layout of the following program!
 *
 */

#include <stdio.h>
#include <stdlib.h>

int x = 5;

int *square(int n);

int main(int argc, char *argv[]) {
  int n = strtol(argv[1], NULL, 10);
  int i = 0;
  while (i <= n) {
    int *squared = square(i);

    printf("%d * %d = %d\n", i, i, *squared);

    i++;
    free(squared);
  }

  return 0;
}

int *square(int n) {
  int *s = malloc(sizeof(int));
  *s = n * n;

  return s;
}

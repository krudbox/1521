#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect number of arguments\n");
    exit(1);
  }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("");
    exit(1);
  }

  int c;
  c = fgetc(f);
  int count = 0;
  while (c != EOF && c != '\n') {
    printf("%c", c);
    c = fgetc(f);
  }

  printf("\n");

  fclose(f);

  return 0;
}
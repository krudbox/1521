/* Writes one line of input from stdin to a provided file */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  // Command line argument usage: ./write_line [filepath]
  if (argc != 2) {
    fprintf(stderr, "Incorrect number of arguments\n");
    exit(1);
  }

  // Opens file
  FILE *f = fopen(argv[1], "w");
  if (f == NULL) {
    perror("");
    exit(1);
  }

  // Reads 1 byte at a time from stdin and writes to the open file
  int c = fgetc(stdin); // Could equivalently use scanf("%c", &c)
  while (c != EOF && c != '\n') {
    fputc(c, f);
    c = fgetc(stdin);
  }

  // Closes file
  if (fclose(f) != 0) {
    perror("");
    exit(1);
  }

  return 0;
}

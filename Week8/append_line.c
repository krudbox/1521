#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect number of arguments\n");
    exit(1);
  }




  FILE *f = fopen(argv[1], "r+");
  if (f == NULL) {
    perror("");
    exit(1);
  }

  fseek(f, 0, SEEK_END);

  char c;
  scanf("%c", &c);
  while (c != '\n') {
    fputc(c, f);
    scanf("%c", &c);
  }

  fclose(f);


  return 0;
}
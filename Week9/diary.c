#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
  char *home = getenv("HOME");
  if (home == NULL) {
    perror("Could not find home: ");
    exit(1);
  } else {
    printf("HOME: %s\n", home);
  }

  char *filename = ".diary";

  int pathBufferSize = strlen(home) + 1 + strlen(filename) + 1;
  char *pathBuffer = malloc(sizeof(char) * pathBufferSize);
  snprintf(pathBuffer, pathBufferSize, "%s/%s", home, filename);

  printf("Attempting to open file %s\n", pathBuffer);
  FILE *f = fopen(pathBuffer, "r");
  if (f == NULL) {
    perror("");
    exit(1);
  }

  int c;
  while ((c = fgetc(f)) != EOF) {
    putchar(c);
  }

  putchar('\n');
  fclose(f);

  return 0;
}


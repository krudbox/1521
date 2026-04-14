#include <stdio.h>

int main(int argc, char *argv[]) {
  int count = 0;

  int i = 0;
  char c = argv[1][i];
  while (c != '\0') {
    if (!((c >> 7) & 1)) {
      count++;
      i++;
      continue;
    }

    if ((c >> 5 & 0b111) == 06) {
      count++;
      i += 2;
    }

    if ((c >> 4 & 0b1111) == 0xe) {
      count++;
      i += 3;
    }

    if ((c >> 3 & 0b11110) == 0b11110) {
      count++;
      i += 4;
    }

    c = argv[1][i];
  }

  printf("there are %d codepoints in the string\n", count);


  return 0;
}
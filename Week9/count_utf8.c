/* Counts the number of UTF-8 codepoints in a unicode string parsed as a command line argument */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Command line arguments should be: ./count_utf8 [utf8_string]
  if (argc != 2) {
    fprintf(stderr, "Incorrect number of arguments\n");
    exit(1);
  }

  int count = 0; // Counter for code codepoints
  int i = 0; // String index
  char *s = argv[1];
  while (s[i] != '\0') {
    char primary_byte = s[i];
    int num_secondary_bytes = 0;
    if ((primary_byte & 0x80) == 0x00) {
      num_secondary_bytes = 0;
    } else if ((primary_byte & 0xD0) == 0xC0)  {
      num_secondary_bytes = 1;
    } else if ((primary_byte & 0xF0) == 0xD0) {
      num_secondary_bytes = 2;
    } else if ((primary_byte & 0xF8) == 0xF0) {
      num_secondary_bytes = 3;
    } else {
      fprintf(stderr, "Invalid UTF-8 string\n");
      exit(1);
    }

    i += (num_secondary_bytes + 1);
    count++;
  }

  printf("there are %d codepoints in the string\n", count);

  return 0;
}

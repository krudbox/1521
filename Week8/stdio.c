#include <fcntl.h>
#include <stdio.h>

int main(void) {
  // Open System call
  FILE *fp = fopen("hello.txt", "w");

  // Write System call
  char toWrite[6] = "boom";
  fwrite(toWrite, 1, 5, fp);

  // Close System call
  fclose(fp);

  return 0;
}


int f1() {
  FILE *fp = fopen("hello.txt", "w");

  // Writes 1 character at a time
  char toWrite[6] = "boom";
  for (int i = 0; i < 6; i++) {
    fputc(toWrite[i], fp);
  }

  fclose(fp);
  return 0;

}


int f2() {
  FILE *fp = fopen("hello.txt", "w");

  // Writes 1 character at a time
  char toWrite[6] = "boom";
  for (int i = 0; i < 6; i++) {
    putc(toWrite[i], fp);
  }

  fclose(fp);
  return 0;

}


int f3() {
  FILE *fp = fopen("hello.txt", "w");

  // Writes all characters together
  char toWrite[6] = "boom";
  fputs(toWrite, fp);

  fclose(fp);
  return 0;

}

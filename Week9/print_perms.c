#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  struct stat s;
  stat(argv[1], &s);

  printf("%b\n", s.st_mode);


  // 1. Using Macros
  if (S_ISREG(s.st_mode)) {
    printf("1. Is a regular file\n");
  }


  // 2. Using Masks
  if ((s.st_mode & __S_IFMT) == __S_IFREG) {
    printf("2. Is a regular file\n");
  }

  return 0;
}
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    struct stat s;
    if (stat(argv[i], &s) == -1) {
      perror("");
      continue;
    }

    mode_t perms = s.st_mode;
    if ((perms & S_IWOTH)) {
      perms = perms & ~S_IWOTH;
    }

    if (chmod(argv[i], perms) == -1) {
      printf("couldnt change perms for %s\n", argv[i]);
    } else {
      printf("removed writable perms for %s\n", argv[i]);
    }

  }


  return 0;
}
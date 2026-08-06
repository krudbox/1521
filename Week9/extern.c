#include <stdio.h>
#include <spawn.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>

extern char **environ;

int main(void){
  int i = 0;
  for (char *s = environ[i]; s != NULL; s = environ[++i]) {
    printf("%s\n", s);
  }
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
  printf("My PID is (%d)\n", getpid());
  printf("My parent's PID is (%d)\n", getppid());
  sleep(20);

  return 0;
}

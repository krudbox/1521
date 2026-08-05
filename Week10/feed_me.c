#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *data) {
  while (true) {
    printf("feed me input!\n");
    sleep(1);
  }

  return NULL;
}

int main(void) {
  pthread_t thread;
  pthread_create(&thread, NULL, thread_run, NULL);

  char line[1024];
  while (fgets(line, sizeof line, stdin)) {
    printf("you entered: %s", line);
  }

  pthread_join(thread, NULL);
  return 0;
}
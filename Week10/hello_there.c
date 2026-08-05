#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void *hello(void *arg) {
    char *msg = (char *)arg;

    while (1) {
        printf("%s\n", msg);
    }
}



int main() {
    pthread_t threadBuff;

    pthread_create(&threadBuff, NULL, hello, "hello");
    while (1) {
        printf("there\n");
    }
    
    pthread_join(threadBuff, NULL);

  


    return 0;
}

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

long counter = 0;



void *increment_counter(void *data) {
    long *n = (long *)data;
    for (int i = 0; i < *n; i++) {
        counter++;
    }

    return NULL;
}



int main(void) {
    pthread_t hi;
    long n = 10000000000;
    pthread_create(&hi, NULL, &increment_counter, (void *)&n);
    sleep(1);
    printf("The value of counter is %ld. We are off by %ld\n", counter, n - counter);
    
}

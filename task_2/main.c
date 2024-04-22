// Программа, которая имитирует последовательный цикл и инкрементирует его с использованием мьютекса

#include <stdio.h>
#include <pthread.h>
#include "increment.h"

int counter = 0; // Инициализация глобальной переменной counter
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for(t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, increment_loop, NULL);
        if (rc) {
            printf("Error: cant create thread %ld\n", t);
            return -1;
        }
    }

    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Counter value after all threads have executed: %d\n", counter);

    return 0;
}

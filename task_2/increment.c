#include "increment.h"
#include <stdio.h>

void *increment_loop(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(&mutex); // Блокируем мьютекс перед доступом к counter
        counter++; 
        pthread_mutex_unlock(&mutex); // Разблокируем мьютекс после доступа к counter
    }
    pthread_exit(NULL);
}

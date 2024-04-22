//Программа, которая создает 5 потоков, каждый из которых выводит свой индекс

#include <stdio.h>
#include <pthread.h>
#include "threads.h"

#define NUM_THREADS 5

int main() {
    pthread_t threads[NUM_THREADS]; 
    int rc; 
    long t; 

    // Создание и запуск потоков
    for(t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        // Вызов функции создания потока, передача функции print_index в качестве аргумента
        // и передача индекса потока в качестве аргумента функции print_index
        rc = pthread_create(&threads[t], NULL, print_index, (void *)t);
        if (rc) {
            // Если создание потока завершилось ошибкой, выводим сообщение об ошибке
            printf("Error: cant create new thread %ld\n", t);
            return -1;
        }
    }

    // Ожидание завершения всех созданных потоков
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_exit(NULL); // Завершение главного потока
}

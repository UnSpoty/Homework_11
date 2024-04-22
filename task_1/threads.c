#include <stdio.h>
#include <pthread.h>
#include "threads.h"

void *print_index(void *thread_id) {
    long tid;
    tid = (long)thread_id;
    printf("thread: %ld\n", tid);
    pthread_exit(NULL);
}

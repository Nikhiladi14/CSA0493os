#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    printf("Thread %d is running.\n", thread_id);
    sleep(1);
    printf("Thread %d finished.\n", thread_id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    pthread_create(&thread1, NULL, thread_function, &id1);
    pthread_create(&thread2, NULL, thread_function, &id2);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread exiting.\n");

    return 0;
}

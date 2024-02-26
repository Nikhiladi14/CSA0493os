#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    pthread_t tid = pthread_self();
    printf("Inside thread, thread ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    // Check if thread IDs are equal
    if (pthread_equal(thread1, thread2))
        printf("Thread IDs are equal.\n");
    else
        printf("Thread IDs are not equal.\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

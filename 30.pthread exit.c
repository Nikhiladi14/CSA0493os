#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    printf("Thread is running.\n");
    sleep(1);
    printf("Thread is exiting.\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, thread_function, NULL);

    // Main thread continues while the other thread is running
    printf("Main thread continuing...\n");
    sleep(2);

    printf("Main thread exiting.\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

sem_t mutex, wrt;
int data = 0, readers_count = 0;

void *reader(void *arg) {
    int reader_id = *((int *)arg);
    while (1) {
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);

        printf("Reader %d reads data: %d\n", reader_id, data);
        sleep(1);

        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);

        // Sleep for a random time
        usleep(rand() % 1000000);
    }
    return NULL;
}

void *writer(void *arg) {
    int writer_id = *((int *)arg);
    while (1) {
        sem_wait(&wrt);
        data++;
        printf("Writer %d writes data: %d\n", writer_id, data);
        sem_post(&wrt);

        // Sleep for a random time
        usleep(rand() % 1000000);
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int i, reader_id[NUM_READERS], writer_id[NUM_WRITERS];

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create reader threads
    for (i = 0; i < NUM_READERS; i++) {
        reader_id[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_id[i]);
    }

    // Create writer threads
    for (i = 0; i < NUM_WRITERS; i++) {
        writer_id[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_id[i]);
    }

    // Join reader threads
    for (i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    // Join writer threads
    for (i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}

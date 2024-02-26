#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

pthread_mutex_t mutex;
sem_t write_block;
int data = 0, readers_count = 0;

void *reader(void *arg) {
    int reader_id = *((int *)arg);
    while (1) {
        pthread_mutex_lock(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&write_block);
        }
        pthread_mutex_unlock(&mutex);

        printf("Reader %d reads data: %d\n", reader_id, data);
        sleep(1);

        pthread_mutex_lock(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&write_block);
        }
        pthread_mutex_unlock(&mutex);

        // Sleep for a random time
        usleep(rand() % 1000000);
    }
    return NULL;
}

void *writer(void *arg) {
    int writer_id = *((int *)arg);
    while (1) {
        sem_wait(&write_block);
        data++;
        printf("Writer %d writes data: %d\n", writer_id, data);
        sem_post(&write_block);

        // Sleep for a random time
        usleep(rand() % 1000000);
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int i, reader_id[NUM_READERS], writer_id[NUM_WRITERS];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&write_block, 0, 1);

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

    // Destroy mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&write_block);

    return 0;
}

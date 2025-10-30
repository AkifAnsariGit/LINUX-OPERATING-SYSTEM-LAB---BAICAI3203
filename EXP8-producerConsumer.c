#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t emptySlots;
sem_t fullSlots;
pthread_mutex_t mutex;

void* producer(void* arg) {
    int item;
    for (int i = 1; i <= 10; i++) {
        item = i;
        sem_wait(&emptySlots);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Producer produced: %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&fullSlots);
        sleep(1);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item;
    for (int i = 1; i <= 10; i++) {
        sem_wait(&fullSlots);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        printf("Consumer consumed: %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&emptySlots);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod, cons;

    sem_init(&emptySlots, 0, BUFFER_SIZE);
    sem_init(&fullSlots, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);
    pthread_mutex_destroy(&mutex);

    return 0;
}

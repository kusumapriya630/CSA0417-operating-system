#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_SIZE 3
int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
void *producer(void *arg) {
 int i;
 for (i = 0; i < 4; i++) {
 pthread_mutex_lock(&mutex);
 while (count == BUFFER_SIZE) {
 printf("Buffer is full, producer is waiting...\n");
 pthread_cond_wait(&full, &mutex);
 }
 buffer[in] = i;
 printf("Produced item %d\n", buffer[in]);
 in = (in + 1) % BUFFER_SIZE;
 count++;
 pthread_cond_signal(&empty);
 pthread_mutex_unlock(&mutex);
 }
 pthread_exit(NULL);
}
void *consumer(void *arg) {
 int item;
 while (1) {
 pthread_mutex_lock(&mutex);
 while (count == 0) {
 printf("Buffer is empty, consumer is waiting...\n");
 pthread_cond_wait(&empty, &mutex);
 }
 item = buffer[out];
 printf("Consumed item %d\n", item);
 out = (out + 1) % BUFFER_SIZE;
 count--;
 pthread_cond_signal(&full);
 pthread_mutex_unlock(&mutex);
 }
}
int main() {
 pthread_t producer_thread, consumer_thread;
 pthread_create(&producer_thread, NULL, producer, NULL);
 pthread_create(&consumer_thread, NULL, consumer, NULL);
 pthread_join(producer_thread, NULL);
 pthread_join(consumer_thread, NULL);
}
/* OUTPUT 
roduced item 0
Consumed item 0
Produced item 1
Consumed item 1
Produced item 2
Consumed item 2
Produced item 3
Consumed item 3
Buffer is empty, consumer is waiting...
*/

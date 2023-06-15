#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
int shared_data = 5;
sem_t semaphore;
void* thread1_func(void* arg) {
 int data;
 sem_wait(&semaphore);
 data = shared_data;
 data = data * 2;
 printf("Thread 1: Doubled data: %d\n", data);
 sem_post(&semaphore);
 pthread_exit(NULL);
}
void* thread2_func(void* arg) {
 int data;
 sem_wait(&semaphore);
 data = shared_data;
 data = data * 5;
 printf("Thread 2: Five times data: %d\n", data);
 sem_post(&semaphore);
 pthread_exit(NULL);
}
int main() {
 pthread_t thread1, thread2;
 sem_init(&semaphore, 0, 1);
 pthread_create(&thread1, NULL, thread1_func, NULL);
 pthread_create(&thread2, NULL, thread2_func, NULL);
 pthread_join(thread1, NULL);
 pthread_join(thread2, NULL);
 sem_destroy(&semaphore);
} 
/* OUTPUT 
Thread 1: Doubled data: 10
Thread 2: Five times data: 25
*/

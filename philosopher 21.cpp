#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5             // Number of philosophers
#define LEFT (i + 4) % N // Left neighbor of i
#define RIGHT (i + 1) % N    // Right neighbor of i
#define THINKING 0      // Philosopher is thinking
#define HUNGRY 1        // Philosopher is hungry
#define EATING 2        // Philosopher is eating

int state[N];           // Array to keep track of the state of each philosopher
pthread_mutex_t mutex;  // Mutex to protect access to critical section
pthread_cond_t cond[N]; // Condition variables for each philosopher

void *philosopher(void *arg);
void take_forks(int i);
void put_forks(int i);
void test(int i);

int main()
{
    int i;
    pthread_t tid[N];

    // Initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < N; i++)
        pthread_cond_init(&cond[i], NULL);

    // Create philosopher threads
    for (i = 0; i < N; i++)
        pthread_create(&tid[i], NULL, philosopher, (void *)i);

    // Wait for philosopher threads to complete
    for (i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    // Destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    for (i = 0; i < N; i++)
        pthread_cond_destroy(&cond[i]);

    return 0;
}

void *philosopher(void *arg)
{
    int i = (int)arg;

    while (1) {
        printf("Philosopher %d is thinking\n", i);
        sleep(rand() % 5);  // Think for a random amount of time

        take_forks(i);      // Try to take forks
        printf("Philosopher %d is eating\n", i);
        sleep(rand() % 5);  // Eat for a random amount of time

        put_forks(i);       // Put down forks
    }
}

void take_forks(int i)
{
    pthread_mutex_lock(&mutex);         // Acquire mutex lock
    state[i] = HUNGRY;                  // Set state to hungry
    test(i);                            // Try to eat
    while (state[i] != EATING)          // Wait for condition variable
        pthread_cond_wait(&cond[i], &mutex);
    pthread_mutex_unlock(&mutex);       // Release mutex lock
}

void put_forks(int i)
{
    pthread_mutex_lock(&mutex);         // Acquire mutex lock
    state[i] = THINKING;                // Set state to thinking
    test(LEFT);                         // Let left neighbor try to eat
    test(RIGHT);                        // Let right neighbor try to eat
    pthread_mutex_unlock(&mutex);       // Release mutex lock
}

void test(int i)
{
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        pthread_cond_signal(&cond[i]);  // Signal condition variable
    }
}

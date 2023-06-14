#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid1, pid2, pid3, pid4;

    pid1 = fork();  // Create first child process
    if (pid1 == 0) {
        // First child process prints odd numbers
        printf("First child process (PID %d) printing odd numbers:\n", getpid());
        for (int i = 1; i <= 10; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
        exit(0);
    }

    pid2 = fork();  // Create second child process
    if (pid2 == 0) {
        // Second child process prints even numbers
        printf("Second child process (PID %d) printing even numbers:\n", getpid());
        for (int i = 2; i <= 10; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
        exit(0);
    }

    pid3 = fork();  // Create third child process
    if (pid3 == 0) {
        // Third child process prints multiples of 3
        printf("Third child process (PID %d) printing multiples of 3:\n", getpid());
        for (int i = 3; i <= 30; i += 3) {
            printf("%d ", i);
        }
        printf("\n");
        exit(0);
    }

    pid4 = fork();  // Create fourth child process
    if (pid4 == 0) {
        // Fourth child process prints multiples of 5
        printf("Fourth child process (PID %d) printing multiples of 5:\n", getpid());
        for (int i = 5; i <= 50; i += 5) {
            printf("%d ", i);
        }
        printf("\n");
        exit(0);
    }

    // Parent process waits for all child processes to complete
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);
    waitpid(pid4, NULL, 0);

    return 0;
}

#include <stdio.h>

#define MAX_PROCESSES 3

struct Process {
    int burstTime;
    int priority;
};

void calculateWaitingTime(struct Process processes[], int n, int waitingTime[]) {
    int currentTime = 0;
    int remainingBurstTime[MAX_PROCESSES];
    int completed = 0;

    // Copy burst times to remainingBurstTime array
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = processes[i].burstTime;
    }

    while (completed != n) {
        int highestPriority = -1;
        int selectedProcess = -1;

        // Find process with the highest priority
        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0 && processes[i].priority > highestPriority) {
                highestPriority = processes[i].priority;
                selectedProcess = i;
            }
        }

        if (selectedProcess == -1) {
            currentTime++;
            continue;
        }

        // Process selected, update waiting time
        waitingTime[selectedProcess] = currentTime;

        // Decrement burst time
        remainingBurstTime[selectedProcess]--;

        // Check if the process is completed
        if (remainingBurstTime[selectedProcess] == 0) {
            completed++;
        }

        currentTime++;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

void calculateAverageTimes(struct Process processes[], int n) {
    int waitingTime[MAX_PROCESSES] = {0};
    int turnaroundTime[MAX_PROCESSES] = {0};

    calculateWaitingTime(processes, n, waitingTime);
    calculateTurnaroundTime(processes, n, waitingTime, turnaroundTime);

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];

        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }

    double averageWaitingTime = (double) totalWaitingTime / n;
    double averageTurnaroundTime = (double) totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

int main() {
    struct Process processes[MAX_PROCESSES] = {
        {30, 2},
        {5, 1},
        {12, 3},

    };

    int n = sizeof(processes) / sizeof(processes[0]);

    calculateAverageTimes(processes, n);

    return 0;
}

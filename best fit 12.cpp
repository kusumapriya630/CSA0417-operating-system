#include <stdio.h>

#define NUM_PARTITIONS 6

int main() {
    int partitions[NUM_PARTITIONS] = { 300, 600, 350, 200, 750, 125 }; 
    int num_processes = 5; 
    int processes[5] = { 115, 500, 358, 200, 375 }; 
    int i, j, best_fit, best_fit_index;

    for (i = 0; i < num_processes; i++) {
        best_fit = -1;
        best_fit_index = -1;
        for (j = 0; j < NUM_PARTITIONS; j++) {
            if (partitions[j] >= processes[i] && (best_fit == -1 || partitions[j] < best_fit)) {
                best_fit = partitions[j];
                best_fit_index = j;
            }
        }
        if (best_fit_index == -1) {
            printf("Process %d of size %d KB could not be allocated.\n", i+1, processes[i]);
        }
        else {
            printf("Process %d of size %d KB allocated to partition %d of size %d KB.\n", i+1, processes[i], best_fit_index+1, best_fit);
            partitions[best_fit_index] -= processes[i];
        }
    }

    return 0;
}
/* OUTPUT 
Process 1 of size 115 KB allocated to partition 6 of size 125 KB.
Process 2 of size 500 KB allocated to partition 2 of size 600 KB.
Process 3 of size 358 KB allocated to partition 5 of size 750 KB.
Process 4 of size 200 KB allocated to partition 4 of size 200 KB.
Process 5 of size 375 KB allocated to partition 5 of size 392 KB.
 */

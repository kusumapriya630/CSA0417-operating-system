#include<stdio.h>
#include<stdlib.h>
int memory_size = 6;
int process_size = 5;
int memory[6] = {300, 600, 350, 200, 750, 125};
int process[5] = {115, 500, 358, 200, 375};
int allocated[5] = {0};
void worst_fit_algorithm() {
 int i, j, max_index;
 for(i = 0; i < process_size; i++) {
 max_index = -1;
 for(j = 0; j < memory_size; j++) {
 if(memory[j] >= process[i]) {
 if(max_index == -1) {
 max_index = j;
 }
 else if(memory[j] > memory[max_index]) {
 max_index = j;
 }
 }
 }
 if(max_index != -1) {
 allocated[i] = 1;
 memory[max_index] -= process[i];
 }
 }
}
void print_memory() {
 int i;
 printf("Memory allocation:\n");
 for(i = 0; i < memory_size; i++) {
 printf("%d KB ", memory[i]);
 }
 printf("\n");
}
void print_process() {
 int i;
 printf("Process allocation:\n");
 for(i = 0; i < process_size; i++) {
 if(allocated[i]) {
 printf("%d KB - Allocated\n", process[i]);
 }
 else {
 printf("%d KB - Not allocated\n", process[i]);
 }
 }
 printf("\n");
}
int main() {
 worst_fit_algorithm();
 print_memory();
 print_process();
}

/* OUTPUT 
Memory allocation:
300 KB 242 KB 150 KB 200 KB 135 KB 125 KB
Process allocation:
115 KB - Allocated
500 KB - Allocated
358 KB - Allocated
200 KB - Allocated
375 KB - Not allocated*/

#include<stdio.h>
#include<stdlib.h>
void round_robin(int bt[], int n, int quantum) {
 int wt[n], tat[n], total_wt = 0, total_tat = 0, time = 0, remaining_bt[n];
 for(int i = 0; i < n; i++)
 remaining_bt[i] = bt[i];
 while(1) {
 int done = 1;
 for(int i = 0; i < n; i++) {
 if(remaining_bt[i] > 0) {
 done = 0;
 if(remaining_bt[i] > quantum) {
 time += quantum;
 remaining_bt[i] -= quantum;
 }
 else {
 time += remaining_bt[i];
 wt[i] = time - bt[i];
 remaining_bt[i] = 0;
 }
 }
 }
 if(done == 1)
 break;
 }
 for(int i = 0; i < n; i++) {
 tat[i] = bt[i] + wt[i];
 total_wt += wt[i];
 total_tat += tat[i];
 }
 printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 for(int i = 0; i < n; i++) {
 printf("\nP%d\t\t%d\t\t%d\t\t%d", i+1, bt[i], wt[i], tat[i]);
 }
 float avg_wt = (float) total_wt / n;
 float avg_tat = (float) total_tat / n;
 printf("\n\nAverage Waiting Time: %f", avg_wt);
 printf("\nAverage Turnaround Time: %f\n", avg_tat);
}
int main() {
 int n = 3, quantum = 4;
 int bt[] = {24, 3, 3};
 round_robin(bt, n, quantum);
}
/*OUTPUT
Process         Burst Time      Waiting Time    Turnaround Time
P1              24              6               30
P2              3               4               7
P3              3               7               10

Average Waiting Time: 5.666667
Average Turnaround Time: 15.666667 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
 int n=3, i, j, wt[10]={0}, tat[10]={0}, bt[10]={10, 15, 25}, ct=0, avg_wt=0, avg_tat=0;
 char pid[] = {'P1', 'P2', 'P3'};
 for(i=0; i<n; i++)
 {
 ct += bt[i];
 tat[i] = ct;
 avg_tat += tat[i];
for(j=0; j<i; j++)
 wt[i] += bt[j];
 avg_wt += wt[i];
 }
 avg_wt /= n;
 avg_tat /= n;
 printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
 for(i=0; i<n; i++)
 printf("%c\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
 printf("\nAverage Waiting Time: %d\n", avg_wt);
 printf("Average Turnaround Time: %d\n", avg_tat);
}

/* OUTPUT
Process Burst Time      Waiting Time    Turnaround Time
1               10              0               10
2               15              10              25
3               25              25              50

Average Waiting Time: 11
Average Turnaround Time: 28
*/

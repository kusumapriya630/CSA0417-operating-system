#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
 int n=9, head_pos=50, curr_track, head_movement=0, i;
 int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
 printf("Track sequence: ");
 for(i=0; i<n; i++)
 printf("%d ", tracks[i]);
 printf("\n\nFCFS Disk Scheduling Algorithm:\n");
 printf("Current Head Position: %d\n", head_pos);
 for(i=0; i<n; i++)
 {
 curr_track = tracks[i];
 head_movement += abs(head_pos - curr_track);
 head_pos = curr_track;
 printf("Move to Track %d\n", curr_track);
 }
 printf("\nTotal Head Movement: %d\n", head_movement);
 printf("Average Head Movement: %.2f\n", (float)head_movement/n);
}
/*Track sequence: 55 58 60 70 18 90 150 160 184

FCFS Disk Scheduling Algorithm:
Current Head Position: 50
Move to Track 55
Move to Track 58
Move to Track 60
Move to Track 70
Move to Track 18
Move to Track 90
Move to Track 150
Move to Track 160
Move to Track 184

Total Head Movement: 238
Average Head Movement: 26.44
*/

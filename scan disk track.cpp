#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n = 5;
    int head_pos = 50; // initial head position
    int tracks[] = {55, 58, 60, 70, 18};
    int i, j, temp, sum = 0;

    // sorting tracks in ascending order
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(tracks[i] > tracks[j])
            {
                temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }

    // finding index of head_pos
    for(i = 0; i < n; i++)
    {
        if(head_pos < tracks[i])
        {
            break;
        }
    }

    // moving head towards higher track positions
    printf("Sequence of head movements:\n%d ", head_pos);
    for(j = i; j < n; j++)
    {
        printf("%d ", tracks[j]);
        sum += abs(head_pos - tracks[j]);
        head_pos = tracks[j];
    }

    // moving head towards lower track positions
    if(i != 0)
    {
        printf("%d ", tracks[i-1]);
        sum += abs(head_pos - tracks[i-1]);
        head_pos = tracks[i-1];
    }

    for(j = i-2; j >= 0; j--)
    {
        printf("%d ", tracks[j]);
        sum += abs(head_pos - tracks[j]);
        head_pos = tracks[j];
    }

    printf("\nAverage head movement: %0.2f\n", (float)sum/n);

    return 0;
}

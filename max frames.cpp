#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3
#define MAX_PAGES 25

int main() {
    int page_frames[MAX_FRAMES] = { -1, -1, -1 }; 
    
    int page_faults = 0;
    int page_sequence[MAX_PAGES] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1 };
    int num_pages = sizeof(page_sequence) / sizeof(page_sequence[0]);

    for (int i = 0; i < num_pages; i++) {
        int page = page_sequence[i];
        bool page_hit = false;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (page_frames[j] == page) {
                page_hit = true;
                break;
            }
        }

        if (!page_hit) {
            int replace_index = -1;
            int max_future_distance = -1;

            for (int j = 0; j < MAX_FRAMES; j++) {
                int future_distance = 0;
                for (int k = i + 1; k < num_pages; k++) {
                    if (page_frames[j] == page_sequence[k]) {
                        break;
                    }
                    future_distance++;
                }

                if (future_distance > max_future_distance) {
                    max_future_distance = future_distance;
                    replace_index = j;
                }
            }

            page_frames[replace_index] = page;
            page_faults++;
        }
        printf("Page frames: ");
        for (int j = 0; j < MAX_FRAMES; j++) {
            printf("%d ", page_frames[j]);
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", page_faults);

    return 0;
}
/* OUTPUT
Page frames: 7 -1 -1
Page frames: 7 0 -1
Page frames: 7 0 1
Page frames: 2 0 1
Page frames: 2 0 1
Page frames: 2 0 3
Page frames: 2 0 3
Page frames: 2 4 3
Page frames: 2 4 3
Page frames: 2 4 3
Page frames: 2 0 3
Page frames: 2 0 3
Page frames: 2 0 3
Page frames: 2 0 1
Page frames: 2 0 1
Page frames: 2 0 1
Page frames: 2 0 1
Page frames: 7 0 1
Page frames: 7 0 1
Page frames: 7 0 1
Page frames: 7 0 1
Page frames: 7 0 1
Page frames: 7 0 1
Page frames: 7 0 1
Page frames: 7 0 1
Total page faults: 9
*?

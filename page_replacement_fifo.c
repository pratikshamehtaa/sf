#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

void fifo(int pages[], int n) {
    int frames[MAX_FRAMES];
    int frameIndex = 0;
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; // Initialize frames to -1
    }

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageHit = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                pageHit = 1;
                break;
            }
        }

        if (!pageHit) {
            printf("Page %d caused a page fault.\n", currentPage);
            frames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % MAX_FRAMES;
            pageFaults++;
        }

        // Print the current state of frames
        printf("Frames: ");
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Total Page Faults using FIFO: %d\n", pageFaults);
}

int main() {
    printf("enter number of pages\n");
    int n;
    scanf("%d", &n);
    int pages[n];
    printf("enter page sequence\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    fifo(pages, n);

    return 0;
}

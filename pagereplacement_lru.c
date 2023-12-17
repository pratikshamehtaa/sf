#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 4

void lru(int pages[], int n) {
    int frames[MAX_FRAMES];
    int recentCount[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; // Initialize frames to -1
        recentCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageHit = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                pageHit = 1;
                recentCount[j] = i + 1; // Update recentCount to current iteration
                break;
            }
        }

        if (!pageHit) {
            printf("Page %d caused a page fault.\n", currentPage);

            // Find the least recently used page in the frames
            int minRecentCountIndex = 0;
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (recentCount[j] < recentCount[minRecentCountIndex]) {
                    minRecentCountIndex = j;
                }
            }

            // Replace the least recently used page
            frames[minRecentCountIndex] = currentPage;
            recentCount[minRecentCountIndex] = i + 1;

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

    printf("Total Page Faults using LRU: %d\n", pageFaults);
}

int main() {
    printf("Enter the number of pages: ");
    int n;
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page sequence: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    lru(pages, n);

    return 0;
}

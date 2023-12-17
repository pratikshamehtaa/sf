#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_FRAMES 4

int findOptimal(int frames[], int pages[], int n, int start) {
    int index = -1, farthest = start;
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = start; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (index == -1) ? 0 : index;
}

void optimal(int pages[], int n) {
    int frames[MAX_FRAMES];
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

            // Find the index to replace using the Optimal algorithm
            int replaceIndex = findOptimal(frames, pages, n, i + 1);

            // Replace the page with the farthest occurrence in the future
            frames[replaceIndex] = currentPage;

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

    printf("Total Page Faults using Optimal: %d\n", pageFaults);
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

    optimal(pages, n);

    return 0;
}

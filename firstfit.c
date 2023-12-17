#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int fragment[m];

    for (int i = 0; i < m; i++) {
        fragment[i] = blockSize[i];
    }

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;

        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                fragment[j] = blockSize[j];
                break;
            }
        }
    }

    printf("\nProcess\tProcess Size\tBlock Index\tFragment\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\t\t%d\n", allocation[i] + 1, fragment[allocation[i]]);
        } else {
            printf("Not Allocated\tN/A\n");
        }
    }
}


int main() {
    int m, n;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    int blockSize[m];

    printf("Enter the sizes of memory blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processSize[n];

    printf("Enter the sizes of processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    firstFit(blockSize, m, processSize, n);

    return 0;
}

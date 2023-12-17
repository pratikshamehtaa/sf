#include <stdio.h>
#include<stdlib.h>

void sstf(int request[], int n, int head) {
    int seekCount = 0;
    int currentHead = head;

    for (int i = 0; i < n; i++) {
        int minDistance = abs(currentHead - request[i]);
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            int distance = abs(currentHead - request[j]);
            if (distance < minDistance) {
                minDistance = distance;
                minIndex = j;
            }
        }

        seekCount += minDistance;
        currentHead = request[minIndex];

        int temp = request[minIndex];
        request[minIndex] = request[i];
        request[i] = temp;
    }

    printf("Total Seek Count using SSTF: %d\n", seekCount);
}

int main() {
    int n, head;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int request[n];

    printf("Enter the request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    sstf(request, n, head);

    return 0;
}

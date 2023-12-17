#include <stdio.h>
#include <stdlib.h>

void fifo(int request[], int n, int head) {
    int seekCount = 0;
    int currentHead = head;

    for (int i = 0; i < n; i++) {
        seekCount += abs(currentHead - request[i]);
        currentHead = request[i];
    }

    printf("Total Seek Count using FIFO: %d\n", seekCount);
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

    fifo(request, n, head);

    return 0;
}

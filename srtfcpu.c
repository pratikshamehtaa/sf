#include <stdio.h>

struct Process {
    int pid;
    int burstTime;
    int waitingTime;  // New field to store waiting time
};

int findShortestJob(struct Process processes[], int n, int currentTime) {
    int shortestJob = -1;
    int shortestTime = 9999;

    for (int i = 0; i < n; i++) {
        if (processes[i].burstTime > 0 && processes[i].burstTime < shortestTime && processes[i].burstTime > currentTime) {
            shortestJob = i;
            shortestTime = processes[i].burstTime;
        }
    }

    return shortestJob;
}

void SRTF(struct Process processes[], int n) {
    int currentTime = 0;
    int totalWaitingTime = 0;  // New variable to store total waiting time

    printf("Time\tProcess\tWaiting Time\n");

    while (1) {
        int shortestJob = findShortestJob(processes, n, currentTime);

        if (shortestJob == -1)
            break;

        processes[shortestJob].burstTime -= 1;
        currentTime += 1;

        // Update waiting time for the completed processes
        for (int i = 0; i < n; i++) {
            if (i != shortestJob && processes[i].burstTime > 0) {
                processes[i].waitingTime += 1;
            }
        }

        printf("%d\tP%d\t%d\n", currentTime, processes[shortestJob].pid, processes[shortestJob].waitingTime);
    }

    // Calculate total waiting time
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
    }

    // Calculate and print average waiting time
    float averageWaitingTime = (float)totalWaitingTime / n;
    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].waitingTime = 0;  // Initialize waiting time to 0
    }

    SRTF(processes, n);

    return 0;
}

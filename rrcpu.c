#include <stdio.h>

struct Process {
    int pid;
    int burstTime;
};

void roundRobin(struct Process processes[], int n, int quantum) {
    int remainingBurstTime[n], waitingTime[n], turnaroundTime[n];
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = processes[i].burstTime;
        waitingTime[i] = turnaroundTime[i] = 0;
    }

    while (1) {
        int allProcessesDone = 1;

        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                allProcessesDone = 0;

                if (remainingBurstTime[i] <= quantum) {
                    currentTime += remainingBurstTime[i];
                    turnaroundTime[i] = currentTime;
                    remainingBurstTime[i] = 0;
                } else {
                    currentTime += quantum;
                    remainingBurstTime[i] -= quantum;
                }
            }
        }

        if (allProcessesDone)
            break;
    }

    printf("Process\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        waitingTime[i] = turnaroundTime[i] - processes[i].burstTime;
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];

        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }

    printf("AverageWaitingTime: %.2f\n", totalWaitingTime / n);
    printf("AverageTurnaroundTime: %.2f\n", totalTurnaroundTime / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    roundRobin(processes, n, quantum);

    return 0;
}

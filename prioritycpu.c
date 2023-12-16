#include <stdio.h>

struct Process {
    int pid;
    int priority;
    int burstTime;     
};


int findHighestPriority(struct Process processes[], int n) {
    int highestPriority = 9999;
    int highestPriorityIndex = -1;

    for (int i = 0; i < n; i++) {
        if (processes[i].priority < highestPriority) {
            highestPriority = processes[i].priority;
            highestPriorityIndex = i;
        }
    }

    return highestPriorityIndex;
}


void PriorityScheduling(struct Process processes[], int n) {
    int totalExecutionTime = 0;
    int waitingTime[n];

    printf("Process\tPriority\tBurstTime\tWaitingTime\n");

    for (int i = 0; i < n; i++) {
        int highestPriorityProcess = findHighestPriority(processes, n);

        totalExecutionTime += processes[highestPriorityProcess].burstTime;
        waitingTime[i] = totalExecutionTime - processes[highestPriorityProcess].burstTime;

        printf("P%d\t%d\t\t%d\t\t%d\n",
               processes[highestPriorityProcess].pid,
               processes[highestPriorityProcess].priority,
               processes[highestPriorityProcess].burstTime,
               waitingTime[i]);

        processes[highestPriorityProcess].priority = 9999;  
    }


    float avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
    }
    avgWaitingTime /= n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter priority for P%d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    PriorityScheduling(processes, n);

    return 0;
}

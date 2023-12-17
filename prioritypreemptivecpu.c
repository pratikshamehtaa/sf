#include <stdio.h>


struct Process {
    char name;
    int priority;
    int burst_time;
    int completion_time;
};

void priority_preemptive_scheduling(struct Process processes[], int n) {
    int current_time = 0;

    while (n > 0) {

        int highest_priority_index = 0;
        for (int i = 1; i < n; i++) {
            if (processes[i].priority < processes[highest_priority_index].priority) {
                highest_priority_index = i;
            }
        }

        current_time++;
        processes[highest_priority_index].burst_time--;


        if (processes[highest_priority_index].burst_time == 0) {
            processes[highest_priority_index].completion_time = current_time;
            

            for (int i = highest_priority_index; i < n - 1; i++) {
                processes[i] = processes[i + 1];
            }

            n--;
        }
    }
}


int main() {
    struct Process processes[] = {
        {'A', 2, 5, 0},
        {'B', 1, 3, 0},
        {'C', 3, 8, 0},
    };

    int n = sizeof(processes) / sizeof(processes[0]);


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }


    priority_preemptive_scheduling(processes, n);


    for (int i = 0; i < sizeof(processes) / sizeof(processes[0]); i++) {
        printf("Process %c completed at time %d\n", processes[i].name, processes[i].completion_time);
    }

    return 0;
}

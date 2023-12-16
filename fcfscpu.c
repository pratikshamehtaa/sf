#include <stdio.h>

int main() {
    int n;
    printf("ENTER THE NO. OF PROCESSES: ");
    scanf("%d",&n);

    int burstTime[n],waitingTime[n],i,turnaroundTime[n];
    for(i=0;i<n;i++)
    {
        printf("BURST TIME FOR P%d: ",i+1);
        scanf("%d",&burstTime[i]);
    }

    waitingTime[0]=0;
    turnaroundTime[0]=burstTime[0];
    for(i=1;i<n;i++)
    {
        waitingTime[i]=0;
        for(int j=0;j<i;j++)
        {
           waitingTime[i]+=burstTime[j]; 
        }
        turnaroundTime[i]=waitingTime[i]+burstTime[i];
    }

    float avgWaitingTime=0,avgTurnaroundTime=0;

    for(i=0;i<n;i++)
    {
        avgWaitingTime+=waitingTime[i];
        avgTurnaroundTime+=turnaroundTime[i];
    }

    avgWaitingTime /=n;
    avgTurnaroundTime /=n;


    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}

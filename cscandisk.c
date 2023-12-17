#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int n, schedule[10], head, mov = 0, temp, temp1;
    
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    
    printf("Enter the schedule to perform C-SCAN disk scheduling: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &schedule[i]);
    }
    
    printf("Enter the head: ");
    scanf("%d", &head);


    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(schedule[j] > schedule[j+1]) {
                temp1 = schedule[j];
                schedule[j] = schedule[j+1];
                schedule[j+1] = temp1;
            }
        }
    }

    printf("The sorted schedule is: ");
    for(int i = 0; i < n; i++) {
        printf("\t%d", schedule[i]);
    }

    int i;
    for (i = 0; i < n; i++) {
        if (head < schedule[i]) {
            break; 
        }
    }

    for (int j = i; j < n; j++) {
        mov += abs(head - schedule[j]);
        head = schedule[j];
    }


    mov += abs(head - 0);
    head = 0;

  
    for (int j = 0; j < i; j++) {
        mov += abs(head - schedule[j]);
        head = schedule[j];
    }

    printf("\nTotal movements are: %d", mov);

    return 0;
}

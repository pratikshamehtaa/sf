#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, schedule[10], head, mov = 0, temp;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the schedule to perform C-LOOK disk scheduling: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &schedule[i]);
    }

    printf("Enter the head: ");
    scanf("%d", &head);

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (schedule[j] > schedule[j + 1]) {
                temp = schedule[j];
                schedule[j] = schedule[j + 1];
                schedule[j + 1] = temp;
            }
        }
    }

    printf("The sorted schedule is: ");
    for (int i = 0; i < n; i++) {
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


    mov += abs(head - schedule[0]);
    head = schedule[0];


    for (int j = 0; j < n; j++) {
        mov += abs(head - schedule[j]);
        head = schedule[j];
    }

    printf("\nTotal movements are: %d", mov);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Initialize a mutex to 1
int mutex = 1;

// Number of full slots as 0
int full = 0;

// Number of empty slots as size of buffer
int empty = 10, x = 0;

// Function to produce an item and add it to the buffer
void producer() {
    if (mutex == 1 && empty != 0) {
        --mutex;
        ++full;
        --empty;
        x++;
        printf("\nProducer produces item %d\n", x);
        ++mutex;
    } else {
        printf("Buffer is full!\n");
    }
}

// Function to consume an item and remove it from buffer
void consumer() {
    if (mutex == 1 && full != 0) {
        --mutex;
        --full;
        ++empty;
        printf("\nConsumer consumes item %d\n", x);
        x--;
        ++mutex;
    } else {
        printf("Buffer is empty!\n");
    }
}

// Driver Code
int main() {
    int n;

    for (;;) {
        printf("\n1. Press 1 for Producer"
               "\n2. Press 2 for Consumer"
               "\n3. Press 3 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                producer();
                break;

            case 2:
                consumer();
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

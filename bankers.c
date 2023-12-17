#include <stdio.h>

int main() {

    int numProcesses = 5;
    int numResources = 3;


    int allocationMatrix[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };


    int maxDemandMatrix[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };


    int availableResources[3] = {3, 3, 2};


    int isProcessFinished[numProcesses];
    for (int processIndex = 0; processIndex < numProcesses; processIndex++) {
        isProcessFinished[processIndex] = 0;
    }


    int needMatrix[numProcesses][numResources];
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            needMatrix[i][j] = maxDemandMatrix[i][j] - allocationMatrix[i][j];
        }
    }


    int safeSequence[numProcesses];
    int sequenceIndex = 0;


    for (int iteration = 0; iteration < numProcesses; iteration++) {
        for (int processIndex = 0; processIndex < numProcesses; processIndex++) {
            if (isProcessFinished[processIndex] == 0) {
                int isSafe = 1;

                // Check if the current process can be executed
                for (int resourceIndex = 0; resourceIndex < numResources; resourceIndex++) {
                    if (needMatrix[processIndex][resourceIndex] > availableResources[resourceIndex]) {
                        isSafe = 0;
                        break;
                    }
                }

                if (isSafe) {
  
                    isProcessFinished[processIndex] = 1;
                    safeSequence[sequenceIndex++] = processIndex;

                    for (int resourceIndex = 0; resourceIndex < numResources; resourceIndex++) {
                        availableResources[resourceIndex] += allocationMatrix[processIndex][resourceIndex];
                    }
                }
            }
        }
    }


    int isSafe = 1;
    for (int processIndex = 0; processIndex < numProcesses; processIndex++) {
        if (isProcessFinished[processIndex] == 0) {
            isSafe = 0;
            printf("The system is not safe.\n");
            break;
        }
    }

    if (isSafe) {
        printf("Following is the SAFE Sequence:\n");
        for (int i = 0; i < numProcesses ; i++) {
            printf(" P%d -", safeSequence[i]);
        }
    }
    printf("\n");
    return 0;
}

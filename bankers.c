#include <stdio.h>
#include <stdlib.h>

int allocation[20][20], max[20][20], available[20], need[20][20], safe[10], s = 0;
int finish[10], work[10], p, r, i, j, processIndex, req[10];

void calculateNeed() {
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

void displayTables() {
    printf("\nAllocation Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("%d\t", allocation[i][j]);
        printf("\n");
    }
    printf("\nNeed Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("%d\t", need[i][j]);
        printf("\n");
    }
}

void checkSafety() {
    for (i = 0; i < p; i++) finish[i] = 0;
    for (i = 0; i < r; i++) work[i] = available[i];

    while (1) {
        int found = 0;
        for (i = 0; i < p; i++) {
            if (!finish[i]) {
                int canProceed = 1;
                for (j = 0; j < r; j++)
                    if (need[i][j] > work[j]) {
                        canProceed = 0;
                        break;
                    }
                if (canProceed) {
                    for (j = 0; j < r; j++)
                        work[j] += allocation[i][j];
                    finish[i] = 1;
                    safe[s++] = i;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }

    if (s < p) {
        printf("\nSystem is in Deadlock state\n");
    } else {
        printf("\nSystem is in Safe state\nSafe Sequence: ");
        for (i = 0; i < s; i++)
            printf("P%d\t", safe[i]);
        printf("\n");
    }
}

int main() {
    printf("\nEnter the number of resources and processes: ");
    scanf("%d%d", &r, &p);
    printf("\nEnter the Allocation Table:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);
    printf("\nEnter the Max Table:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);
    printf("\nEnter the vector Available: ");
    for (i = 0; i < r; i++)
        scanf("%d", &available[i]);

    calculateNeed();
    displayTables();

    printf("\nEnter the process number for request: ");
    scanf("%d", &processIndex);
    printf("\nEnter the request: ");
    for (i = 0; i < r; i++)
        scanf("%d", &req[i]);

    for (i = 0; i < r; i++) {
        if (req[i] > need[processIndex][i] || req[i] > available[i]) {
            printf("\nRequest cannot be satisfied...\n");
            return 1;
        }
    }

    for (i = 0; i < r; i++) {
        allocation[processIndex][i] += req[i];
        available[i] -= req[i];
    }

    calculateNeed();
    checkSafety();

    return 0;
}

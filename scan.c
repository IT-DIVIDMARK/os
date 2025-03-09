#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], n, TotalHeadMovement = 0, initial, size, move;
    
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    
    printf("Enter the Requests sequence:\n");
    for (int i = 0; i < n; i++) 
        scanf("%d", &RQ[i]);
    
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    
    printf("Enter total disk size: ");
    scanf("%d", &size);
    
    printf("Enter the head movement direction (high 1 and low 0): ");
    scanf("%d", &move);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (index = 0; index < n; index++) {
        if (initial < RQ[index]) {
            break;
        }
    }

    printf("Order of requests served: ");
    
    if (move == 1) {
        for (int i = index; i < n; i++) {
            TotalHeadMovement += abs(RQ[i] - initial);
            printf("%d ", RQ[i]);
            initial = RQ[i];
        }
        if (index > 0) {
            TotalHeadMovement += abs(size - 1 - RQ[n - 1]);
            initial = size - 1;
        }
        for (int i = index - 1; i >= 0; i--) {
            TotalHeadMovement += abs(RQ[i] - initial);
            printf("%d ", RQ[i]);
            initial = RQ[i];
        }
    } else {
        for (int i = index - 1; i >= 0; i--) {
            TotalHeadMovement += abs(RQ[i] - initial);
            printf("%d ", RQ[i]);
            initial = RQ[i];
        }
        if (index < n) {
            TotalHeadMovement += abs(0 - RQ[0]);
            initial = 0;
        }
        for (int i = index; i < n; i++) {
            TotalHeadMovement += abs(RQ[i] - initial);
            printf("%d ", RQ[i]);
            initial = RQ[i];
        }
    }

    printf("\nTotal head movement is %d\n", TotalHeadMovement);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], n,sstftalHeadMovement = 0, initial, count = 0;
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    printf("%d - ", initial);

    while (count < n) {
        int min = 1000, index = -1;
        for (int i = 0; i < n; i++) {
            int d = abs(RQ[i] - initial);
            if (RQ[i] != 1000 && min > d) {
                min = d;
                index = i;
            }
        }
        if (index != -1) {
            TotalHeadMovement += min;
            initial = RQ[index];
            printf(" ------ > %d", RQ[index]);
            RQ[index] = 1000;
            count++;
        }
    }
    printf("\nTotal head movement is %d\n", TotalHeadMovement);
    return 0;
}

#include <stdio.h>

#define P 5 // Number of processes
#define R 3 // Number of resource types

// Function to calculate the Need matrix
void calculateNeed(int need[P][R], int max[P][R], int allot[P][R]) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

// Function to display the Allocation matrix
void displayAllocation(int allot[P][R]) {
    printf("Allocation Matrix:\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", allot[i][j]);
        }
        printf("\n");
    }
}

// Function to display the Max matrix
void displayMax(int max[P][R]) {
    printf("Max Matrix:\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }
}

// Function to display the Need matrix
void displayNeed(int need[P][R], int max[P][R], int allot[P][R]) {
    calculateNeed(need, max, allot);
    printf("Need Matrix:\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

// Function to display Available resources
void displayAvailable(int avail[R]) {
    printf("Available Resources:\n");
    for (int i = 0; i < R; i++) {
        printf("%d ", avail[i]);
    }
    printf("\n");
}

int main() {
    int allot[P][R]; // Allocation matrix
    int max[P][R];   // Maximum matrix
    int avail[R];    // Available resources
    int need[P][R];  // Need matrix
    int choice;

    // Accept Allocation matrix
    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < P; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < R; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    // Accept Max matrix
    printf("Enter Max Matrix:\n");
    for (int i = 0; i < P; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < R; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Accept Available resources
    printf("Enter Available Resources:\n");
    for (int i = 0; i < R; i++) {
        printf("Resource %d: ", i);
        scanf("%d", &avail[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Allocation Matrix\n");
        printf("2. Display Max Matrix\n");
        printf("3. Display Need Matrix\n");
        printf("4. Display Available Resources\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllocation(allot);
                break;

            case 2:
                displayMax(max);
                break;

            case 3:
                displayNeed(need, max, allot);
                break;

            case 4:
                displayAvailable(avail);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

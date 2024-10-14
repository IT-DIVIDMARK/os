#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


void bubblesort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionsort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

void fork1() {
    int arr[25], n, i;
    pid_t pid;

    printf("\nEnter the number of values in the array: ");
    scanf("%d", &n);
    
    printf("\nEnter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pid = fork(); // Create a child process

    if (pid == 0) {
        // Child process
        sleep(10); // Simulate a delay for the child process
        printf("\nChild process\n");
        printf("Child process ID = %d\n", getpid());
        printf("Parent process ID = %d\n", getppid());

        insertionsort(arr, n); // Child performs insertion sort
        printf("\nElements sorted using Insertion Sort:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        exit(0); // Exit child process
    } else if (pid > 0) {
        // Parent process
        wait(NULL); // Wait for the child process to finish
        printf("\nParent process\n");
        printf("Parent process ID = %d\n", getpid());

        bubblesort(arr, n); // Parent performs bubble sort
        printf("Elements sorted using Bubble Sort:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");

        system("ps -x"); // Display system processes
    } else {
        // Fork failed
        printf("Fork failed!\n");
        exit(1);
    }
}

int main() {
    fork1(); // Call the function to create a fork and sort
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10
#define MAX_REFERENCES 15

// Function to check if a page is already in memory (returns its index if found)
int isPresent(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return i;
        }
    }
    return -1;
}

// Function to find the index of the most recently used frame
int findMRU(int recent[], int n) {
    int maxRecent = recent[0], index = 0;
    for (int i = 1; i < n; i++) {
        if (recent[i] > maxRecent) {
            maxRecent = recent[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int n, refStr[MAX_REFERENCES] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int frames[MAX_FRAMES], recent[MAX_FRAMES];
    int pageFaults = 0, time = 0;

    // Number of frames in memory
    printf("Enter the number of frames (n): ");
    scanf("%d", &n);

    // Initialize frames and recent usage time array
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
        recent[i] = -1;
    }

    // Process each page in the reference string
    for (int i = 0; i < MAX_REFERENCES; i++) {
        int currentPage = refStr[i];
        printf("\nReference to page %d: ", currentPage);

        // Check if page is already in memory
        int pos = isPresent(frames, n, currentPage);
        if (pos == -1) {
            // Page fault occurs
            pageFaults++;
            printf("(Page fault) ");

            // Find the MRU page to replace (if memory is full)
            if (frames[n-1] != -1) {
                int mruIndex = findMRU(recent, n);
                frames[mruIndex] = currentPage;  // Replace MRU page
                recent[mruIndex] = time;         // Update time
            } else {
                // Insert into first empty frame
                for (int j = 0; j < n; j++) {
                    if (frames[j] == -1) {
                        frames[j] = currentPage;
                        recent[j] = time;
                        break;
                    }
                }
            }
        } else {
            // Page is already in memory, update the recent time
            recent[pos] = time;
            printf("(No page fault) ");
        }

        // Print the current state of frames
        printf("Frames: ");
        for (int j = 0; j < n; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }

        time++;
    }

    printf("\n\nTotal number of page faults: %d\n", pageFaults);

    return 0;
}

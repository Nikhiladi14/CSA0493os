#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define FRAME_SIZE 3 // Size of the page frame
#define PAGE_COUNT 10 // Number of pages
#define EMPTY -1 // Indicates an empty page frame

void printFrames(int frames[], int n) {
    printf("Frames: ");
    for (int i = 0; i < n; i++) {
        if (frames[i] == EMPTY)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

bool isPageExists(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page)
            return true;
    }
    return false;
}

int findOptimal(int pages[], int frames[], int start_index, int n) {
    int index = -1;
    int farthest = start_index;
    for (int i = 0; i < FRAME_SIZE; i++) {
        int j;
        for (j = start_index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    if (index == -1)
        return 0;
    return index;
}

void optimal(int pages[], int n) {
    int frames[FRAME_SIZE]; // Page frames
    int page_faults = 0; // Count of page faults

    // Initialize all frames to EMPTY
    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i] = EMPTY;
    }

    // Traverse through all pages
    for (int i = 0; i < n; i++) {
        printf("Page %d: ", pages[i]);

        // If page already exists in frames, no page fault
        if (isPageExists(frames, FRAME_SIZE, pages[i])) {
            printf("Page already in frame.\n");
        } else {
            // Find the optimal page to replace
            int index = findOptimal(pages, frames, i + 1, n);

            // Replace the optimal page with the new page
            frames[index] = pages[i];
            page_faults++;
            printf("Page fault occurred.\n");
        }
        printFrames(frames, FRAME_SIZE);
    }

    printf("\nTotal page faults: %d\n", page_faults);
}

int main() {
    // Sample pages for testing
    int pages[PAGE_COUNT] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2};

    printf("Simulating Optimal Page Replacement Algorithm\n\n");
    optimal(pages, PAGE_COUNT);

    return 0;
}
'n'
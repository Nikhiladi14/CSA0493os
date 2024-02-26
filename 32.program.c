#include <stdio.h>
#include <stdbool.h>

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

int findLRU(int frames[], int counter[], int n) {
    int min = counter[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (counter[i] < min) {
            min = counter[i];
            index = i;
        }
    }
    return index;
}

void LRU(int pages[], int n) {
    int frames[FRAME_SIZE]; // Page frames
    int page_faults = 0; // Count of page faults
    int counter[FRAME_SIZE]; // Counter to track the last usage of each page in frames

    // Initialize all frames to EMPTY and counters to 0
    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i] = EMPTY;
        counter[i] = 0;
    }

    // Traverse through all pages
    for (int i = 0; i < n; i++) {
        printf("Page %d: ", pages[i]);

        // If page already exists in frames, update its counter
        if (isPageExists(frames, FRAME_SIZE, pages[i])) {
            printf("Page already in frame.\n");
            for (int j = 0; j < FRAME_SIZE; j++) {
                if (frames[j] == pages[i])
                    counter[j] = i;
            }
        } else {
            // Find the least recently used page in frames
            int index = findLRU(frames, counter, FRAME_SIZE);

            // Replace the least recently used page with the new page
            frames[index] = pages[i];
            counter[index] = i;
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

    printf("Simulating LRU Page Replacement Algorithm\n\n");
    LRU(pages, PAGE_COUNT);

    return 0;
}

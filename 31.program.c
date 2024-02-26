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

void FIFO(int pages[], int n) {
    int frames[FRAME_SIZE]; // Page frames
    int page_faults = 0; // Count of page faults
    int index = 0; // Index to replace the oldest page

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
            // Replace the oldest page in frames
            frames[index] = pages[i];
            index = (index + 1) % FRAME_SIZE; // Move to the next frame circularly
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

    printf("Simulating FIFO Page Replacement Algorithm\n\n");
    FIFO(pages, PAGE_COUNT);

    return 0;
}

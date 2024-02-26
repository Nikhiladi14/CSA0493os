#include <stdio.h>
#include <stdlib.h>

// Function to sort the array of disk requests
void sort(int arr[], int n) {
    int temp, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to find the index of the disk request closest to the head
int findNearestIndex(int arr[], int n, int head) {
    int index = -1;
    int minDist = 1000000; // A large number to represent infinity

    for (int i = 0; i < n; i++) {
        if (abs(arr[i] - head) < minDist) {
            minDist = abs(arr[i] - head);
            index = i;
        }
    }
    return index;
}

void CSCAN(int arr[], int n, int head, int max_track) {
    int total_tracks = n;
    int total_movement = 0;
    int current_track = head;
    int i, index, next_track;
    
    sort(arr, n);
    
    printf("Head movement path: %d ", head);

    // Moving towards higher track numbers first
    for (i = 0; i < n; i++) {
        if (arr[i] >= head) {
            index = i;
            break;
        }
    }

    // Moving towards higher track numbers
    for (i = index; i < n; i++) {
        printf("-> %d ", arr[i]);
        total_movement += abs(arr[i] - current_track);
        current_track = arr[i];
        total_tracks--;
    }

    // Move to the beginning of the disk
    printf("-> %d ", max_track);
    total_movement += abs(max_track - current_track);
    current_track = 0;

    // Moving towards lower track numbers
    for (i = 0; i < index; i++) {
        printf("-> %d ", arr[i]);
        total_movement += abs(arr[i] - current_track);
        current_track = arr[i];
        total_tracks--;
    }

    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int n, head, max_track;
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter the current position of the disk head: ");
    scanf("%d", &head);
    
    printf("Enter the maximum track number: ");
    scanf("%d", &max_track);
    
    CSCAN(arr, n, head, max_track);
    
    free(arr);
    return 0;
}

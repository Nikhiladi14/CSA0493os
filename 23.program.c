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

void SCAN(int arr[], int n, int head, int direction, int max_track) {
    int total_tracks = n;
    int total_movement = 0;
    int current_track = head;
    int i, index, next_track;
    
    sort(arr, n);
    
    if (direction == 1)
        printf("Head movement path: %d ", head);
    else
        printf("Head movement path: %d ", head);

    while (total_tracks > 0) {
        if (direction == 1) { // Moving towards higher track numbers
            index = findNearestIndex(arr, n, current_track);
            if (index == -1) {
                direction = -1; // Change direction
                continue;
            }
            next_track = arr[index];
            arr[index] = -1; // Mark this track as visited
        } else { // Moving towards lower track numbers
            index = findNearestIndex(arr, n, current_track);
            if (index == -1) {
                direction = 1; // Change direction
                continue;
            }
            next_track = arr[index];
            arr[index] = -1; // Mark this track as visited
        }
        
        if (next_track != -1) {
            printf("-> %d ", next_track);
            total_movement += abs(next_track - current_track);
            current_track = next_track;
            total_tracks--;
        }
    }
    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int n, head, max_track, direction;
    
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
    
    printf("Enter the direction of head movement (1 for towards higher track numbers, -1 for towards lower track numbers): ");
    scanf("%d", &direction);
    
    SCAN(arr, n, head, direction, max_track);
    
    free(arr);
    return 0;
}

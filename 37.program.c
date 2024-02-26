#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100 // Maximum number of disk requests

// Function to simulate FCFS disk scheduling
void FCFS(int requests[], int num_requests, int initial_position) {
    int current_position = initial_position;
    int total_head_movement = 0;

    printf("Sequence of disk head movement:\n");
    printf("%d ", current_position);

    // Traverse through all disk requests
    for (int i = 0; i < num_requests; i++) {
        // Calculate the absolute difference in positions
        int head_movement = abs(requests[i] - current_position);
        total_head_movement += head_movement;

        // Move the head to the next request position
        current_position = requests[i];

        printf("-> %d ", current_position);
    }

    printf("\nTotal head movement: %d\n", total_head_movement);
}

int main() {
    int requests[MAX_REQUESTS]; // Array to store disk requests
    int num_requests; // Number of disk requests
    int initial_position; // Initial position of the disk head

    // Input number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &num_requests);

    // Input disk requests
    printf("Enter the disk requests:\n");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    // Input initial position of the disk head
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &initial_position);

    // Perform FCFS disk scheduling
    FCFS(requests, num_requests, initial_position);

    return 0;
}

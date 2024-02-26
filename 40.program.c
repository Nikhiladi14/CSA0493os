#include <stdio.h>
#include <stdbool.h>

#define MAX_BLOCKS 100 // Maximum number of memory blocks
#define MAX_PROCESSES 100 // Maximum number of processes

// Structure to represent a memory block
typedef struct {
    int block_id;
    int size;
    bool allocated;
} MemoryBlock;

// Structure to represent a process
typedef struct {
    int process_id;
    int size;
    int block_id;
} Process;

// Function to allocate memory to a process using the best fit algorithm
void bestFit(MemoryBlock memory[], int num_blocks, Process process) {
    int best_index = -1;
    int min_size = -1;

    // Find the smallest available block that can accommodate the process
    for (int i = 0; i < num_blocks; i++) {
        if (!memory[i].allocated && memory[i].size >= process.size) {
            if (best_index == -1 || memory[i].size < min_size) {
                best_index = i;
                min_size = memory[i].size;
            }
        }
    }

    // If a suitable block is found, allocate memory to the process
    if (best_index != -1) {
        memory[best_index].allocated = true;
        process.block_id = memory[best_index].block_id;
        printf("Process %d allocated to memory block %d.\n", process.process_id, process.block_id);
    } else {
        printf("Unable to allocate memory for process %d.\n", process.process_id);
    }
}

int main() {
    MemoryBlock memory[MAX_BLOCKS]; // Array to store memory blocks
    Process processes[MAX_PROCESSES]; // Array to store processes
    int num_blocks, num_processes;

    // Input number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);

    // Input memory block details
    printf("Enter details of memory blocks:\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("Enter size of memory block %d: ", i + 1);
        scanf("%d", &memory[i].size);
        memory[i].block_id = i + 1;
        memory[i].allocated = false;
    }

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Input process details
    printf("Enter details of processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &processes[i].size);
        processes[i].process_id = i + 1;
        processes[i].block_id = -1; // Initialize block ID to -1 (unallocated)
    }

    // Allocate memory to processes using best fit algorithm
    printf("\nAllocating memory to processes:\n");
    for (int i = 0; i < num_processes; i++) {
        bestFit(memory, num_blocks, processes[i]);
    }

    return 0;
}

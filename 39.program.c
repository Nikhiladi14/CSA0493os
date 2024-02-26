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

// Function to allocate memory to a process using the worst fit algorithm
void worstFit(MemoryBlock memory[], int num_blocks, Process process) {
    int worst_index = -1;
    int worst_size = -1;

    // Find the largest available block
    for (int i = 0; i < num_blocks; i++) {
        if (!memory[i].allocated && memory[i].size >= process.size) {
            if (worst_index == -1 || memory[i].size > worst_size) {
                worst_index = i;
                worst_size = memory[i].size;
            }
        }
    }

    // If a suitable block is found, allocate memory to the process
    if (worst_index != -1) {
        memory[worst_index].allocated = true;
        process.block_id = memory[worst_index].block_id;
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

    // Allocate memory to processes using worst fit algorithm
    printf("\nAllocating memory to processes:\n");
    for (int i = 0; i < num_processes; i++) {
        worstFit(memory, num_blocks, processes[i]);
    }

    return 0;
}

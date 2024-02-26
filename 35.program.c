#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BLOCKS 100 // Maximum number of blocks in the file
#define BLOCK_SIZE 1024 // Size of each block

// Structure to represent a block
typedef struct {
    char data[BLOCK_SIZE];
} Block;

// Structure to represent a file
typedef struct {
    Block blocks[MAX_BLOCKS]; // Array to store file blocks
    int num_blocks; // Number of blocks in the file
} File;

// Function to initialize a file
void initFile(File *file) {
    file->num_blocks = 0;
}

// Function to add a block to the file
void addBlock(File *file, char data[]) {
    if (file->num_blocks >= MAX_BLOCKS) {
        printf("File is full. Cannot add more blocks.\n");
        return;
    }

    strcpy(file->blocks[file->num_blocks].data, data);
    file->num_blocks++;
}

// Function to display all blocks in the file
void displayFile(File *file) {
    printf("File contents:\n");
    for (int i = 0; i < file->num_blocks; i++) {
        printf("Block %d: %s\n", i + 1, file->blocks[i].data);
    }
}

int main() {
    File file; // File to store blocks

    // Initialize the file
    initFile(&file);

    // Add some sample blocks to the file
    addBlock(&file, "Data of Block 1");
    addBlock(&file, "Data of Block 2");
    addBlock(&file, "Data of Block 3");

    // Display the file contents
    displayFile(&file);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BLOCK_SIZE 1024 // Size of each disk block

// Structure to represent a disk block
typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block* next;
} Block;

// Structure to represent a file
typedef struct {
    Block* first_block; // Pointer to the first block of the file
    Block* last_block; // Pointer to the last block of the file
} File;

// Function to initialize a file
void initFile(File* file) {
    file->first_block = NULL;
    file->last_block = NULL;
}

// Function to add a block to the file
void addBlock(File* file, char data[]) {
    // Create a new block
    Block* new_block = (Block*)malloc(sizeof(Block));
    if (new_block == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(new_block->data, data);
    new_block->next = NULL;

    // If the file is empty, set both first and last blocks to the new block
    if (file->first_block == NULL) {
        file->first_block = new_block;
        file->last_block = new_block;
    } else {
        // Append the new block to the end of the file
        file->last_block->next = new_block;
        file->last_block = new_block;
    }
}

// Function to display all blocks in the file
void displayFile(File* file) {
    printf("File contents:\n");
    Block* current_block = file->first_block;
    while (current_block != NULL) {
        printf("%s\n", current_block->data);
        current_block = current_block->next;
    }
}

// Function to free memory allocated for blocks
void freeBlocks(File* file) {
    Block* current_block = file->first_block;
    while (current_block != NULL) {
        Block* temp = current_block;
        current_block = current_block->next;
        free(temp);
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

    // Free memory allocated for blocks
    freeBlocks(&file);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records in the file

// Structure to represent a record
typedef struct {
    int id;
    char data[100];
} Record;

// Function to add a record to the file
void addRecord(Record file[], int *num_records, int id, char data[]) {
    if (*num_records >= MAX_RECORDS) {
        printf("File is full. Cannot add more records.\n");
        return;
    }

    file[*num_records].id = id;
    strcpy(file[*num_records].data, data);
    (*num_records)++;
}

// Function to display all records in the file
void displayFile(Record file[], int num_records) {
    printf("File contents:\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record %d: ID = %d, Data = %s\n", i + 1, file[i].id, file[i].data);
    }
}

int main() {
    Record file[MAX_RECORDS]; // Array to store file records
    int num_records = 0; // Number of records in the file

    // Add some sample records to the file
    addRecord(file, &num_records, 1, "Data of Record 1");
    addRecord(file, &num_records, 2, "Data of Record 2");
    addRecord(file, &num_records, 3, "Data of Record 3");

    // Display the file contents
    displayFile(file, num_records);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *pattern;

    // Check if the number of arguments is correct
    if (argc != 3) {
        printf("Usage: %s <pattern> <file>\n", argv[0]);
        return 1;
    }

    pattern = argv[1];

    // Open the file
    file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", argv[2]);
        return 1;
    }

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Search for the pattern in the line
        if (strstr(line, pattern) != NULL) {
            // If the pattern is found, print the line
            printf("%s", line);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}

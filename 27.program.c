#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *directory;
    struct dirent *entry;

    // Open current directory
    directory = opendir(".");

    if (directory == NULL) {
        printf("Unable to open directory.\n");
        return 1;
    }

    // Print directory contents
    printf("Contents of current directory:\n");
    while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close directory
    closedir(directory);
    
    return 0;
}

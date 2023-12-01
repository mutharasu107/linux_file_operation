#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Create a new directory
    const char *newDirName = "my_directory";
    if (mkdir(newDirName, 0777) == 0) {
        printf("Directory '%s' created successfully.\n", newDirName);

        // Create a subdirectory inside the new directory
        const char *subDirName = "my_subdirectory";
        char command[100];
        sprintf(command, "mkdir %s/%s", newDirName, subDirName);
        
        if (system(command) == 0) {
            printf("Subdirectory '%s' created successfully.\n", subDirName);
        } else {
            fprintf(stderr, "Failed to create subdirectory.\n");
        }
    } else {
        fprintf(stderr, "Failed to create directory.\n");
    }

    return 0;
}

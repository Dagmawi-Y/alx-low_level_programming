#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the extern variable environ
extern char** environ;

void print_path_directories() {
    // Get the value of the PATH environment variable
    char* path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not found\n");
        return;
    }

    // Split the PATH string at each colon and print each directory
    char* token = strtok(path, ":");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
}

int main() {
    // Call the function to print PATH directories
    print_path_directories();
    return 0;
}

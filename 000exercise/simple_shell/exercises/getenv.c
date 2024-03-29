#include <stdio.h>
#include <string.h>

// Declare the extern variable environ
extern char** environ;

char* _getenv(const char* name) {
    // Iterate through the environ array
    for (char** env = environ; *env != NULL; ++env) {
        // Split the environment variable into name and value
        char* delim = strchr(*env, '=');
        if (delim != NULL) {
            // Compare the name part of the environment variable
            if (strncmp(*env, name, delim - *env) == 0) {
                // Return the value part of the environment variable
                return delim + 1;
            }
        }
    }
    // Environment variable not found
    return NULL;
}

int main() {
    // Test the _getenv function
    char* path = _getenv("PATH");
    if (path != NULL) {
        printf("PATH = %s\n", path);
    } else {
        printf("PATH environment variable not found\n");
    }
    return 0;
}

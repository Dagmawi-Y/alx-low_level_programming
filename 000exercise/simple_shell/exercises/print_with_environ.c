#include <stdio.h>

// Declare the extern variable environ
extern char** environ;

int main() {
    // Iterate through the environ array
    for (char** env = environ; *env != NULL; ++env) {
        // Print each environment variable
        printf("%s\n", *env);
    }
    return 0;
}

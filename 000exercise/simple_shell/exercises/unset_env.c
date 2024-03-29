#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the extern variable environ
extern char** environ;

int _unsetenv(const char* name) {
    // Count the number of environment variables
    int num_vars;
    for (num_vars = 0; environ[num_vars] != NULL; ++num_vars) {}

    // Allocate memory for the new environ array
    char** new_environ = malloc((num_vars + 1) * sizeof(char*));
    if (new_environ == NULL) {
        perror("malloc");
        return -1;
    }

    // Copy the existing environment variables to the new array,
    // excluding the variable we want to remove
    int new_index = 0;
    for (int i = 0; i < num_vars; ++i) {
        char* delim = strchr(environ[i], '=');
        if (delim != NULL && strncmp(environ[i], name, delim - environ[i]) != 0) {
            // Copy the variable if its name is not equal to the one we want to remove
            new_environ[new_index++] = environ[i];
        }
    }

    // Terminate the new environ array with NULL
    new_environ[new_index] = NULL;

    // Replace the original environ with the new_environ
    environ = new_environ;

    return 0;
}

int main() {
    // Set some environment variables for testing
    setenv("MYVAR", "hello", 1);
    setenv("PATH", "/new/path", 1);

    // Unset the MYVAR variable
    _unsetenv("MYVAR");

    // Print the modified environment
    for (char** env = environ; *env != NULL; ++env) {
        printf("%s\n", *env);
    }

    return 0;
}

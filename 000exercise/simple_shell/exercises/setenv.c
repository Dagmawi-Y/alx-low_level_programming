#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the extern variable environ
extern char** environ;

int _setenv(const char* name, const char* value, int overwrite) {
    // Check if the variable already exists in the environment
    for (char** env = environ; *env != NULL; ++env) {
        char* delim = strchr(*env, '=');
        if (delim != NULL && strncmp(*env, name, delim - *env) == 0) {
            // Variable already exists
            if (overwrite) {
                // Overwrite the existing value
                char* new_env = malloc(strlen(name) + strlen(value) + 2);
                if (new_env == NULL) {
                    perror("malloc");
                    return -1;
                }
                sprintf(new_env, "%s=%s", name, value);
                free(*env); // Free the existing environment variable
                *env = new_env;
                return 0;
            } else {
                // Don't overwrite if overwrite flag is not set
                return 0;
            }
        }
    }

    // Variable doesn't exist, so add it to the environment
    char* new_env = malloc(strlen(name) + strlen(value) + 2);
    if (new_env == NULL) {
        perror("malloc");
        return -1;
    }
    sprintf(new_env, "%s=%s", name, value);

    // Count the number of environment variables
    int num_vars;
    for (num_vars = 0; environ[num_vars] != NULL; ++num_vars) {}

    // Allocate memory for the new environ array
    char** new_environ = malloc((num_vars + 2) * sizeof(char*));
    if (new_environ == NULL) {
        perror("malloc");
        free(new_env);
        return -1;
    }

    // Copy the existing environment variables to the new array
    for (int i = 0; i < num_vars; ++i) {
        new_environ[i] = environ[i];
    }

    // Add the new variable to the environ array
    new_environ[num_vars] = new_env;
    new_environ[num_vars + 1] = NULL;

    // Replace the original environ with the new_environ
    environ = new_environ;

    return 0;
}

int main() {
    // Test the _setenv function
    _setenv("MYVAR", "hello", 1); // Add or overwrite MYVAR with "hello"
    _setenv("PATH", "/new/path", 0); // Don't overwrite PATH if it already exists

    // Print the modified environment
    for (char** env = environ; *env != NULL; ++env) {
        printf("%s\n", *env);
    }

    return 0;
}

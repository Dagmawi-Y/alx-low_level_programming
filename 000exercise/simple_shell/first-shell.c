#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        // Display prompt
        printf("#cisfun$ ");
        fflush(stdout);

        // Read command from user
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        // Remove newline character from command
        command[strcspn(command, "\n")] = '\0';

        // Fork a child process
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execlp(command, command, NULL); // Execute command
            perror("execlp"); // If execlp fails
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            wait(&status); // Wait for child to finish
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t pid;
    char *args[] = {"ls", "-l", "/tmp", NULL};

    // Create 5 child processes
    for (i = 0; i < 5; i++) {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            printf("Child %d executing ls -l /tmp:\n", i+1);
            execve("/bin/ls", args, NULL);
            perror("execve"); // This line is reached only if execve fails
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL); // Wait for the child process to finish
            printf("Child %d exited.\n", i+1);
        }
    }

    return 0;
}

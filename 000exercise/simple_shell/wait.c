#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    pid_t pid, wpid;
    int status;

    pid = fork(); // Create a child process
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process executing...\n");
        sleep(2); // Simulate some work
        printf("Child process exiting\n");
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("Parent process waiting for child...\n");
        wpid = wait(&status); // Wait for child process to terminate
        if (wpid == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        printf("Child process with PID %d terminated with status %d\n", wpid, WEXITSTATUS(status));
    }

    return 0;
}

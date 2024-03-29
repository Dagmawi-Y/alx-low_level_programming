#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10;
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Fibonacci of %d in child process: %d\n", n, fibonacci(n));
    } else {
        // Parent process
        printf("Fibonacci of %d in parent process: %d\n", n, fibonacci(n));
    }

    return 0;
}

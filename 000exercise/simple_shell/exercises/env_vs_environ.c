#include <stdio.h>

// Declare the extern variable environ
extern char** environ;

int main(int argc, char *argv[], char *env[]) {
    // Print the addresses of env and environ
    printf("Address of env: %p\n", env);
    printf("Address of environ: %p\n", environ);

    return 0;
}

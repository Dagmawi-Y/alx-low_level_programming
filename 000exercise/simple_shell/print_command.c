#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[256]; // Buffer to store the input line

    printf("$ "); // Print the prompt
    while (fgets(line, sizeof(line), stdin) != NULL) // Read input line by line
    {
        if (strcmp(line, "exit\n") == 0)
            break;
        printf("%s", line); // Print the entered command
        printf("$ "); // Print the prompt again
    }

    return 0; // Return 0 to indicate successful execution
}

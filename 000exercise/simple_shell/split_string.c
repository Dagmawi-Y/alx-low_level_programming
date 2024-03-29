#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 500 // Maximum number of words in the input string

char **split_string(char *str, int *num_words)
{
    char **words = malloc(MAX_WORDS * sizeof(char *)); // Allocate memory for array of pointers
    if (words == NULL) // Check if memory allocation failed
    {
        fprintf(stderr, "Memory allocation failed\n"); // Print error message
        exit(EXIT_FAILURE); // Exit the program with failure status
    }

    char *token = strtok(str, " "); // Tokenize the string using space as delimiter
    *num_words = 0; // Initialize number of words to 0
    while (token != NULL) // Loop through each token
    {
        words[*num_words] = strdup(token); // Allocate memory for each word and store in array
        (*num_words)++; // Increment number of words
        token = strtok(NULL, " "); // Get next token
    }

    return words; // Return the array of words
}

int main(void)
{
    char str[] = "This is a test string"; // Input string
    int num_words; // Variable to store number of words
    char **words = split_string(str, &num_words); // Call split_string function

    printf("Number of words: %d\n", num_words); // Print number of words
    for (int i = 0; i < num_words; i++)
    { // Loop through each word
        printf("Word %d: %s\n", i + 1, words[i]); // Print each word
        free(words[i]); // Free memory allocated for each word
    }
    free(words); // Free memory allocated for array of pointers

    return 0; // Return 0 to indicate successful execution
}

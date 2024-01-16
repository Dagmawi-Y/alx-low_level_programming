#include "main.h"
#include <stdlib.h>

/**
 * string_duplicate - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer of an array of chars
 */
char *_strdup(char *str)
{
    char *str_copy;
    unsigned int i, j;

    if (str == NULL)
        return (NULL);

    /* Calculate the length of the input string */
    for (i = 0; str[i] != '\0'; i++)
        ;

    /* Allocate memory for the duplicated string */
    str_copy = (char *)malloc(sizeof(char) * (i + 1));

    if (str_copy == NULL)
        return (NULL);

    /* Copy the string to the newly allocated memory */
    for (j = 0; j <= i; j++)
        str_copy[j] = str[j];

    return (str_copy);
}

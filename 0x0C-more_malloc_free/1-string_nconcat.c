#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: amount of bytes.
 *
 * Return: pointer to the allocated memory.
 * if malloc fails, status value is equal to 98.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int len_str1, len_str2, len_result, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (len_str1 = 0; s1[len_str1] != '\0'; len_str1++)
		;

	for (len_str2 = 0; s2[len_str2] != '\0'; len_str2++)
		;

	if (n > len_str2)
		n = len_str2;

	len_result = len_str1 + n;

	result = malloc(len_result + 1);

	if (result == NULL)
		return (NULL);

	for (i = 0; i < len_result; i++)
		if (i < len_str1)
			result[i] = s1[i];
		else
			result[i] = s2[i - len_str1];

	result[i] = '\0';

	return (result);
}

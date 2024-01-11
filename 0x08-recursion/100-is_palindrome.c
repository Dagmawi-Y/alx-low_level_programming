#include "main.h"

/**
 * is_palindrome_helper - Helper function to check if a string is a palindrome.
 * @s: Input string.
 * @start: Starting index.
 * @end: Ending index.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (is_palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - Returns 1 if a string is a palindrome, 0 otherwise.
 * @s: Input string.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int length = 0;

	/* Calculate the length of the string */
	while (s[length] != '\0')
		length++;

	return (is_palindrome_helper(s, 0, length - 1));
}

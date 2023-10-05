#include <stdlib.h>
#include "main.h"

/**
 * get_word_count - helper function to count the number of words in a string
 * @str: string to evaluate
 *
 * Return: number of words
 */
int get_word_count(char *str)
{
	int word_flag, count, word_count;

	word_flag = 0;
	word_count = 0;

	for (count = 0; str[count] != '\0'; count++)
	{
		if (str[count] == ' ')
			word_flag = 0;
		else if (word_flag == 0)
		{
			word_flag = 1;
			word_count++;
		}
	}

	return (word_count);
}

/**
 * **split_string - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **split_string(char *str)
{
	char **word_matrix, *temp;
	int i, index = 0, length = 0, word_count, count = 0, start, end;

	while (*(str + length))
		length++;
	word_count = get_word_count(str);
	if (word_count == 0)
		return (NULL);

	word_matrix = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (word_matrix == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (count)
			{
				end = i;
				temp = (char *)malloc(sizeof(char) * (count + 1));
				if (temp == NULL)
					return (NULL);
				while (start < end)
					*temp++ = str[start++];
				*temp = '\0';
				word_matrix[index] = temp - count;
				index++;
				count = 0;
			}
		}
		else if (count++ == 0)
			start = i;
	}

	word_matrix[index] = NULL;

	return (word_matrix);
}

#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: pointer of an array of char
 */
char *argstostr(int argc, char **argv)
{
	char *newstr;
	int total_chars, i, j, index;

	if (argc == 0)
		return (NULL);

	for (total_chars = i = 0; i < argc; i++)
	{
		if (argv[i] == NULL)
			return (NULL);

		for (j = 0; argv[i][j] != '\0'; j++)
			total_chars++;
		total_chars++;
	}

	newstr = malloc((total_chars + 1) * sizeof(char));

	if (newstr == NULL)
	{
		free(newstr);
		return (NULL);
	}

	for (i = j = index = 0; index < total_chars; j++, index++)
	{
		if (argv[i][j] == '\0')
		{
			newstr[index] = '\n';
			i++;
			index++;
			j = 0;
		}
		if (index < total_chars - 1)
			newstr[index] = argv[i][j];
	}
	newstr[index] = '\0';

	return (newstr);
}

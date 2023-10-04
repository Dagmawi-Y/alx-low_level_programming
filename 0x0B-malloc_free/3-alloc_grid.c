#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of the array.
 * @height: height of the array.
 *
 * Return: pointer of an array of integers
 */
int **alloc_grid(int width, int height)
{
	int **newgrid;
	int i, j;

	if (width < 1 || height < 1)
		return (NULL);

	newgrid = malloc(height * sizeof(int *));
	if (newgrid == NULL)
	{
		free(newgrid);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		newgrid[i] = malloc(width * sizeof(int));
		if (newgrid[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(newgrid[i]);
			free(newgrid);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			newgrid[i][j] = 0;

	return (newgrid);
}

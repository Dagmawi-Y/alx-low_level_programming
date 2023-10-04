#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid.
 * @newgrid: multidimensional array of integers.
 * @height: height of the grid.
 *
 * Return: no return
 */
void free_grid(int **newgrid, int height)
{
	if (newgrid != NULL && height != 0)
	{
		for (; height >= 0; height--)
			free(newgrid[height]);
		free(newgrid);
	}
}

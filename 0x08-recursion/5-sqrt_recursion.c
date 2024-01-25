#include "main.h"

/**
 * _sqrt_helper - Returns the natural square root of a number.
 * @n: Input number.
 * @iterator: Iterator.
 *
 * Return: Square root or -1.
 */
int _sqrt_helper(int n, int iterator)
{
	if (iterator * iterator == n)
		return (iterator);
	else if (iterator * iterator > n)
		return (-1);
	else
		return (_sqrt_helper(n, iterator + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: Input number.
 *
 * Return: Natural square root or -1.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	return (_sqrt_helper(n, 1));
}

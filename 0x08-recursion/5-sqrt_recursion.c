#include "main.h"

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of the number or -1 if no natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	return (_sqrt_helper(n, 1, n / 2 + 1));
}

/**
 * _sqrt_helper - Helper function for binary search.
 * @n: The number to calculate the square root of.
 * @start: The starting point of the search range.
 * @end: The ending point of the search range.
 *
 * Return: The square root of the number or -1 if no natural square root.
 */
int _sqrt_helper(int n, int start, int end)
{
	if (start > end)
		return (-1);

	int mid = (start + end) / 2;
	long long mid_squared = (long long)mid * mid;

	if (mid_squared == n)
		return (mid);
	else if (mid_squared < n)
		return (_sqrt_helper(n, mid + 1, end));
	else
		return (_sqrt_helper(n, start, mid - 1));
}

#include "main.h"

/**
 * is_prime_helper - Helper function to check if a number is prime.
 * @n: Input number.
 * @divisor: Current divisor to check.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_helper(int n, int divisor)
{
	if (n < 2)
		return (0);

	if (divisor > n / 2)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (is_prime_helper(n, divisor + 1));
}

/**
 * is_prime_number - Returns 1 if the input integer is a prime number,
 * otherwise returns 0.
 * @n: Input number.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	return (is_prime_helper(n, 2));
}

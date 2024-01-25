#include <stdio.h>
#include <stdarg.h>

/**
* sum_them_all - sum of all its parameters
* @n: n args
* Return: sum or if n == 0, return 0
*/
int sum_them_all(const unsigned int n, ...)
{
    int sum = 0;
    unsigned int i;
    va_list count;

    if (n)
    {
        va_start(count, n);
        for (i = 0; i < n; i++)
        {
            sum += va_arg(count, int);
        }
        va_end(count);
    }
    return (sum);
}

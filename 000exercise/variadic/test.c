#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
    int result = 0;
    va_list args;
    va_start(args, count);

    for(int i = 0; i < count; i++)
    {
        result += va_arg(args, int);
    }

    va_end(args);

    return result;
}

int main()
{
    printf("Sum: %d", sum(1, 2, 3, 4));
    return 0;
}
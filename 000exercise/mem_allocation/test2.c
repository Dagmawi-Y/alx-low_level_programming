#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


bool divide(int a, int b, bool *d) {
    int c = a / b;

    if (c * b == a) {
        *(d) = true;
    } else {
        *(d) = false;
    }
    return c;
}

int main()
{
    int numerator = 10;
    int denominator = 5;
    bool divisible;
    int result = divide(numerator, denominator, divisible);
}


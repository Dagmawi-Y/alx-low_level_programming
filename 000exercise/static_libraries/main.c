#include <stdio.h>
#include "main.h"

int main(void) {
    int a, b, sum, sub;
    a = 5;
    b = 5;
    sum = add(a, b);
    sub = subtract(a, b);
    printf("%d + %d = %d\n", a, b, sum);
    printf("%d - %d = %d\n", a, b, sub);
    return (0);
}
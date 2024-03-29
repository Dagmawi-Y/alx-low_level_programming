#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr2;
    int x = 10;
    ptr2 = &x;
    printf("%d\n", *ptr2);


    int *ptr;
    ptr = (int*) malloc(5 * sizeof (int));
    printf("%p\n", ptr);
    free(ptr);
}

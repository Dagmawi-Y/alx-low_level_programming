#include <stdio.h>

void fun(int a)
{
    printf("The number is: %d\n", a);
}

int main()
{
    void(*fun_ptr)(int);
    fun_ptr = &fun;

    (*fun_ptr)(10);

    return 0;
}

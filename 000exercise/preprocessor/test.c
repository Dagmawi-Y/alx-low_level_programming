//
// Created by Daggy on 1/23/2024.
//
#include <stdio.h>
#define MY_VARIABLE 23
#define SQUARE(X) (X * X)
#define PI 3.14

int main(){
    double radius = 4.5;
    double area = PI * SQUARE(radius);
    printf("%f", area);
    return 0;
}

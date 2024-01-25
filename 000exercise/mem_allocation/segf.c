#include <stdio.h>
//
// Created by Daggy on 1/18/2024.
//
/**
 * segf - Let's segfault \o/
 *
 * Return: nothing.
 */
void segf(void) {
    char *str;

    str = "Holberton";
    str[0] = 's';
    printf("%s", str);
}

/**
 *  main - concept introduction
 *
 * Return: 0.
 */
int main(void) {
    segf();
    return (0);
}
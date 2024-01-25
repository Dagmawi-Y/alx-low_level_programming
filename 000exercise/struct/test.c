//
// Created by Daggy on 1/23/2024.
//
#include <stdio.h>
struct User
{
    char *name;
    char *email;
    int age;
};

int main()
{
    struct User user;
    user.name = "Foo Bar";
    printf("%s",user.name);
}

#include <stdio.h>
#include <malloc.h>


struct Dog
{
    char *name;
};




int main()
{


    struct Dog *dogPointer;
    dogPointer = (struct Dog *) malloc(sizeof(struct Dog));
    dogPointer -> name = "Puppy";

    printf("%s\n", dogPointer->name);
    free(dogPointer);

    return 0;
}

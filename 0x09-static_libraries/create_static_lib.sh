#!/bin/bash
gcc -Wall -pedantic -Wextra -c *.c
ar -rc liball.a *.o

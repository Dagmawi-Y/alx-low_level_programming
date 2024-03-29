# 0x18-dynamic_libraries

This directory contains various C source files and scripts related to dynamic libraries. Below is a brief description of each file:

- `0-isupper.c`: Contains a function `int _isupper(int c)` that checks for uppercase characters.
- `0-main.c`: Main file to test the function `_isupper`.
- `0-memset.c`: Contains a function `char *_memset(char *s, char b, unsigned int n)` that fills memory with a constant byte.
- `0-strcat.c`: Contains a function `char *_strcat(char *dest, char *src)` that concatenates two strings.
- `1-create_dynamic_lib.sh`: Script to create a dynamic library called `liball.so` from all `.c` files in the current directory.
- `1-main.c`: Main file to test dynamic library creation.
- `1-memcpy.c`: Contains a function `char *_memcpy(char *dest, char *src, unsigned int n)` that copies memory area.
- `1-isdigit.c`: Contains a function `int _isdigit(int c)` that checks for a digit (0 through 9).
- `1-strncat.c`: Contains a function `char *_strncat(char *dest, char *src, int n)` that concatenates `n` bytes from source string to destination string.
- `100-atoi.c`: Contains a function `int _atoi(char *s)` that converts a string to an integer.
- `100-operations.so`: Dynamic library containing various mathematical operations.
- `101-make_me_win.sh`: Script to make you win the Jackpot of the `elf64` binary.
- `2-strchr.c`: Contains a function `char *_strchr(char *s, char c)` that locates a character in a string.
- `2-strlen.c`: Contains a function `int _strlen(char *s)` that returns the length of a string.
- `2-strncpy.c`: Contains a function `char *_strncpy(char *dest, char *src, int n)` that copies `n` characters from source string to destination string.
- `3-islower.c`: Contains a function `int _islower(int c)` that checks for lowercase characters.
- `3-main.c`: Main file to test the function `_islower`.
- `3-puts.c`: Contains a function `int _puts(char *str)` that prints a string, followed by a new line, to stdout.
- `3-strcmp.c`: Contains a function `int _strcmp(char *s1, char *s2)` that compares two strings.
- `3-strspn.c`: Contains a function `unsigned int _strspn(char *s, char *accept)` that gets the length of a prefix substring.
- `4-isalpha.c`: Contains a function `int _isalpha(int c)` that checks for alphabetic characters.
- `4-main.c`: Main file to test the function `_isalpha`.
- `4-strpbrk.c`: Contains a function `char *_strpbrk(char *s, char *accept)` that searches a string for any of a set of bytes.
- `5-strstr.c`: Contains a function `char *_strstr(char *haystack, char *needle)` that locates a substring.
- `6-abs.c`: Contains a function `int _abs(int n)` that computes the absolute value of an integer.
- `_putchar.c`: Contains a function `_putchar` to print a character.
- `9-strcpy.c`: Contains a function `char *_strcpy(char *dest, char *src)` that copies a string.

## How to Use

1. Clone this repository to your local machine.
2. Navigate to the `0x18-dynamic_libraries` directory.
3. Compile the desired C files along with the dynamic library using gcc. For example:
    ```bash
    gcc -Wall -pedantic -Werror -Wextra -L. -ldynamic -o [output_file] [main_file.c]
    ```
4. Execute the compiled binary to test the functionality.

Make sure you have the necessary permissions to execute scripts and compile C files.

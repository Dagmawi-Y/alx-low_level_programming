# Search Algorithms

This project implements various search algorithms in C, including linear, binary, jump, interpolation, exponential, and advanced binary search.

## Algorithms

- **Linear Search**: `int linear_search(int *array, size_t size, int value);`  
  O(n)

- **Binary Search**: `int binary_search(int *array, size_t size, int value);`  
  O(log n)

- **Jump Search**: `int jump_search(int *array, size_t size, int value);`  
  O(√n)

- **Interpolation Search**: `int interpolation_search(int *array, size_t size, int value);`  
  O(log log n)

- **Exponential Search**: `int exponential_search(int *array, size_t size, int value);`  
  O(log n)

- **Advanced Binary Search**: `int advanced_binary(int *array, size_t size, int value);`  
  O(log n)

## Usage

Compile with:

```bash
gcc -Wall -Wextra -pedantic -std=gnu89 main.c algorithm_file.c -o output_name
```

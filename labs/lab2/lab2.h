#include <stdio.h>
#include <stdlib.h>

//prototypes
int makeArray(int **array, int size);
void initArray(int *array, int size);
int multiplyOdd(int *array, int size, int multiplicand);
void freeArray(int **array);
void printArray(int * array, int size);
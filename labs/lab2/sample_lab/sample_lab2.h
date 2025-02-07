#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

float* appendToArray(float* array, int* size, int* capacity, float value);
void freeArray(float** array);
void printArray(float array[], int size);
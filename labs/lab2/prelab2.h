#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

float * copyFloatArray(float input_array[], int* output_length);
void freeFloatArray(float** arrayptr);
void printArray(float array[], int size);
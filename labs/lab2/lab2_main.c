#include "lab2.h"
#define SIZE 10

int main(void){
    int* array = NULL;
    makeArray(&array, SIZE);
    initArray(array, SIZE);
    array[2] = 3;
    int count = multiplyOdd(array, SIZE, 3);
    printf("Count multiplied: %d\n", count);
    printArray(array, SIZE);

    printf("\narray address before free: %p\n", array);
    freeArray(&array);
    printf("array address after free: %p", array);
    return 0;
}
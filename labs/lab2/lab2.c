#include "lab2.h"


int makeArray(int **array, int size){
    if(array== NULL || size == 0){
        return 1;
    }
    *array = malloc(sizeof(int) * size);
    return 0;
}

void initArray(int *array, int size){
    if(array!= NULL && size != 0){
        for(int i=0; i<size; i++){
            array[i] = 0;
        }
    }
    
}

int multiplyOdd(int *array, int size, int multiplicand){
    if(array== NULL || size == 0){
        return -1;
    }
    int count = 0;
    for(int i=0; i<size; i++){
        if(array[i] % 2 != 0){
            array[i] *= multiplicand;
            count++;
        }
    }
    return count;
    
}

void freeArray(int **array){
    if(array != NULL && *array!=NULL){
        free(*array);
        *array = NULL;
    }
}

void printArray(int * array, int size){
    if(array!=NULL && size != 0){
        for(int i=0; i<size; i++){
            printf("%d ", array[i]);
        }
    }
}

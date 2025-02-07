#include "sample_lab2.h"


float* appendToArray(float* array, int* size, int* capacity, float value){
    if(array == NULL || (*capacity) == 0){
        return NULL;
    }
    if((*size) == (*capacity)){
        (*capacity) = (*capacity) * 2;
        size_t temp = (*capacity) * sizeof(float);
        float * temparr = realloc(array, temp);
        if(temparr == NULL){
            return array;
        }
        array= temparr;

    }
    array[(*size)] = value;
    (*size)++;
    return array;
}

void freeArray(float** array){
    if(array != NULL && *array != NULL){
        free(*array);
        *array = NULL;
    }
}

void printArray(float array[], int size){
    printf("[");
    for(int i=0; i<size-1; i++){
        printf("%f, ",array[i]);
    }
    printf("%f",array[size-1]);
    printf("]");
    printf("\n");
}
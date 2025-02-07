#include "prelab2.h"

float * copyFloatArray(float input_array[], int* output_length){
    int count = 1; //count starts at 1 to fix off by one error
    int i = 0;
    while(input_array[i++] != 0.0){
        count++;
    }
    *output_length = count;
    float* array_copy = malloc(count * sizeof(float));

    if(array_copy == NULL){
        return NULL;
    }
    
    for(int i=0; i<count; i++){
        array_copy[i] = input_array[i];
    }
    return array_copy;
}


void freeFloatArray(float** arrayptr){
    if(arrayptr != NULL && *arrayptr != NULL){
        free(*arrayptr);
        *arrayptr = NULL;
    }
}

void printArray(float array[], int size){
    if(array != NULL && size != 0){
        printf("Start:\n");
    for(int i=0; i<size; i++){
        printf("array[%d] = %f\n",i,array[i]);
    }
        printf("End.\n");
    }
}
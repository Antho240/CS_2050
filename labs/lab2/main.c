#include "prelab2.h"
#define SIZE 5

int main(void){
    //print orginal array
    float array[SIZE] = {1.0,2.0,3.0,4.0,0.0};
    printf("Orginal Array:\n");
    printArray(array,SIZE);

    // allocate copy of orginal array
    int count = 0;
    float * copy_array = NULL;
    copy_array = copyFloatArray(array, &count);
    if(copy_array == NULL){
        printf("Memory Allocation failed\n");
        return 1;
    }

    //print copied array
    printf("\nCopied array:\n");
    printArray(copy_array,count);

    //free memory and check for leaks
    freeFloatArray(&copy_array);
    if(copy_array == NULL){
        printf("Memory succesfully freed!\n");
    }
    else{
        printf("Memory not freed. Check for memory leaks.\n");
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "prelab.h"
#define SIZE 10

int main(void){
    int array[SIZE] = {-1000,1000,4,5,6,11000,-8000,10,4,4};
    int max = 0;
    int min = 0;
    int count=0;
    count = getArrayInfo(array, SIZE, &max, &min);
    printf("count: %d, max: %d, min: %d", count, max, min);

}
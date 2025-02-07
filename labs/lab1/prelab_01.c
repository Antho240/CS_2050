#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getArrayInfo(int array[], int size, int* max, int* min){
    *min = INT_MAX;
    *max = INT_MIN;
    int count = 0;
    for(int i=0; i<size; i++){
        if(array[i] > (*max)){
            *max = array[i];
        }
        if(array[i] < (*min)){
            *min = array[i];
        }
    }
    int range = *max - *min + 1;
    int* set = calloc((range),sizeof(int));
    if(!set){
        printf("Memory allocation failed!");
    }

    for(int i=0; i<size; i++){
        int index = array[i] - *min;
        if(set[index]!=0){
            continue;
        }
        else{
            set[index]++;
            count++;
        }
    }
    free(set);
    return count;
}
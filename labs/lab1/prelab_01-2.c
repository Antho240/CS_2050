#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define HASH_SIZE 10007 //Prime number to prevent collsions


/*typedef struct{
    int value;
}element;*/

unsigned int hash(int num){
    return abs(num) % HASH_SIZE;
}

//element* hash_table[HASH_SIZE];

void hash_table_init(int hash_table[HASH_SIZE]){
    for(int i=0; i<HASH_SIZE; i++){
        hash_table[i] = 0;
    }
}

int hash_insert(int num, int hash_table[HASH_SIZE]){
    int index = num % HASH_SIZE;
    if(hash_table[index] == 0){
        hash_table[index] = num;
        return 1;
    }
    return 0;
}

int getArrayInfo(int array[], int size, int* max, int* min, int hash_table[HASH_SIZE]){
    *min = INT_MAX;
    *max = INT_MIN;
    int count = 0;
    hash_table_init(hash_table);
    for(int i=0; i<size; i++){
        if(array[i] > (*max)){
            *max = array[i];
        }
        if(array[i] < (*min)){
            *min = array[i];
        }

        if(hash_insert(array[i], hash_table)){
            count++;
        }

    }
    return count;
    
}
#include "prelab-2.h"
#define SIZE 9

int main(void){
    int hash_table[HASH_SIZE];
    int array[SIZE] = {4,5,6,7,-1000,1000,-100000,69,69};
    int max = 0;
    int min = 0;
    int count=0;
    count = getArrayInfo(array, SIZE, &max, &min, hash_table);
    printf("count: %d, max: %d, min: %d", count, max, min);

}
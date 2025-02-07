#include "sample_lab2.h"

int main(void){
    int size = 0;
    int capacity = 2;
    float* array = malloc(capacity * sizeof(float));
    float temp = 0.0;
    int current_cap = capacity;
    for(int i=0; i<7; i++){
        array = appendToArray(array, &size, &capacity, temp);
        printf("Appending %f...",temp);
        if(current_cap != capacity){
            current_cap = capacity;
            printf(" (Array resized to capacity %d)", capacity);
        }
        printf("\n");
        temp+=1.1;
    }

    printArray(array, size);
    printf("Final size: %d\n",size);
    printf("Final capacity: %d\n",capacity);

    freeArray(&array);
    if(array == NULL){
        printf("Memory freed successfully!\n");
    }
    
    return 0;
}
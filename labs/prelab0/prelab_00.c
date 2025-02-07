#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 10

int occurrences(int array[], int size, int key);
void printArray(int array[],int size);

int main(void){
    srand(time(NULL));
    int array[SIZE]={0};
    for(int i=0; i<SIZE; i++){
        int temp = (rand()%100)+1;
        array[i] = temp;
    }
    int key = 0;
    printf("Random intialized array:\n");
    printArray(array, SIZE);
    printf("\n");
    printf("Enter your key: ");
    scanf("%d",&key);
    int result = occurrences(array, SIZE, key);
    printf("There are %d numbers >= to %d",result,key);



    return 0;
}

int occurrences(int array[], int size, int key){
    int count=0;
    for(int i=0; i<size; i++){
        if(array[i]>= key){
            count++;
        }
    }
    return count;
}
void printArray(int array[],int size){
    for(int i=0; i<SIZE; i++){
        printf("%d ",array[i]);
    }
}
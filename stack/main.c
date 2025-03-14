#include "stack.h"

int main(void){
    Stack* stack = stackInit();
    int int_data1 = 1000;
    int int_data2 = 2000;
    int int_data3 = 3000;
    int int_data4 = 4000;
    void* data1 = &int_data1;
    void* data2 = &int_data2;
    void* data3 = &int_data3;
    void* data4 = &int_data4;
    if(push(stack, data1)){
        printf("***failed to push***\n");
    }
    if(push(stack, data2)){
        printf("***failed to push***\n");
    }
    if(push(stack, data3)){
        printf("***failed to push***\n");
    }
    if(push(stack, data4)){
        printf("***failed to push***\n");
    }
    void* popped = pop(stack);
    printf("Data popped: %d\n", *((int*)popped));
    popped = pop(stack);
    printf("Data popped: %d\n", *((int*)popped));
    freeStack(stack);
    return 0;
}
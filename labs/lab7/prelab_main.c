#include "prelab7.h"

int main(void){
    Queue* queue = queueInit();
    if(queue == NULL){
        printf("***failed to initialize queue***\n");
    }
    int int_data1 = 1000;
    int int_data2 = 2000;
    int int_data3 = 3000;
    void* data1 = &int_data1;
    void* data2 = &int_data2;
    void* data3 = &int_data3;
    if(enqueue(data1, queue)){
        printf("***failed to insert into queue***\n");
    }
    if(enqueue(data2, queue)){
        printf("***failed to insert into queue***\n");
    }
    if(enqueue(data3, queue)){
        printf("***failed to insert into queue***\n");
    }
    int size = getQueueSize(queue);
    printf("Size of queue: %d\n", size);
    void* data_dequeued = dequeue(queue);
    printf("Data removed from queue: %d\n", *((int*)data_dequeued));
    size = getQueueSize(queue);
    printf("New size of queue: %d\n", size);
    int errorCode = getQueueErrorCode(queue);
    printf("Error Code of most recent action: %d\n",errorCode);
    freeQueue(queue);
    return 0;
}
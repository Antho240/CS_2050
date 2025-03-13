#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    void* data;
    Node *next;
};
typedef struct Queue Queue;
struct Queue{
    Node* front;
    Node* rear;
    int size;
    int errorCode;
};

int getQueueErrorCode(Queue* queue);
Queue* queueInit();
int enqueue(void* data, Queue* queue);
void* dequeue(Queue* queue);
int getQueueSize(Queue* queue);
void freeQueue(Queue* queue);
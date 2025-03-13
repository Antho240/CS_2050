#include "prelab7.h"

int getQueueErrorCode(Queue* queue){
    if(queue == NULL){
        return 1;
    }
    return queue->errorCode;
}

Queue* queueInit(){
    Queue* queue = malloc(sizeof(Queue));
    if(queue){
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
        queue->errorCode = 0;
    }
    return queue;
}

int enqueue(void* data, Queue* queue){
    if(queue==NULL){
        return 1;
    }
    Node* node = malloc(sizeof(Node));
    if(node == NULL){
        queue->errorCode = 1;
        return 1;
    }
    node->data = data;
    if(queue->size == 0){
        queue->front = node;
        queue->rear = node;
        node->next = NULL;
    }
    else{
        queue->rear->next = node;
        node->next = NULL;
        queue->rear = node;
    }
    queue->size = queue->size + 1;
    queue->errorCode = 0;
    return 0;
}

void* dequeue(Queue* queue){
    if(queue == NULL){
        return NULL;
    }
    if(queue->size == 0){
        queue->errorCode = 2;
        return NULL;
    }
    void* data_returned = queue->front->data;
    Node* node_deleted = queue->front;
    queue->front = queue->front->next;
    free(node_deleted);
    queue->size = queue->size - 1;
    queue->errorCode = 0;
    return data_returned;
}

int getQueueSize(Queue* queue){
    if(queue == NULL){
        return 0;
    }
    return queue->size;
}

void freeQueue(Queue* queue){
    if(queue == NULL){
        return;
    }
    Node* currentNode = queue->front;
    Node* nextNode = currentNode;
    while(currentNode != NULL){
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    free(queue);
}
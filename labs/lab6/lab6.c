// Anthony Stuart           03/07/2025          ansmvf
#include "lab6.h"
#include <stdio.h>
#include <stdlib.h>
int makeList(Node **list){
    if(list == NULL){
        return 1;
    }
    *list = malloc(sizeof(Node));
    if(*list){
        (*list)->data = NULL;
        (*list)->next= NULL;
        return 0;
    }
    return 1;
}

int getSize(Node *list){
    if(list == NULL){
        return 0;
    }
    Node* nextNode = list->next;
    int size = 0;
    while(nextNode != NULL){
        nextNode = nextNode->next;
        size++;
    }
    return size;
}

void * getAtIndex(Node *list, int index){
    int length = getSize(list);
    if(list == NULL || index < 0 || index >= length){
        return NULL;
    }
    Node* currentNode;
    if(list->next == NULL){
        currentNode = list;
    }
    else{
        currentNode = list->next;
    }
    int currentIndex = 0;
    while(currentNode != NULL && currentIndex < index){
        currentNode = currentNode->next;
        currentIndex++;        
    }
    if(currentNode){
        return currentNode->data;
    }
    return NULL;
}

int insertAtTail(Node *list, void *data){
    if(list == NULL){
        return 1;
    }
    Node* currentNode;
    if(list->next == NULL){
        currentNode = list;
    }
    else{
        currentNode = list->next;
    }
    Node* temp;
    Node* newNode = malloc(sizeof(*newNode));
    if(newNode){
        while(currentNode != NULL){
            temp = currentNode;
            currentNode = currentNode->next;
        }
        temp->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
        return 0;
    }
    return 1;
}

void * removeFromHead(Node *list){
    if(list == NULL){
        return NULL;
    }
    if(list->next == NULL){
        return NULL;
    }
    Node* head = list->next;
    list->next = head->next;
    void* removedData = head->data;
    free(head);
    return removedData;
}

void freeList(Node **list){
    if(list == NULL){
        return;
    }
    Node* head = *list;
    Node* nextNode = head;
    while(head != NULL){
        nextNode = head->next;
        free(head);
        head = nextNode;
    }
    *list = NULL;
}
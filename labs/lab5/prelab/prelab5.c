#include "prelab5.h"

LinkedList* intializeLinkedList(int* errorCode){
    LinkedList* p;
    p = malloc(sizeof(*p));
    if(p){
        p->next = NULL;
        p->object =0;
        *errorCode = 0;
    }
    else{
       *errorCode=1; 
    }
    return p;
}

LinkedList* insertAtHead(int object, LinkedList* head, int* errorCode){
    if(head == NULL){
        *errorCode = 1;
        return head;
    }

    LinkedList* newNode = malloc(sizeof(LinkedList));
    if(newNode){
        newNode->next = head;
        newNode->object = object;
        *errorCode = 0;
    }
    else{
        *errorCode = 1;
        return head;
    }
    return newNode;
}

int getIndex(int index, LinkedList* head){
    if(head == NULL || index < 1){
        return 0;
    }
    LinkedList* current = head;
    int currentIndex = 1;
    while(current != NULL && currentIndex < index){
        current = current->next;
        currentIndex++;
    }
    if(current){
        return current->object;
    }
    return 0;

}

int getLinkedListLength(LinkedList* head){
    if(head == NULL){
        return 0;
    }
    int length = 0;
    LinkedList* current = head;
    while(current != NULL){
        current = current->next;
        length++;
    }
    return length;
}

LinkedList* freeLinkedList(LinkedList* head){
    if(head == NULL){
        return NULL;
    }
    LinkedList* current = head;
    LinkedList* nextNode;
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    return NULL;
}
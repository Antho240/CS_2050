#include "prelab6.h"

LinkedList* intializeLinkedList(int* errorCode){
    LinkedList* dummyNode;
    dummyNode = malloc(sizeof(*dummyNode));
    if(dummyNode){
        dummyNode->object = INT_MIN;
        dummyNode->next = NULL;
        *errorCode = 0;
    }
    else{
        *errorCode = 1;
    }
    return dummyNode;
}

LinkedList* insertAtHead(int object, LinkedList* head, int* errorCode){
    if(head == NULL){
        *errorCode = 1;
        return head;
    }
    LinkedList* newNode = malloc(sizeof(*newNode));
    if(newNode){
       newNode->next = head->next;
       head->next = newNode;
       newNode->object = object;
       *errorCode = 0;
    }
    else{
        *errorCode = 1;
    }
    return head;

}

LinkedList* insertAtTail(int object, LinkedList* head, int* errorCode){
    if(head == NULL){
        return head;
    }
    LinkedList* newNode = malloc(sizeof(*newNode));
    LinkedList* current = head->next;
    LinkedList* temp;
    if(newNode){
        while(current != NULL){
            temp = current;
            current = current->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
        newNode->object = object;
        *errorCode = 0;
    }
    else{
        *errorCode = 1;
    }
    return head;
}

int getIndex(int index, LinkedList* head){
    if(head == NULL || index < 1){
        return 0;
    }
    LinkedList* currentNode = head->next;
    int currentIndex = 1;
    while(currentNode != NULL && currentIndex < index){
        currentNode = currentNode->next;
        currentIndex++;        
    }
    if(currentNode){
        return currentNode->object;
    }
    return 0;
}

int getLinkedListLength(LinkedList* head){
    if(head == NULL){
        return 0;
    }
    LinkedList* node = head->next;
    int length = 0;
    while(node != NULL){
        node = node->next;
        length++;
    }
    return length;
}

LinkedList* freeLinkedList(LinkedList* head){
    if(head == NULL){
        return head;
    }
    LinkedList* nextNode;
    while(head != NULL){
        nextNode = head->next;
        free(head);
        head = nextNode;
    }
    return NULL;
}
// Anthony Stuart           02/28/2025          ansmvf
#include "lab5.h"

Node* initList(){
    Node* p;
    p = malloc(sizeof(*p));
    if(p){
        p->next = NULL;
        p->data =0;
    }
    return p;
}

void freeList(Node* head){
    if(head == NULL){
        return;
    }
    Node* current = head;
    Node* nextNode;
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

Node * insertAtTail(Node *head, int data, int *error){
    if(head == NULL){
        *error = 1;
        return NULL;
    }
    Node* newNode = malloc(sizeof(Node));
    if(newNode){
        newNode->data = data;
        newNode->next = NULL;
        Node* current = head;
        Node* temp = current;
        while(current != NULL){ //goes to end of list
            temp = current;
            current = current->next;
        }
        temp->next = newNode;
        *error = 0;
    }
    else{
        *error = 1;
    }
    return head;
}

Node * removeFromHead(Node *head, int *data){
    if(head == NULL){
        return NULL;
    }
    Node* nextNode = head->next;
    *data = head->data;
    free(head);
    head = nextNode;
    return head;
}

void printList(Node *head){
    if(head == NULL){
        return;
    }
    Node* current = head;
    while(current != NULL){ 
        printf("%d\n",current->data);
        current = current->next;
    }
}

int listContains(Node *head, int data){
    if(head == NULL){
        return 0;
    }
    Node* current = head;
    while(current != NULL){
        if(current->data == data){
            return 1;
        }
        current = current->next;
    }
    return 0;
}
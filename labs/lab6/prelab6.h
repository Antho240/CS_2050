#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct linkedListStruct{
    int object;
    struct linkedListStruct * next;
}LinkedList;

LinkedList* intializeLinkedList(int* errorCode);
LinkedList* insertAtHead(int object, LinkedList* head, int* errorCode);
int getIndex(int index, LinkedList* head);
int getLinkedListLength(LinkedList* head);
LinkedList* freeLinkedList(LinkedList* head);
LinkedList* insertAtTail(int object, LinkedList* head, int* errorCode);
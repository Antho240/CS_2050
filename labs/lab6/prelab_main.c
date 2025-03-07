#include "prelab6.h"

int main(void){
    int errorCode = 0;
    LinkedList* list = intializeLinkedList(&errorCode);
    if(errorCode){
        printf("***Linked list intialization failed***\n");
    }
    for(int i=5; i>0; i--){
        insertAtHead(i, list, &errorCode);
        if(errorCode){
            printf("***insert at head failed***\n");
            printf("---error at index %d---\n",i);
        }
    }
    for(int i=6; i<11; i++){
        insertAtTail(i, list, &errorCode);
        if(errorCode){
            printf("***insert at tail failed***\n");
            printf("---error at index %d---\n",i);
        }
    }

    int length = getLinkedListLength(list);
    printf("Length of linked list: %d\n",length);

    int index = getIndex(1, list);
    printf("Data at index 1: %d\n", index);
    index = getIndex(10, list);
    printf("Data at index 10: %d\n", index);

    freeLinkedList(list);
    return 0;
}
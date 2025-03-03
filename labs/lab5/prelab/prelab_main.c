#include "prelab5.h"

int main(void){
    LinkedList* list = NULL;
    int errorCode;
    list = intializeLinkedList(&errorCode);
    if(errorCode){
        printf("***intialization of linked list failed***\n");
    }
    for(int i=1; i<6; i++){
        list = insertAtHead(i, list, &errorCode);
        if(errorCode){
            printf("***insert at head failed***\n");
            printf("---index of failure %d---\n",i);
            break;
        }
    }

    int value = getIndex(1, list);
    printf("Object value at index 1: %d\n", value);
    value = getIndex(3, list);
    printf("Object value at index 3: %d\n", value);
    value = getIndex(6, list);
    printf("Object value at index 6: %d\n", value);

    int length = getLinkedListLength(list);
    printf("Length of list: %d\n", length);

    freeLinkedList(list);
    return 0;
}
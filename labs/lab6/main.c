#include "lab6.h"
#include <stdio.h>
#include <stdlib.h>
/*  Basic tests cases I wrote to test proper exectuion and debug if needed.
    My code was run through more intensive test cases upon submission.  */
int main(void){
    Node* list = NULL;
    makeList(&list);
    int value = 4564;
    void* data = &value;
    insertAtTail(list, data);
    int value2 = 5667;
    void* data2 = &value2;
    insertAtTail(list, data2);
    int size =0;
    size = getSize(list);
    printf("Size of list: %d\n", size);
    void* indexed = getAtIndex(list, 0);
    printf("Element at index 0: %d\n", (*(int*)indexed));
    indexed = getAtIndex(list,1);
    printf("Element at index 1: %d\n", (*(int*)indexed));
    void* removedData = removeFromHead(list);
    printf("Removed data from head: %d\n",(*(int*)indexed));
    size = getSize(list);
    printf("New size of list: %d\n",size);
    freeList(&list);
    return 0;
}
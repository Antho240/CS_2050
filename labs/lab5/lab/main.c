#include "lab5.h"

int main(void){
    Node* list = initList();
    int error;
    for(int i=1; i<6; i++){
        insertAtTail(list, i, &error);
        if(error){
            printf("***insert at tail failed***\n");
            printf("---error at index %d---\n",i);
        }
    }

    if(listContains(list, 4)){
        printf("The data 4 was found in list\n");
    }

    if(listContains(list, 0)){
        printf("The data 0 was found in list\n");
    }

    if(listContains(list, 5)){
        printf("The data 5 was found in list\n");
    }


    int data = -1;
    list = removeFromHead(list, &data);
    printf("Data removed from head: %d\n", data);
    list = removeFromHead(list, &data);
    printf("Data removed from head: %d\n", data);

    freeList(list);
    return 0;
}
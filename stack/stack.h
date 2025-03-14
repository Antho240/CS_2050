#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    void* data;
    Node* next;
};
typedef struct Stack Stack;
struct Stack{
    Node* top;
};

Stack* stackInit();
int push(Stack* stack, void* data);
void* pop(Stack* stack);
void freeStack(Stack* stack);


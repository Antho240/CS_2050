#include "stack.h"

Stack* stackInit(){
    Stack* stack = malloc(sizeof(Stack));
    if(stack){
        stack->top = NULL;
    }
    return stack;
}

int push(Stack* stack, void* data){
    if(stack == NULL){
        return 1;
    }
    Node* node = malloc(sizeof(Node));
    if(node){
        node->next = stack->top;
        stack->top = node;
        node->data = data; 
    }
    else{
        return 1;
    }
    return 0;
}

void* pop(Stack* stack){
    if(stack == NULL || stack->top == NULL){
        return NULL;
    }
    void* data = stack->top->data;
    Node* nextNode = stack->top->next;
    free(stack->top);
    stack->top = nextNode;
    return data;
}

void freeStack(Stack* stack){
    if(stack == NULL){
        return;
    }
    Node* current = stack->top;
    Node* nextNode = current;
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(stack);
}

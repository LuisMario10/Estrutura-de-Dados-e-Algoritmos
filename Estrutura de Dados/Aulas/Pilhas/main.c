#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_STACK 10

typedef struct _stack {
    int *data;
    int capacity;
    int size;
} Stack;

Stack* new_Stack(int capacity) {
    Stack* newStack = (Stack*) calloc(1, sizeof(Stack));
    newStack->size = 0;
    newStack->capacity = capacity;
    newStack->data = (int*) calloc(newStack->capacity, sizeof(int));
    return newStack;
}

bool S_isEmpty(Stack* stackRef) {
    return stackRef->size == 0;
}

int S_isFull(Stack* stackRef) {
    return stackRef->size == stackRef->capacity;
}

void S_push(Stack* stackRef, int number) {
    if(S_isFull(stackRef)) {
        printf("Pilha esta Cheia!!!\n");
    } 
    else {
        stackRef->data[stackRef->size] = number;
        stackRef->size++;
    }
}

void S_pop(Stack* stackRef) {
    if(S_isEmpty(stackRef)) {
        printf("Pilha esta vazia!\n");
    }
    else {
        stackRef->data[stackRef->size] = 0;
        stackRef->size--;
    }
}

void S_peek(Stack* stackRef) {
    if(S_isEmpty(stackRef)) {
        printf("Pilha esta vazia!\n");
    } 
    else {
        printf("Elemento do Topo: %i\n", stackRef->data[stackRef->size - 1]);
    }
}

void S_destroy(Stack** stackRef) {
    Stack* stack = *stackRef;
    free(stack->data);
    free(stack);
    *stackRef = NULL;
}

int main() {
    Stack* myStack = new_Stack(3);
    S_push(myStack, 10);
    S_push(myStack, 20);
    S_push(myStack, 30);
    S_push(myStack, 40);
    S_push(myStack, 50);
    S_pop(myStack);
    S_peek(myStack);
    return 0;
}
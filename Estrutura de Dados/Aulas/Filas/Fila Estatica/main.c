#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _queue {
    int* datas;
    int size;
    int capacity;
    int begin;
    int end;  
} Queue;

Queue* new_Queue(int capacity) {
    Queue* queue = (Queue*) calloc(1, sizeof(Queue));
    queue->datas = (int*) calloc(capacity, sizeof(int));
    queue->begin = 0;
    queue->end = 0;
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

bool isEmpty(Queue* queueRef) {
    return queueRef->size == 0;
}

bool isFull(Queue* queueRef) {
    return queueRef->size == queueRef->capacity;
}

void enqueue(Queue* queueRef, int data) {
    if(isFull(queueRef)) {
        fprintf(stderr, "Error in Queue!");
        fprintf(stderr, "Queue is Full!");
        exit(EXIT_FAILURE);
    }
    queueRef->datas[queueRef->end] = data;
    queueRef->end = (queueRef->end + 1) % queueRef->capacity;
    queueRef->size++;
}

int dequeue(Queue* queueRef) {
    if(isEmpty(queueRef)) {
        fprintf(stderr, "Error in Vazia!");
        fprintf(stderr, "Queue is Empty!");
        exit(EXIT_FAILURE);
    } 
    int data = queueRef->datas[queueRef->begin];
    queueRef->begin = (queueRef->begin + 1) % queueRef->capacity;
    return data;
}

void printQueue(Queue* queueRef) {
    printf("Begin = %i\n", queueRef->begin);
    printf("End = %i\n", queueRef->end);
    printf("Capacity = %i\n", queueRef->capacity);
    printf("Size = %i\n", queueRef->size);
    printf("Queue-datas = ");
    long s, i;
    for(int s = 0; s < queueRef->size; s++, i = (i + 1)%queueRef->capacity) {
        printf("%i, ", queueRef->datas[i]);
    }
    printf("\n");
}

int peek(Queue* queueRef) {
    if(isEmpty(queueRef)) {
        fprintf(stderr, "Error in Vazia!\n");
        fprintf(stderr, "Queue is Empty!\n");
        exit(EXIT_FAILURE);
    }
    return queueRef->datas[queueRef->begin];
}

int main() {
    Queue* myQueue = new_Queue(5);
    enqueue(myQueue, 1);
    enqueue(myQueue, 39);
    enqueue(myQueue, 86);
    enqueue(myQueue, 55);
    dequeue(myQueue);
    dequeue(myQueue);
    printQueue(myQueue);
    //printf("\nBegin = %i\nEnd = %i", myQueue->begin, myQueue->end);
    return 0;
}
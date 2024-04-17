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
        printf("Fila Cheia!!");
    } else {
        queueRef->datas[queueRef->end] = data;
        queueRef->end = (queueRef->end + 1) % queueRef->capacity;
        queueRef->size++;   
    }
}

int dequeue(Queue* queueRef) {
    if(isEmpty(queueRef)) {
        return -1;
    }
    int data = queueRef->datas[queueRef->begin];
    queueRef->datas[queueRef->begin] = 0;
    queueRef->begin = (queueRef->begin + 1) % queueRef->capacity;
    queueRef->size++;
    return data;
}

void printQueue(Queue* queueRef) {
    for(int i = queueRef->begin; i < (queueRef->size); i++) {
        printf("%i - ", queueRef->datas[i]);
    }
}
int main() {
    Queue* myQueue = new_Queue(5);
    enqueue(myQueue, 1);
    enqueue(myQueue, 39);
    enqueue(myQueue, 86);
    enqueue(myQueue, 55);
    dequeue(myQueue);
    printQueue(myQueue);
    return 0;
}
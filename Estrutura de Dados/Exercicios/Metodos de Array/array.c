#include <stdio.h>
#include <stdlib.h>
#include "array.h"

integerArray *newIntegerArray(int size) {
    integerArray *array = (integerArray*) calloc(1, sizeof(integerArray));
    array->array = (int*) calloc(size, sizeof(int));
    array->now = 0;
    array->size = size;
    return array;
}

void add(integerArray *arrayRef, int numberRef) {
    if(arrayRef->now == arrayRef->size) {
        printf("Array is full!");
    } else {
        arrayRef->array[arrayRef->now] = numberRef;
        arrayRef->now++;
    }
}

void remove(integerArray *arrayRef, int numberId);

void removeFinal(integerArray *arrayRef) {
     arrayRef->array[arrayRef->size] = 0;
}

int sumAll(integerArray *arrayRef);

int search(int numberRef);

int sort(integerArray *arrayRef);

void deleteIntergerArray(integerArray **arrayRef) {
    free((*arrayRef)->array);
    (*arrayRef)->array = NULL;
    free(*arrayRef);
    *arrayRef = NULL;
}
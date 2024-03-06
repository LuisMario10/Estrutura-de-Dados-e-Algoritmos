#include <stdio.h>
#include <stdlib.h>
#include "array.h"

integerArray *new_IntegerArray(int size) {
    integerArray *array = (integerArray*) calloc(1, sizeof(integerArray));
    array->array = (int*) calloc(size, sizeof(int));
    array->now = 0;
    array->size = size;
    return array;
}

void print(integerArray *arrayRef) {
    for(int i = 0; i < arrayRef->size; i++) {
        printf("posicao %i - %i\n", i, arrayRef->array[i]);
    }
    printf("\n");
}

void add(integerArray *arrayRef, int numberRef) {
    if(arrayRef->now == arrayRef->size) {
        printf("Array is full!");
    } else {
        arrayRef->array[arrayRef->now] = numberRef;
        arrayRef->now++;
    }
}

void removeFinal(integerArray **arrayRef) { 
    integerArray *arrayAUX = *arrayRef;
    arrayAUX->now--;
    arrayAUX->array[arrayAUX->now] = 0; 
}
void removeNumber(integerArray **arrayRef, int numberId) {
    integerArray *arrayAUX = *arrayRef;
    int arraySize = arrayAUX->now;
    if(numberId == arrayAUX->now) {
        removeFinal(arrayRef);
    } else {
        int aux;
        for(int i = numberId; i < arraySize; i++) {
            arrayAUX->array[i] = arrayAUX->array[i + 1];
        }
        arrayAUX->array[arraySize] = 0;
        arrayAUX->now--;
    }
}

void invertArray(integerArray **arrayRef) {
    integerArray *arrayAUX = *arrayRef;
    int arraySize = arrayAUX->now - 1;
    int aux;
    for(int i = 0; i < (arraySize/2); i++) {
        aux = arrayAUX->array[i];
        arrayAUX->array[i] = arrayAUX->array[arraySize - i];
        arrayAUX->array[arraySize - i] = aux;
    }
}

int sumAll(integerArray *arrayRef) {
    int sum = 0;
    for(int i = 0; i < arrayRef->size; i++) {
        sum = sum + arrayRef->array[i];
    }
    return sum;
}

void sort(integerArray **arrayRef) {
    integerArray *arrayAUX = *arrayRef;
    int AUX;
    for(int i = 0; i < (arrayAUX->size); i++) {
        for(int j = 0; j < (arrayAUX->size - i - 1); j++) {
            if(arrayAUX->array[j] > arrayAUX->array[j+1]) {
                AUX = arrayAUX->array[j];
                arrayAUX->array[j] = arrayAUX->array[j+1];
                arrayAUX->array[j+1] = AUX;
            }
        }
    }
}

void delete_IntergerArray(integerArray **arrayRef) {
    free((*arrayRef)->array);
    (*arrayRef)->array = NULL;
    free(*arrayRef);
    *arrayRef = NULL;
}
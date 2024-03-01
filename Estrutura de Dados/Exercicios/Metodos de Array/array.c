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
    arrayAUX->array[numberId] = 0;
    arrayAUX->now--;
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

void deleteIntergerArray(integerArray **arrayRef) {
    free((*arrayRef)->array);
    (*arrayRef)->array = NULL;
    free(*arrayRef);
    *arrayRef = NULL;
}
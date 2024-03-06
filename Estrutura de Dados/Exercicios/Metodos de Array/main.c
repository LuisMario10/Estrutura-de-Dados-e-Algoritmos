#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
    integerArray *myArray = new_IntegerArray(10);
    add(myArray, 1);
    add(myArray, 4);
    add(myArray, 8);
    add(myArray, 16);
    add(myArray, 32);
    add(myArray, 64);
    add(myArray, 128);
    print(myArray);
    removeNumber(&myArray, 4);
    print(myArray);
    delete_IntergerArray(&myArray);
    return 0;
}
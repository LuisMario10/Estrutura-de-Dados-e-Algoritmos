#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
    integerArray *myArray = newIntegerArray(7);
    add(myArray, 5);
    add(myArray, 7);
    add(myArray, 10);
    add(myArray, 11);
    add(myArray, 20);
    add(myArray, 8);
    add(myArray, 9);
    sort(&myArray);
    print(myArray);
    removeNumber(&myArray, 2);
    print(myArray);
    deleteIntergerArray(&myArray);
    return 0;
}
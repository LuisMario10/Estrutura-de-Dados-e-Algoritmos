#include <stdio.h>
#include <stdlib.h>
#include "stringList.h"

char *createDynamicString(int sizeString) {
    char *newString = (char*) calloc(sizeString, sizeof(char));
    return newString;
}

void destroyDynamicString(char **stringRef) {
    free(*stringRef);
    *stringRef = NULL;
}

StringList *newStringList(int capacity) {
    StringList *stringList = (StringList*) calloc(1, sizeof(StringList));
    stringList->strings = (char**) calloc(capacity, sizeof(char*));
    stringList->capacity = capacity;
    stringList->size = 0;
    return stringList;
}

void sizeStringList(StringList *stringListRef) {
    if(stringListRef->size == 0) {
        printf("Vazio");
    } else {
        printf("%i", stringListRef->size);
    }
}

void capacityStringList(StringList *stringListRef) {
    printf("%i",stringListRef->capacity);
}

char *atStringList(StringList *stringListRef, int index) {
    if(stringListRef->strings[index] == NULL) {
        return "invalido";
    }
    return stringListRef->strings[index];
}

char *getStringList(StringList *stringListRef, int index) {
    stringListRef->strings[index];
}

void appendStringList(StringList *stringListRef, char *element) {
    stringListRef->strings[stringListRef->size] = element;
    stringListRef->size++;
}

void printStringList(StringList *stringListRef) {
    for(int i = 0; i < stringListRef->size; i++) {
        printf("List[%i] ==> %s\n", i, stringListRef->strings[i]);
    }
    printf("\n");
}

void destroyStringList(StringList **stringListRef) {
    StringList *auxStringList = *stringListRef;
    for(int i = 0; i < auxStringList->size; i++) {
        destroyDynamicString(&(auxStringList->strings[i]));
    }
    free(auxStringList->strings);
    auxStringList->strings = NULL;
    free(auxStringList);
    *stringListRef = NULL;
}   
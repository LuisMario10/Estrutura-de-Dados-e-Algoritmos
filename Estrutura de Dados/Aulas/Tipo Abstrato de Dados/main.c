#include <stdio.h>
#include "stringList.h"


int main(void) {
    StringList *listaStrings = newStringList(10);
    char *teste = "teste";
    for(int i = 0; i < 10; i++) {
        appendStringList(listaStrings, teste);
    }
    printStringList(listaStrings);
    destroyStringList(&listaStrings);
    return 0;
}


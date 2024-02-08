#include <stdio.h>
#include "stringList.h"


int main(void) {
    StringList *listaStrings = newStringList(10);
    listaStrings->strings = {"arroz", "skate", "vasco", "peixe"};
    
    return 0;
}


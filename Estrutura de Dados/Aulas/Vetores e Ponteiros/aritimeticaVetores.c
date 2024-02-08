#include <stdio.h>

#define TAM_VTR 5

int v[TAM_VTR];

int main(void) {
    for(int i = 0; i < TAM_VTR; i++) {
        printf("Insira Valores na Lista: \n");
        scanf("%i", &v[i]);
    }

    for(int j = 0; j < TAM_VTR; j++) {
        printf("v = %p, v[%i] = %i, (v + %i) = %p, *(v + %i) = %i \n", v, j, v[j], j, 
        (v + j), j, *(v + j));
    }

    return 0;
}
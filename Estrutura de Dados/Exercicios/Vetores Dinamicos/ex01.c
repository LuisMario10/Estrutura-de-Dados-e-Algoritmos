#include <stdio.h>
#include <stdlib.h>

int v1[5] = {1,2,3,4,5};
int *p, *v2;

void mostraVetor(int *vetor);

int main()
{
    printf("Vetor 1 Antes: \n");
    mostraVetor(v1);
    p = v1;
    p[2] = p[3] = 100;
    v2 = (int *) calloc(5, sizeof(int));
    for(int j = 0; j < 5; j++) {
        v2[j] = v1[j];
    }
    printf("Vetor 1 Depois: \n");
    printf("Endereco do v1: %p\n", v1);
    mostraVetor(v1);

    printf("Vetor Dinamico: \nEndereco do ponteiro v2: %p\n", v2);
    mostraVetor(v2);

    printf("Acessando Vetor Por *p: \n");
    mostraVetor(p);

    free(v2);
    v2 = NULL;
    return 0;
}

void mostraVetor(int *vetor)
{
    for(int i = 0; i < 5; i++)
    {
        printf("vetor[%i] = %i\n", i, vetor[i]);
    }
    printf("\n\n");
}
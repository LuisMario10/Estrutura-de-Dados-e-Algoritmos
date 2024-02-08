#include <stdio.h>
#include <stdlib.h>

#define TAM_VETORES 5

int vetorEstatico[TAM_VETORES] = {10, 22, 36, 47, 52};
int *vetorDinamico;

void mostraVetor(int *v);

int main(void)
{
    vetorDinamico = (int *) malloc(TAM_VETORES * sizeof(int));
    printf("Endereco VetorEstatico:\nvetorEstatico = %p\n&vetorEstatico = %p\nvetorEstatico[0] = %p\n", vetorEstatico, &vetorEstatico, vetorEstatico[0]);
    mostraVetor(vetorEstatico);
    for(int j = 0; j < TAM_VETORES; j++)
    {
        vetorDinamico[j] = vetorEstatico[j];
    }
    printf("Endereco Vetor Dinamico:\nvetorDinamico = %p\n&vetorDinamico = %p\nvetorDinamico[0] = %p\n", vetorDinamico, &vetorDinamico, &vetorDinamico[0]);
    mostraVetor(vetorDinamico);
    free(vetorDinamico);
    vetorDinamico = NULL;
    return 0;
}

void mostraVetor(int *v) {
    for(int i = 0; i < TAM_VETORES; i++)
    {
        printf("v[%i] = %i\n", i, v[i]);
    }
    printf("\n\n");
}
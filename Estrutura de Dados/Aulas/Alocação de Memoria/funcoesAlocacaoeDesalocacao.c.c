#include <stdio.h>
#include <stdlib.h>

void mostraVetor(int *vetor);
void desalocaVetor(int **vetor);

int main(void)
{
    printf("- Vetor Normal: \n");
    int v[5] = {1, 4, 8, 12, 16};
    mostraVetor(v);

    printf("- Vetor Dinamico com Malloc: \n");
    int *vMalloc = (int *) malloc(5 * sizeof(int));
    mostraVetor(vMalloc);

    printf("- Vetor Dinamico com Calloc: \n");
    int *vCalloc = (int *) calloc(5, sizeof(int));
    mostraVetor(vCalloc);

    desalocaVetor(&vMalloc);
    desalocaVetor(&vCalloc);
}

void mostraVetor(int *vetor)
{
    for(int i = 0; i < 5; i++)
    {
        printf("&vetor[%i] = %p, vetor[%i] = %i\n", i, &vetor, i, vetor[i]);
    }
    printf("\n\n\n");
}

void desalocaVetor(int **vetor)
{
    free(*vetor);
    *vetor = NULL;
}
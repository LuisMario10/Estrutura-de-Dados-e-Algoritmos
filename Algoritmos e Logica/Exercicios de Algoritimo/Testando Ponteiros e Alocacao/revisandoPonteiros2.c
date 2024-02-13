#include <stdio.h>

#define TAMANHO_LISTA 5

int numeros[TAMANHO_LISTA];
int *v[TAMANHO_LISTA];
int **p[TAMANHO_LISTA];

int main(void)
{
    for(int i = 0; i < TAMANHO_LISTA; i++)
    {
        printf("Insira um valor em v[%i]: ", i);
        scanf("%i", &numeros[i]);
        v[i] = &numeros[i];
        printf("\n\n");
    }

    for(int j = 0; j < TAMANHO_LISTA; j++)
    {
        p[j] = &v[j];
        printf("v[%i] = %i, *p[%i] = %i\n", j, *v[j], j, *p[j]);
        printf("&v[%i] = %p, p[%i] = %p\n", j, &v[j], j, p[j]);
        printf("**p[%i] = %i", j, **p[j]);
    }
    return 0;
}
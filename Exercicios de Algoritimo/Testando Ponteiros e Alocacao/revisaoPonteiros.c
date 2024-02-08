#include <stdio.h>
#include <stdlib.h>

int vetor[10] = {1, 34, 54, 92, 109, 114, 180, 239, 390, 490};

int *p1 = NULL;
int **p2;

void mostraEndereco(int *v);

int main(void)
{
    p1 = vetor;
    p2 = (int**) calloc(10, sizeof(int*));
    printf("Endereco de Memoria de vetor[0] == %p\n", &vetor);
    printf("Endereco de Memoria de p1 == %p\n", &p1);
    printf("Endereco de Memoria de p1 == %p\n\n", &p2);
    for(int i = 0; i < 10; i++)
    {
        p2[i] = &vetor[i];
    }
    printf("Mostrando endereco do vetor:\n");
    mostraEndereco(vetor);
    printf("Mostrando endereco do vetor copiado:\n");
    mostraEndereco(*p2);
    printf("%p", &*p2[1]);
    return 0;
}

void mostraEndereco(int *v) 
{
    for(int i = 0; i < 10; i++)
    {
        printf("endereco de p[%i] = %p\n", i, &v[i]);
    }
    printf("\n\n");
}
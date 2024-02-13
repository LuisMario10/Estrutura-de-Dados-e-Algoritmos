#include <stdio.h>

#define TAM_LISTA 10

int lista[TAM_LISTA] = {5,2,7,4,10,8,6,1,3,9};

void selectionSort(int *lista);
void arrayView(int *lista, int tamanhoLista);

int main(void) 
{
    printf("Comecou\n");
    selectionSort(lista); 
    printf("Terminou");
    return 0;
}

void selectionSort(int *array)
{
    int aux;
    for(int i = 0; i < TAM_LISTA; i++)
    {
        for(int j = i+1; j < TAM_LISTA; j++)
        {
            if(array[i] > array[j])
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                printf("%i - Lista Atualizada: \n", j);
                arrayView(array, TAM_LISTA);
            }
        }
    }
    printf("Resultado Final: \n");;
    arrayView(array, TAM_LISTA);
}

void arrayView(int *lista, int tamanhoLista)
{
    int count = 0;
    while(count < tamanhoLista)
    {
        printf("%i ", lista[count]);
        count++;
    }
    printf("\n\n");
}
#include <stdio.h>

#define TAM_LISTA  7
int lista[TAM_LISTA] = {5,3,7,2,8,10,1};

void bubbleSort(int *array);
void arrayView(int *array, int tamanhoArray);

int main(void)
{
    printf("Lista Inicial: ");
    arrayView(lista, TAM_LISTA);
    printf("Lista Final: ");
    bubbleSort(lista);
    return 0;
}

void bubbleSort(int *array)
{
    int aux;
    for(int i = 0; i < TAM_LISTA; i++)
    {
        for(int j = 0; j < (TAM_LISTA - i - 1); j++)
        {
            if(array[j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    arrayView(lista, TAM_LISTA);
}

void arrayView(int *array, int tamanhoArray)
{
    int count = 0;
    while(count < tamanhoArray)
    {
        printf("%i ", array[count]);
        count++;
    }
    printf("\n");
}
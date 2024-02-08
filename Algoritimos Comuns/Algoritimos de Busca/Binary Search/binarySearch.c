#include <stdio.h>

int lista[10] = {1,2,3,4,5,6,7,8,9,10};
int numeroEscolido, resultado;

int buscaBinaria(int numero, int *vetor, int final);

const int TAMANHO_LISTA = 9;

int main(void)
{
    printf("Insira um Numero: ");
    scanf("%i", &numeroEscolido);
    resultado = buscaBinaria(numeroEscolido, lista, TAMANHO_LISTA);
    printf("Indice: %i", resultado);
    return 0;
}

int buscaBinaria(int numero, int *vetor, int final)
{
    int inicio = 0;
    int meio;

    while(inicio <= final)
    {
        meio = (inicio + final)/2;
        if(numero == vetor[meio])
        {
            return meio;
        }
        else 
        {
            if(numero < vetor[meio])
            {
                final = meio - 1;
            }
            else 
            {
                inicio = meio + 1;
            }
        }
        
    } 
    return -1;
}
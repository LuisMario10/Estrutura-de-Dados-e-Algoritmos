#include <stdio.h>

int numeroEscolido, count;
int fatorial(int numero);

int main(void)
{
    printf("Insira um Numero?: ");
    scanf("%i", &numeroEscolido);
    printf("Resultado do Fatorial: %i", fatorial(numeroEscolido));
    return 0;
}

int fatorial(int numero) 
{
    int resultado = numero;
    int count = numero - 1;
    while(count > 0)
    {
        resultado = resultado * count;
        count--;
    }
}
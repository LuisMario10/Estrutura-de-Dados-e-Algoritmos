#include <stdio.h>
#include <math.h>
int x;
int y;

int main(void)
{
    printf("Digite um numero: ");
    scanf("%i", &x);
    printf("Digite outro: ");
    scanf("%i", &y);

    int soma = x + y;
    int sub = x - y;
    int multip = x * y;
    float div = x / y;

    printf("Resultado Soma: %i\n", soma);
    printf("Resultado Subtração: %i\n", sub);
    printf("Resultado Multiplicação: %i\n", multip);
    printf("Resultado Divisão: %i\n", div);
    printf("Raiz quadrada do primeiro: %i\n", sqrt(x));
    return 0;
}
#include <stdio.h>

int x, y;
int soma(n1, n2);

int main(void)
{
    printf("Digite um numero: ");
    scanf("%i", &x);
    printf("Digite outro: ");
    scanf("%i", &y);
    printf("Resultado da soma dos numeros escolhidos: %i", soma(x, y));
    return 0;
}

int soma(n1, n2)
{
    return n1 + n2;
}
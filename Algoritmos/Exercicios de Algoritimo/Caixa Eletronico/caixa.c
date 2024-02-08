#include <stdio.h>

int dinheiro;
int notas100, notas50, notas20, notas10, notas5, notas2;

void caixaEletronico(int valor);

int main(void)
{
    printf("Quer sacar quanto?: ");
    scanf("%i", &dinheiro);
    caixaEletronico(dinheiro);
    return 0;
}

void caixaEletronico(int valor)
{
    int total = valor;

    while(total >= 100)
    {
        total = total - 100;
        notas100++;
    }
    while(total >= 50)
    {
        total = total - 50;
        notas50++;
    }
    while(total >= 20)
    {
        total = total - 20;
        notas20++;
    }
    while(total >= 10)
    {
        total = total - 10;
        notas10++;
    }
    while(total >= 5)
    {
        total = total - 5;
        notas5++;
    }
    while(total >= 2)
    {
        total = total - 2;
        notas2++;
    }

    printf("Receba: [%i] Notas de 100 | [%i] Notas de 50 | [%i] Notas de 20 | [%i] Notas de 10 | [%i] Notas de 5 | [%i] Notas de 2", notas100, notas50, notas20, notas10, notas5, notas2);
}
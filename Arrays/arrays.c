#include <stdio.h>

char String[30];
int escolha = 0;

int main(void)
{
    printf("Escreva seu nome: ");
    scanf("%29[^\n]s", String);
    printf("Bem Vindo, %s ", String);
    return 0;
}
#include <stdio.h>

int escolha = 0;

int main(void)
{
    do 
    {
        printf("Continuar Programa? [0] sim - [1] nao: ");
        scanf("%i", &escolha);
    } while(escolha == 0);
    return 0;
}
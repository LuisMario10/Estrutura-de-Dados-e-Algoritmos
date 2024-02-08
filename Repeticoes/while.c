#include <stdio.h>

int inicio;
int main(void)
{
    printf("Contagem Regressiva:\n Determine o inicio");
    scanf("%i", &inicio);
    while(inicio != 0)
    {
        printf(inicio);
        inicio--;
    }
    return 0;
}
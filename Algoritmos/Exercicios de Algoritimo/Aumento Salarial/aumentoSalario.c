#include <stdio.h>
#include <math.h>

char nome[30];
float calculaSalarioNovo(float salario);
float salario;

const float PORCENTAGEM = 1.15;

int main(void)
{
    printf("Qual seu nome?\n");
    scanf("%29[^\n]s", nome);
    fflush(stdin);
    printf("Por Favor informe seu salario: \n");
    scanf("%f", &salario);   
    fflush(stdin);
    printf("%s, seu novo salario com a porcentagem aplicada sera de %.2f", nome,  calculaSalarioNovo(salario));
    return 0;
}

float calculaSalarioNovo(float salario)
{
    return ceil(salario * PORCENTAGEM);
}
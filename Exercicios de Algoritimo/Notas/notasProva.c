// Media par passar >= 6

#include <stdio.h>

float notas[3];
float media;

const int QUANTIDADE_NOTAS = 3;

int main(void)
{
    for(int i = 0; i < QUANTIDADE_NOTAS; i++)
    {
        printf("Adicione a nota[%i] do Aluno(a): ", (i + 1));
        scanf("%f", &notas[i]);
    }
    media = (notas[0] + notas[1] + notas[2])/QUANTIDADE_NOTAS;
    if(media >= 6)
    {
        printf("A Media Foi de: [ %.2f ] | Aluno(a) Aprovado!!!", media);
    }
    else
    {
        printf("A Media Foi de: [ %.2f ] | Aluno(a) Reprovado!!!", media);
    }
    printf("Finalizou o Programa!!!, valores");
    return 0;
}
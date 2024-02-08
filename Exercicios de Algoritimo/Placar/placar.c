#include <stdio.h>
#include <string.h>

char casa[10];
char visitante[10];
int pontuacaoCasa = 0;
int pontuacaoVisitante = 0;

const int TAMANHO_NOME = 10;

int main(void)
{
    printf("Insira o nome do time da casa: \n");
    fgets(casa, TAMANHO_NOME, stdin);
    fflush(stdin);
    printf("Insira o nome do time visitante: \n");
    fgets(visitante, TAMANHO_NOME, stdin);
    fflush(stdin);
    

    printf("Pontuacao de %s", casa);
    scanf("%i", &pontuacaoCasa);
    printf("Pontuacao de %s", visitante);
    scanf("%i", &pontuacaoVisitante);
    printf("Placar da partida: %s [%i] x [%i] %s\n", casa, pontuacaoCasa, pontuacaoVisitante, visitante);

    if(pontuacaoCasa > pontuacaoVisitante)
    {
        printf("Time da %s e o vencedor!!!, Parabens", casa);
    } else if(pontuacaoCasa < pontuacaoVisitante)
    {
        printf("Time %s e o vencedor!!!, Parabens", visitante);
    } else if(pontuacaoCasa == pontuacaoVisitante)
    {
        printf("A partida terminou em empate");
    }
    return 0;
}
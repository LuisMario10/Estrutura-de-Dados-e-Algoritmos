#include <stdio.h> 

int tempo;
int escolha = 1;

void converteTempo(int tempoTotal);

int main(void)
{
    while(escolha != 0)
    {
        printf("Insira o tempo total, em segundos: ");
        scanf("%i", &tempo);
        converteTempo(tempo);
        printf("Continuar: [0]nao | [1]sim: ");
        scanf("%i", &escolha);
    }
    return 0;
}

void converteTempo(int tempoTotal)
{
    int horas, minutos, segundos;
    segundos = tempoTotal;
    horas = tempoTotal / 3600;
    segundos = segundos - (3600 * horas);
    minutos = segundos / 60;
    segundos = segundos - (minutos * 60);
    printf("%i Horas : %i Minutos : %i Segundos\n", horas , minutos, segundos);
}
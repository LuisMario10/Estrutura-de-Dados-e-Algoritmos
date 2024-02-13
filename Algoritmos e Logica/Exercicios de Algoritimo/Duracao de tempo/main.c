#include <stdio.h>
int inicio, fim;

int duracaoJogo(int comeco, int final) {
    if(comeco > 24 || final > 24) {
        return - 1;
    }
    else if(comeco > final) {
        comeco = comeco - 12;
        return comeco - final;
    }
    return comeco - final;
}

int main() {
    printf("Inicio do Jogo[em Horas]: ");
    scanf("%i", &inicio);
    printf("Final do Jogo[em Horas]: ");
    scanf("%i", &fim);
    int duracao = duracaoJogo(inicio, fim);
    if(duracao == -1) {
        printf("Erro, inicio ou fim nao correspondem a horarios validos");
    }
    printf("O jogo durou: %i", duracaoJogo(inicio, fim));
    return 0;
}
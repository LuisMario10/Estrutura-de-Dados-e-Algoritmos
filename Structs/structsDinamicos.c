#include <stdio.h>
#include <stdlib.h>

typedef struct _pessoa {
    char nome[100];
    int idade;
    float peso;
} Pessoa;

int main() {
    Pessoa *voce = (Pessoa *) calloc(1, sizeof(Pessoa));
    printf("Qual seu nome?: \n");
    scanf("%s", voce->nome);
    printf("Qual sua idade?: \n");
    scanf("%i", &voce->idade);
    printf("Qual seu peso? [em Kg]: \n");
    scanf("%f", &voce->peso);

    printf("Ola %s, voce tem %i anos e pesa %.2f Kg", voce->nome, voce->idade, voce->peso);
    free(voce);
    voce = NULL;
    
    return 0;
}
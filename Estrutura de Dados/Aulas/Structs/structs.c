#include <stdio.h>

#define TAM 50

typedef struct Pessoa {
    char nome[TAM];
    int idade;
    float peso;
} Pessoa;

int main()
{
    Pessoa eu = { "Luis", 10, 80.7 };
    printf("Nome: %s\n Idade: %i\n Peso: %f", eu.nome, eu.idade, eu.peso);
    return 0;
}
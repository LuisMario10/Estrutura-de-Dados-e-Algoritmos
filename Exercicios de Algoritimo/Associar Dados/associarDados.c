/* 
Pessoa1: Nome -> Luis / Idade -> 19
Pessoa2: Nome -> Mario / Idade -> 35
Pessoa3: Nome -> Gabriel / Idade -> 20  
*/

#include <stdio.h>  

typedef struct Pessoa {
    char *nome;
    int idade;
} Pessoa;

Pessoa ListaPessoas[3] = {
    {"Luis", 19},
    {"Mario", 35},
    {"Gabriel", 20}
};

int main(void)
{
    int i = 0;
    while(i <= 3)
    {
        printf("Nome: %s\nIdade: %i\n\n", ListaPessoas[i].nome, ListaPessoas[i].idade);
        i++;
    }
    return 0;
    // comentario
}
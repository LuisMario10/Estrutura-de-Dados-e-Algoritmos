#include <stdio.h>

#define TAM_LISTA 7

int lista[TAM_LISTA+1] = {1,4,6,7,8,34,54,100};
int escolha, continuar;
int pesquisaLinear(int numero);

int main(void)
{
    while(continuar == 0)
    {
        printf("Pesquise um Numero: \n");
        scanf("%i", &escolha);
        printf("Resultado: %i\n",pesquisaLinear(escolha));

        printf("Continuar?: ");
        scanf("%i", &continuar);
    }
    
    return 0;
}

int pesquisaLinear(int numero)
{
    for(int id = 0; id <= TAM_LISTA; id++)
    {
        if(lista[id] == numero)
        {
            return id;
        }
    }
    return -1;
}
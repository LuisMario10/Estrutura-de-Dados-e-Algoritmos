#include <stdio.h>

int continuar = 1;
int codigoLanche;
float valorFinal;

int main(void) 
{
    while(continuar != 0)
    {
        printf("Lanchonete\n\nCodigo | Lanche | Preco\n");
        printf("1 | Cachorro quente | R$ 4,00\n");
        printf("2 | X-Salada | R$ 4,50\n");
        printf("3 | X-Bacon | R$ 5,00\n");
        printf("4 | Torta de Maca | R$ 2,00\n");
        printf("5 | Refrigerante | R$ 1,50\n\n");

        printf("Escolha seu Lanche: \n");
        scanf("%i", &codigoLanche);

        switch(codigoLanche)
        {
            case 1:
                printf("+1 Cachorro Quente");
                valorFinal = valorFinal + 4;
                break;
            case 2:
                printf("+1 X-Salada");
                valorFinal = valorFinal + 4.5;
                break;
            case 3:
                printf("+1 X-Bacon");
                valorFinal = valorFinal + 5;
                break;
            case 4:
                printf("+1 Torta de Maca");
                valorFinal = valorFinal + 2;
                break;
            case 5:
                printf("+1 Refrigerante");
                valorFinal = valorFinal + 1.5;
                break;
            default:
                printf("Erro, Codigo Nao pertence a um produto valido!!!\n");
                break;
        }
        printf("\n\nContinuar? [0] Nao ou [1] Sim: \n");
        scanf("%i", &continuar);
    }

    printf("Fechando Caixa...\nSua Conta: %.2f", valorFinal);
}
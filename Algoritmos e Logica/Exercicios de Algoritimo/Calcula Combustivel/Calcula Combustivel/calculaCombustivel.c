#include <stdio.h>

float combustivelAtual, distanciaPercorrida, vazaoCarro, abastecimentoLocal, resultado;
float quantidadeCombustivelRestante(float combustivel, float distancia, float vazao);

int main(void) 
{
    printf("Insira a quantidade de combustivel atual: \n");
    scanf("%f", &combustivelAtual);
    printf("Insira a Distancia a ser percorrida: \n");
    scanf("%f", &distanciaPercorrida);
    printf("Insira a vazao(perca de combustivel a cada KM) do carro: \n");
    scanf("%f", &vazaoCarro);
    float resultado = quantidadeCombustivelRestante(combustivelAtual, distanciaPercorrida, vazaoCarro);
    if(resultado >= 0)
    {
        printf("O trajeto sera feito sem pausas com esse volume de combustivel");
    }
    else if(resultado < 0)
    {
        float abastecimento = combustivelAtual * vazaoCarro;
        printf("O trajeto sera interrompido, pois a %.2f Km\n", abastecimento);
        printf("Voce deve abastecer %.2f litros\n", resultado * (-1));
    }
    return 0;
}

float quantidadeCombustivelRestante(float combustivel, float distancia, float vazao)
{
    return (combustivel - (distancia / vazao));
}
#include <stdio.h>

int escolha;
int continuar = 1;
float lados[3];
float base, altura, raio;

float calculaAreaRetangulo(float lado1, float lado2);
float calculaAreaCircunferencia(float raio);
float calculaAreaTriangulo(float base, float altura);
float calculaVolumePrisma(float lado1, float lado2, float lado3);
float calculaVolumeEsfera(float raio);

int main(void)
{
    while(continuar != 0)
    {
        printf("ESCOLHA A OQUE CALCULAR:\n");
        puts("Area do Retangulo/Cubo[0]\n");
        puts("Area Circunferencia[1]\n");
        puts("Area Triangulo[2]\n");
        puts("Volume Prisma[3]\n");
        puts("Volume Esfera[4]\n");
        puts("Qual sua escolha: ");
        scanf("%i", &escolha);
        if(escolha == 0)
        {
            for(int i = 0; i < 2; i++)
            {
                printf("Informe o comprimento do lado[%i] em Metros\n", i + 1);
                scanf("%f", &lados[i]);
            }
            printf("Resultado: %.2f M^2\n\n", calculaAreaRetangulo(lados[0], lados[1]));
        } 
        else if(escolha == 1)
        {
            printf("Informe o comprimento do raio da circunferencia: \n");
            scanf("%f", &raio);
            printf("Resultado: %.2f M^2\n\n", calculaAreaCircunferencia(raio));

        } 
        else if(escolha == 2)
        {
            printf("Informe o comprimento da base: \n");
            scanf("%f", &base);
            printf("Informe a altura do triangulo: \n");
            scanf("%f", &altura);
            printf("Resultado: %.2f M^2\n\n", calculaAreaTriangulo(base, altura));
        }
        else if(escolha == 3)
        {
            for(int i = 0; i < 3; i++)
            {
                printf("Informe a aresta[%i]: ", i + 1);
                scanf("%f", lados[i]);
            }
            printf("Resultado: %.2f M^3\n\n");
        }
        else if(escolha == 4)
        {
            printf("Informe o raio da esfera: ");
            scanf("%f", &raio);
            printf("Resultado: %.2f M^3\n\n", calculaVolumeEsfera(raio));
        }
        printf("Continuar? nao[0] sim[1]: \n");
        scanf("%i", &continuar);
        printf("\n\n\n\n");
    }
    printf("Finalizando Programa...\n");
    return 0;
}

float calculaAreaRetangulo(float lado1, float lado2)
{
    return lado1 * lado2;
}

float calculaAreaCircunferencia(float raio)
{
    return 3.14 * (raio * raio);
}

float calculaAreaTriangulo(float base, float altura)
{
    return base * altura / 2;
}

float calculaVolumePrisma(float lado1, float lado2, float lado3)
{
    return lado1 * lado2 * lado3;
}

float calculaVolumeEsfera(float raio)
{
    return 4 * 3.14 * (raio * raio) / 3;
}
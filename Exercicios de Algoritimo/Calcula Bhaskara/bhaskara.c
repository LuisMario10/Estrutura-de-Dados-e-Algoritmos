// Bhaskara => -b (+/-) sqrt(delta) / 2*a
// Delta => b^2 - 4 * a * c

#include <stdio.h>
#include <math.h>

float a, b, c, d;

float delta(float a, float b, float c);
void calculaBhaskara(float a, float b, float delta);

int main(void)
{
    printf("Insira o valor de A: ");
    scanf("%f", &a);
    printf("Insira o valor de B: ");
    scanf("%f", &b);
    printf("Insira o valor de C: ");
    scanf("%f", &c);

    d = delta(a, b, c);
    printf("valor de Delta: %f", d);
    calculaBhaskara(a, b, d);
    return 0;
}

float delta(float a, float b, float c)
{
    return ((b * b) - 4 * a * c);
}

void calculaBhaskara(float a, float b, float delta)
{
    float X1 = (-b + sqrt(delta))/ (2*a);
    float X2 = (-b - sqrt(delta))/ (2*a);

    printf("Resultado Calculado: \n\n");
    printf("X1 = %.2f\n", X1);
    printf("X2 = %.2f\n", X2);
}
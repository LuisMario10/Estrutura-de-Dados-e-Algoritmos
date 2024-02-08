#include <stdio.h>

int a,b,*p1,*p2;

int main(void)
{
    a = 10;
    b = 5;
    p1 = &a;
    p2 = &b;
    printf("Valor do Calculo com ponteiros: %i", *p1 + *p2);
    return 0;
}
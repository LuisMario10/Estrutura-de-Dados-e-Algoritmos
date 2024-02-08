#include <stdio.h>

int age;

int main(void)
{
    printf("Ola, qual sua idade?");
    scanf("%i", &age);
    if(age >= 18)
    {
        printf("Voce é maior de idade!");
    } 
    else if(age == 18) 
    {
        printf("voce tem 18 anos, logo e de maior");
    } 
    else {
        printf("Voce é menor de idade!");
    }
    return 0;
}
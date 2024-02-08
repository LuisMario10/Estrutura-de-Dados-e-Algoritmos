#include <stdio.h>
#include <stdlib.h>

int n = 5;
int *v;

int main(void) 
{
    v = (int *)malloc(5 * sizeof(int));

    printf("Endereco do Vetor: %p", &v);
    for(int i = 0; i < n; i++) 
    {
        v[i] = i * 10;
    }
    for(int i = 0; i < n; i++) 
    {
        printf("&v[%i] = %p, v[%i] = %i\n", i, &v[i], i, v[i]);
    }

    free(v);
    v = NULL;
    return 0;
}
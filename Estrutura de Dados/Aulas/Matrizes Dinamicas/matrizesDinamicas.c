#include <stdio.h>
#include <stdlib.h>

const int linhas = 5;
const int colunas = 4;

int main(void)
{
    int **m = (int **) calloc(linhas, sizeof(int*));
    for(int i = 0; i < linhas; i++)
    {
        m[i] = (int *) calloc(colunas, sizeof(int));
    }
    
    int count = 0;

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            m[i][j] = count++;
            printf("m[%i][%i] = %i\n", i,j,m[i][j]);
        }
    }
    return 0;
}
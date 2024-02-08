#include <stdio.h>
#include <stdio.h>

int linhas = 2, colunas = 4, count = 0;

int **matrizDinamica(size_t nlinhas, size_t ncolunas)
{
    int **m = (int **) calloc(nlinhas, sizeof(int*));
    for(size_t a; a < nlinhas; a++)
    {
        m[a] = (int*) calloc(ncolunas, sizeof(int));
    }
    return m;
}

int main(void)
{
    int **novaMatriz = matrizDinamica(linhas, colunas);
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            novaMatriz[i][j] = count++;
            printf("matriz[%i][%i] = %i\n", i, j, novaMatriz[i][j]);
        }
    }
    return 0;
}



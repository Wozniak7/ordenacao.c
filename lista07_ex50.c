#include <stdio.h>
#include <stdlib.h>

void le_matriz(int **, int, int);
void exibe_matriz(int **, int, int);
int soma_diagonal(int **, int);

int main()
{
    int linha, coluna, i;
    int **m;
    printf("digite o numero de linhas: \n");
    scanf("%d", &linha);
    printf("digite o numero de colunas: ");
    scanf("%d", &coluna);

    m = (int **)malloc(linha * sizeof(int *));

    for (i = 0; i < linha; i++)
        m[i] = (int *)malloc(coluna * sizeof(int));

    le_matriz(m, linha, coluna);
    exibe_matriz(m, linha, coluna);

    printf("\n a soma da diagonal principal eh: %d\n", soma_diagonal(m, linha));

    return 0;
}

void le_matriz(int **m, int linha, int coluna)
{
    int i, j;
    printf("digite o elemento\n");
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void exibe_matriz(int **m, int linha, int coluna)
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
            printf("%4d| ", m[i][j]);
        printf("\n");
    }
}

int soma_diagonal(int **m, int linha)
{
    int i, soma = 0;
    for (i = 0; i < linha; i++)
        soma = soma + m[i][i];

    return soma;
}
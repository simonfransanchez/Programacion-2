/*Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente. */

void convert(int mat[][5], int n)
{
    int i, j;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            if (mat[i][j] != 0)
                if (mat[j][i] == 0)
}
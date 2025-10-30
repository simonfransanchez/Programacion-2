/*Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente. */

void convert(int mat[][5], int n)
{
    int i, j;
    for (i = 0; i <= n; i++)
        for (j = i + 1; j <= n; j++){
            mat[i][j] += mat[j][i];
            mat[j][i] = mat[i][j];
        }

}
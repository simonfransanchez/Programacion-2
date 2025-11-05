/*Desarrollar funciones recursivas para:
a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.
b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
de adyacencia.
c) determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia
(triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).
d) generar un vector de registros con grado y vértice para aquellos vértices, de un grafo
almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3. */

void genera(int v[], int n, int i, int j)
{
    if (i >= 0)
        if (j >= 0)
        {
            v[i] += mat[i][j];
            genera(v, n, i, j - 1);
        }
        else
            genera(v, n, i - 1, n - 1);
}
/* Para un grafo almacenado en una matriz de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad
b) mostrar todos sus vértices mediante recorrido en amplitud
c) devolver la cantidad de componentes conexas*/

#define MAX 10

int todosvisitados(int v[], int n)
{
    int i = 0;
    while (v[i] != 0 && i <= n)
        i++;
    return i > n;
}

void DFS(int mat[][MAX], int n, int ini)
{
    int v[MAX] = {0}, i = 0, vert, k;
    TPila P;
    v[ini] = 1;
    poneP(&P, ini);
    printf("%d", ini);
    while (!todosvisitados(v, n))
    {
        i++;
        while (!vacia(P))
        {
            vert = vertady(mat, consultaP(P));
            if (vert != -1)
            {
                v[vert] = i;
                poneP(&P, vert);
                printf("%d", vert);
            }
            else
                sacaP(&P, vert);
        }
    }
}
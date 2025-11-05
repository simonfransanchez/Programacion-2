/* Para un grafo almacenado en una matriz de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad
b) mostrar todos sus vértices mediante recorrido en amplitud
c) devolver la cantidad de componentes conexas*/

#define MAX 10

int todosvisitados(int v[], int n)
{
    int i = 0;
    while (v[i] != 0 && i <= n - 1)
        i++;
    return i > n;
}

int buscaCC(int v, int n)
{
    int i = 0;
    while (v[i] != 0 && i <= n - 1)
        i++;
    return i;
}

int vertady(int mat[][MAX], int n, int vert, int v[])
{
    int i = 0;
    while (!(mat[vert][i] != 0 && v[i] == 0))
        i++;
    return i;
}

void DFS(int mat[][MAX], int n)
{
    int v[MAX] = {0}, i = 0, vert, ini;
    TPila P;
    while (!todosvisitados(v, n))
    {
        i++;
        ini = buscaCC(v, n);
        v[ini] = i;
        poneP(&P, ini);
        printf("%d", ini);
        while (!vacia(P))
        {
            vert = vertady(mat, n, consultaP(P), v);
            if (vert != -1)
            {
                v[vert] = i;
                poneP(&P, vert);
                printf("%d", vert);
            }
            else
                sacaP(&P, &vert);
        }
    }
}

void BFS(int mat[][MAX], int n)
{
    int v[MAX] = {0}, i = 0, vert, ini;
    TCola C;
    while (!todosvisitados(v, n))
    {
        i++;
        ini = buscaCC(v, n);
        v[ini] = i;
        poneC(&C, ini);
        printf("%d", ini);
        while (!vaciaC(C))
        {
            sacaC(&C, &vert);
            k = vertady(mat, n, vert, v);
            while (k != -1)
            {
                v[k] = i;
                printf("%d", k);
                poneC(&C, k);
            }
        }
    }
}
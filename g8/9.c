/*Hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia*/

typedef struct nodo
{
    char vert;
    struct nodo *sig;
} nodo;

typedef nodo *TLista;

typedef struct
{
    int gre;
    char vert;
    TLista sub;
} tv;

int busca(tv v[], char x)
{
    int i = 0;
    while (v[i].vert != x)
        i++;
    return i;
}

void grados(tv v[], int n)
{
    int i;
    TLista aux;
    for (i = 0; i <= n; i++)
    {
        aux = v[i].sub;
        while (aux)
        {
            (v[busca(v, aux->vert)].gre)++;
            aux = aux->sig;
        }
    }
}

char max(tv v[], int n)
{
    int i, m = 0;
    char vert;
    for (i = 0; i <= n; i++)
        if (v[i].gre > m)
        {
            m = v[i].gre;
            vert = v[i].vert;
        }
    return vert;
}
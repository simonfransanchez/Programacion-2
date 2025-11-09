

typedef struct nodo
{
    int dato;
    struct nodo *izq, *der;
} nodo;

int grado(arbol A)
{
    int gr = 0;
    A = A->izq;
    while (A)
    {
        gr++;
        A = A->der;
    }
    return gr;
}

int ej1(arbol bosque)
{
    int cumple = 1;
    while (bosque && cumple)
    {
        cumple = grado(bosque) == grado_arbol(bosque->izq);
        bosque = bosque->der;
    }
}

int grado_arbol(arbol A)
{
    int gri, grd, gr;
    if (A == NULL)
        return 0 else
        {
            gri = grado_arbol(A->izq);
            grd = grado_arbol(A->der);
            gr = grado(A);
            gr = (gri > gr) ? gri : gr;
            gr = (grd > gr) ? grd : gr;
            return gr;
        }
}

int gradoN(arbolN A, pos p)
{
    pos c;
    int gr = 0;
    c = hijomasizq(p);
    while (!nulo(c))
    {
        gr++;
        c = hnoder(c);
    }
    return gr;
}

int verifica(arbolN A, pos p)
{
    pos c;
    int grant = -1, gract;
    c = hijomasizq(p);
    gract = gradoN(A, c);
    while (!nulo(c) && gract > grant)
    {
        grant = gract;
        c = hnoder(c);
        gract = gradoN(A, c);
    }
    return nulo(c);
}

int existe(arbolN A, pos p)
{
    if (!nulo(p))
    {
        if (!nulo(hijomasizq(p, A)))
        {
            return verifica(A, p) || existe(A, hijomasizq(p)) || existe(A, hnoder(p));
        }
        else
            return 0;
    }
    else
        return 0;
}

int cant(int mat[][MAX], int n, int i, int j, int gre, int grs)
{ // llamado: cant(mat,n-1,n-1,n-1,0,0)
    if (i < 0)
        return 0;
    else if (j < 0)
        return (gre == grs) + cant(mat, n, i - 1, n, 0, 0);
    else if (mat[i][i] == 0)
        return cant(mat, n, i, j - 1, gre + mat[j, i], grs + mat[i][j]);
    else
        return cant(mat, n, i - 1, n, 0, 0);
}

// EJERCICIO 1
int recorrido(arbol A, int n, int k1, int k2)
{
    if (A == NULL || n > k2)
        return 0;
    else if (n >= k1)
        if (n <= k2)
            return (A->dato < 0) || recorrido(A->izq, n + 1, k1, k2) || recorrido(A->der, n, k1, k2);
        else
            return recorrido(A->izq, n + 1, k1, k2) || recorrido(A->der, n, k1, k2);
}

int cuenta(arbol bosque, int k1, int k2)
{
    int cont = 0, cumple = 1;
    while (bosque)
    {
        if (bosque->dato < 0 || recorrido(bosque->izq, 2, k1, k2))
            cont++;
        bosque = bosque->der;
    }
    return cont;
}

// EJERCICIO 2
void ej2(arbolN A, pos p, int n, int k, int *max, int *min)
{ // llamado ej2(A,raiz(A),1,k,*max,*min) min=999 max=0 (main)
    pos c;
    int gr = 0;
    if (!nulo(p) && n <= k)
    {
        c = hijomasizq(p);
        while (!nulo(c))
        {
            gr++;
            ej2(A, c, n + 1, k, max, min);
            c = hnoder(c);
        }
        if (n == k)
        {
            *min = (gr < *min) ? gr : (*min);
            *max = (gr < *max) ? gr : (*max);
        }
    }
}

// EJERCICIO 3
void determina_rec(int mat[][MAX], int n, int i, int j, int *g1, int *g2)
{ // llamado deetermina(mat,n-1,n-2,n-1)
    if (i >= 0 && (*g1 + *g2 != 0))
        if (i == j)
            determina_rec(mat, n, i - 1, n, g1, g2);
        else
        {
            if (mat[i][j] > mat[j][i])
                *g1 = 0;
            else if (mat[i][j] < mat[j][i])
                *g2 = 0;
            determina_rec(mat, n, i, j - 1, g1, g2);
        }
}

int determina(int mat[][MAX], int n)
{
    int i, j, g1 = 1, g2 = 2, ;
    for (i = 1; i < n; i++)
    {
        j = i + 1;
        while (j < n && (g1 != g2))
        {
            if (mat[i][j] > mat[j][i])
                g1 = 0;
            else if (mat[i][j] < mat[j][i])
                g2 = 0;
            j++;
        }
    }
    if (g1 == g2)
        return -1;
    else
        return g1 > g2; // LA FUNCION RETORNA SI G2 ES SUBGRAFO DE G1 O VICEVERSA Y -1 SI NINGUNA
}

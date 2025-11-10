int grado(arbol A)
{
    int cont = 0;
    A = A->izq;
    while (A)
    {
        cont++;
        A = A->der;
    }
    return cont;
}

void recorrido(arbol A, int k, *aux)
{
    if (A)
        if (*aux < 2)
        {
            *aux += grado(A) == k;
            recorrido(A->izq, k, aux);
            recorrido(A->der, k, aux);
        }
}

void ej1(arbol bosque, int k, )
{
    int cont = 0, aux = 0;
    while (bosque)
    {
        recorrido(bosque->izq, k, &aux);
        cont += (grado(bosque) + aux == 1);
        bosque = bosque->der;
    }
}

void ej2(arbolN A, pos p, int n, int *nivel, int v[])
{
    if (!nulo(p))
    {
        if (n > *nivel)
            *nivel = n;
        if (v[n] == 0)
            v[n] = esvocal(info(p, A));
        ej2(A, hijomasizq(p, A), n + 1, nivel, v);
        ej2(A, hnoder(p, A), n, nivel, v);
    }
}

void determina(arbolN A, pos p, int v[], int *cumple)
{
    int nivel = 0, i = 0;
    if (!vacio(A))
    {
        ej2(A, raiz(A), 1, &nivel, v);
        while (i < nivel && v[i] != 0)
            i++;
    }
    *cumple = (i == nivel && nivel != 0);
}

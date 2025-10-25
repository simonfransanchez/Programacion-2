/*Implementar una función iterativa que inserte un elemento en un ABB*/

void insertaABB(arbol *A, int x)
{
    arbol act, ant, nuevo;
    ant = NULL;
    act = *A;
    while (act)
    {
        while (x > act->dato)
        {
            ant = act;
            act = act->der;
        }
        while (x < act->dato)
        {
            ant = act;
            act = act->izq;
        }
    }
    nuevo = (arbol)malloc(sizeof(nodo));
    nuevo->der = nuevo->izq = NULL;
    nuevo->dato = x;
    if (ant == NULL)
        *A = nuevo;
    else if (x < ant->dato)
        ant->izq = nuevo;
    else
        ant->der = nuevo;
}
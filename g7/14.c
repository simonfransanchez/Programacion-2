/*Desarrollar una función que compruebe que si un árbol binario es un ABB*/

int verifica(arbol A)
{
    if (A == NULL)
        return 1;
    else if ((A->izq->dato == NULL || A->izq->dato < A->dato) && (A->der->dato == NULL || A->der->dato > A->dato))
        return verifica(A->izq) && verifica(A->der);
    else
        return 0;
}
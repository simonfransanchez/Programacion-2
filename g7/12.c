/*Determinar cuántos elementos de un ABB son mayores que A y menores que B. A y B son
parámetros de entrada. */

int entreAB(arbol A, int a, int b)
{
    if (A == NULL)
        return 0;
    else if (A->dato > a)
        if (A->dato < b)
            return 1 + entreAB(A->izq, a, b) + entreAB(A->der, a, b);
        else
            return entreAB(A->izq, a, b);
    else
        return entreAB(A->der, a, b);
}

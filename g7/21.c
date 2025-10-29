/*21. Dado un árbol binario que proviene de la transformación de un bosque,
a) hallar la cantidad de árboles del bosque que tenían altura al menos K (dato de entrada)
b) generar un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.
c) verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada).*/

int a(arbol bosque, int k)
{ // ASUMIENDO UN K > 1
    int i = 0;
    while (bosque)
    {
        i += cumple(bosque->izq, 2, k);
        bosque = bosque->der;
    }
    return i;
}

int cumple(arbol a, int n, int k)
{
    if (a == NULL)
        return 0;
    else if (n >= k)
        return 1;
    else
        return cumple(a->izq, n + 1, k) || cumple(a->der, n + 1, k);
}

void b(int v[], arbol bosque)
{
    int i = 0;
    while (bosque)
    {
        v[i] = buscamin(bosque->izq);
        bosque = bosque->der;
    }
}

int buscamin(arbol A)
{
    int min, mini, mind;
    if (A == NULL)
        return MIN; // constante exageradamente grande
    else
    {
        min = A->dato;
        mini = buscamin(A->izq);
        mind = buscamin(A->der);
        min = (min < mini) ? min : mini;
        min = (min < mind) ? min : mind;
        return min;
    }
}

int grado(arbol A)
{
    int i = 0;
    A = A->izq;
    while (A)
    {
        i++;
        A = A->der;
    }
    return i;
}

int c(arbol bosque, int k)
{
    int cumple = 1;
    while (cumple && bosque)
        if (grado(bosque) == k)
            bosque = bosque->der;
        else
        {
            cumple = verifica(bosque->izq);
            bosque = bosque->der;
        }
    return (cumple && bosque == NULL);
}
}

int verifica(arbol A, int k)
{
    if (A == NULL)
        return 0;
    else if (grado(A) == k)
        return 1;
    else
        return verifica(A->izq) || verifica(A->der);
}
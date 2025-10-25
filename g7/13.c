/*. Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente. */

void genera(arbol A, char v[], int *n)
{
    if (A)
    {
        genera(A->der, v, n);
        (*n)++;
        v[*n] = A->dato;
        genera(A->izq, v, n);
    }
}
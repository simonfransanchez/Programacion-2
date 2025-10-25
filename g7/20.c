/*Dado un árbol binario proveniente de la conversión de un árbol general:
a) hallar la cantidad de nodos que habia en niveles impares.
b) obtener el promedio de las claves cuyo grado era K (dato de entrada).
c) obtener la altura del árbol original
d) determinar el grado del árbol original. */

int nodoimp(arbol A, int n)
{
    if (A == NULL)
        return 0;
    else if (n % 2 != 0)
        return 1 + nodoimp(A->izq, n + 1) + nodoimp(A->der, n + 1);
    else
        return
}
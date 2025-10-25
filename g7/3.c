#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
    int dato;
    struct nodo *izq, * der;
} nodo;

typedef nodo * arbol;

long int suma(arbol A);
int hojas(arbol A);
int estax(arbol A, int x);

void main(){}

long int suma(arbol A){
    if (A == NULL)
        return 0;
    else
        if (A->dato % 3 == 0)
            return A->dato + suma(A->izq) + suma(A->der);
        else
            return suma(A->izq) + suma(A->der);
}

int hojas(arbol A){
    if (A == NULL)
        return 1;
    else
        return hojas(A->izq) + hojas(A->der);
}

int esta(arbol A, int x){
    if (A == NULL)
        return 0;
    else
        return (A->dato == x || esta(A->izq) || esta(A->der));
}
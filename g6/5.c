#include <stdio.h>

typedef struct nodo{
    TCola C;
    struct nodo *sig;}nodo;

typedef nodo *TLista;

void generaP(TLista L, TPila *P);

void main(){}

void generaP(TLista L, TPila *P){
    int max,aux;
    while (L){    
        sacaC(&(L->C),&max);
        while (!vacia(C)){
            saca(&(L->C),&aux);
            if (aux>max)
                max = aux;
        }
        poneP(P,max);
        L = L->sig;
    }
}
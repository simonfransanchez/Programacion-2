#include <stdio.h>
#include <sstdlib.h>

typedef struct nodo{
    char dato;
    struct nodo *sig;} nodo;

typedef nodo *TLista;

void muestra(TLista L);
int cantvoc(TLista L);
int estaord(TLista L);
void elimina(TLista *L, int P);

void main(){}

void muestra(TLista L){
    TLista aux;
    aux = L;
    while (aux != NULL){
        printf("%c", aux->dato);
        aux = aux->sig;
    }
}

int cantvoc(TLista L){
    TLista aux;
    int cont = 0;
    while (aux){
        if (esvocal(aux->dato))
            cont++;
        aux = aux->sig;
    }
}

int estaord(TLista L){
    TLista act
}
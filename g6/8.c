#include <stdio.h>
#include <stdlib.h>

typedef struct nodoD{
    char dato;
    struct nodoD *ant, *sig;} nodo;

typedef nodoD * PnodoD;

typedef struct {
    PnodoD pri,ult;} TListaD;

typedef struct nodoC{
    char dato;
    struct nodoC *sig;} nodoC;

typedef nodoC * TListaC;

void muestraLD(TListaD LD);
int cantvLD(TListaD LD);
int estaordLD(TListaD LD);
void elimLD(TListaD LD, int p);

void muestraLC(TListaC LC);
int cantvLC(TListaC LC);
int estaordLC(TListaC LC);
void elimLC(TListaC LC, int p);

void main(){}

void muestraLD(TListaD LD){
    while (LD.pri){
        printf("%c",LD.pri->dato);
        LD.pri = LD.pri->sig;
    }
}

int cantvLD(TListaD LD){
    int cont = 0;
    while (LD.pri){
        if (esvocal(LD.pri->dato))
            cont++;
        LD.pri = LD.pri->sig;
    }
    return cont;
}

int estaordLD(TListaD LD){
    PnodoD ant;
    if (LD.pri){
        ant = LD.pri;
        LD.pri = LD.pri->sig;
        while (LD.pri != NULL && ant <= LD.pri){
            ant = LD.pri;
            LD.pri = LD.pri->sig;
        }
        return (LD.pri == NULL);
    }
    else
        return 0;
}


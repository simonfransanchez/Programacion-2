#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
#define ST3 4
#define ST30 31
#define ST20 21

typedef struct {
    unsigned int num,dur;
} TElementoP;

typedef struct{
    TElementoP dato[10];
    int tope;
} TPila;

typedef struct nodito{
    unsigned int hora;
    char cod[ST3];
    struct nodito *sig;
} nodito;

typedef nodito *TSL;

typedef struct nodoC{
    unsigned int num;
    TSL sub;
    struct nodoC *sig;
} nodoC;

typedef nodoC *TLC;

typedef struct nodoS{
    char cod[ST3],nom[ST30],ctt[ST20];
    TPila P;
    struct nodoS *sig;
}nodoS;

typedef nodoS *TLS;

void ia(TLC LCP, unsigned int p){
    FILE *arch = fopen("MEDICIONES.TXT","rt");
    unsigned int hora;
    char cc[ST3];
    TLC act, ant, nuevoC;
    TSL aux,nuevoS;
    if (arch){
        nuevoC->num = p;
        nuevoC->sig = NULL;
        while (fscanf(arch,"%d %s",&hora,cc) == 2){
            nuevoS = (TSL)malloc(sizeof(nodito));
            strcpy(nuevoS->cod,cc);
            nuevoS->hora = hora;
            nuevoS->sig = NULL;
            if (nuevoC->sub == NULL)
                nuevoC->sub = nuevoS;
            else
                aux->sig = nuevoS;
            aux = nuevoS;
        }
        insertaLC(LCP,nuevoC);
    }
}

void insertaLC(TLC LC, TLC nuevo){
    TLC act,ant;
    act = LC;
    do{
        ant = act;
        act = act->sig;
    }
    while(nuevo->num > act->num && act != LC);
    nuevo->sig = act;
    ant->sig = nuevo;
}

void ib(TLC TCP, TLS LSC, char cod[ST3]){
    TLS aux;
    aux = LSC;
    while (aux && strcmp())
}
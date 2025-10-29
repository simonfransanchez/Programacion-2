#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colas.h"
#include "pilas.h"
#define LIM 50

typedef struct nodito{
    float peso;
    int cant[3];
    struct nodito *sig;
} nodito;

typedef nodito * TSLista;

typedef struct nodoD{
    char dest;
    TSLista sub;
    struct nodoD *sig, *ant;
} nodoD;

typedef nodoD * PnodoD;

typedef struct {
    PnodoD pri,ult;
} TListaD;

void a(TListaD LD, TCola *C, TPila *P){
    PnodoD aux;
    unsigned int contp;
    TelementoC x;
    TSLista nuevo, act, ant;
    char dest;
    while (!vaciaC(*C)){
        sacaC(C,&x);        
        contp = 0;
        nuevo = (TSLista)malloc(sizeof(nodito));
        nuevo->peso = 0;
        nuevo->cant = {0};
        nuevo->sig = NULL;
        while (nuevo->peso < LIM && !vaciaC(*C)){
            if (x.peso >= 30 && !(x.cal == 4 || x.cal == 5)){
                nuevo->peso += x.peso / 1000;
                nuevo->cant[x.cal]++;
                contp++;
            }
            else
                poneP(P,x);
            sacaC(C,&x);
        }
        dest = determina(nuevo,contp);
        aux = LD.pri;
        while (aux < toupper(dest))
            aux = aux->sig;
        act = aux->sub;
        ant = NULL;
        while (act){
            ant = act;
            act = act->sig;
        }
        if (ant)
            ant->sig = nuevo;
        else
            aux->sub = nuevo;
    }
}

void b(TListaD LD, char dest[11], int cant){
    FILE * arch = fopen("pedido.txt","wt");
    PnodoD aux;
    TSLista act;
    int i = 0;
    float acum = 0;
    while (aux->dest < dest)
        aux = aux->sig;
    act = aux->sub;
    while (act && i<=cant){
        i++;       
        acum += act->peso;
        fprintf(arch,"%f %d\n",act->peso,act->cant[0]+act->cant[1]+act->cant[2]);
        act = act->sig;
        free(aux->sub);
        aux->sub = act;
    }
    fprintf(arch,"%f",acum);

}

void c(TPila *P, TCola *C){
    TelementoC x;
    if (!vaciaP(*P)){
        sacaP(P,&x);
        c(P,C);
        (x.cal == 4 && x.peso >= 30)? poneC(C,x):poneP(P,x);
    }
}
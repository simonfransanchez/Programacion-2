#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colas.h"
#define ST9 9
#define MAXV 5

typedef struct nodito
{
    unsigned int num;
    char dni[ST9];
    struct nodito *sig;
} nodito;

typedef nodito *TSL;

typedef struct nodoS
{
    unsigned int num;
    char tipo;
    TSL sub;
    struct nodoS *sig;
} nodoS;

typedef nodoS *TLS;

typedef struct nodoD
{
    TElementoC dato;
    struct nodoD *sig, *ant;
} nodoD;

typedef nodoD *PnodoD;

typedef struct
{
    PnodoD pri, ult;
} TLD;

void insertaLD(TLDP *LDP, TElementoC x);
TSLista busca_pac(TLH LH);
void ia(TLH LH, TCola *C, TLDP *LDP);
void ib(TLH LH, int vc[], char vt[]);
void ic();

void main()
{}

void insertaLD(TLDP *LDP, TElementoC x)
{
    PnodoD aux, nuevo;
    nuevo = (PnodoD)malloc(sizeof(nodoD));
    nuevo->ant = nuevo->sig = NULL;
    nuevo->dato = x;
    if (LDP->pri == NULL)
    {
        LDP->pri = LDP->ult = nuevo;
    }
    else if (strcmp(x.dni, LDP->pri->dato.dni) == -1)
    {
        nuevo->sig = LDP->pri;
        LDP->pri->ant = LDP->pri = nuevo;
    }
    else if (strcmp(x.dni, LDP->ult->dato.dni) == 1)
    {
        nuevo->ant = LDP->ult;
        LDP->ult->sig = LDP->ult = nuevo;
    }
    else
    {
        aux = LDP->pri->sig;
        while (strcmp(x.dni, aux->dato.dni) == -1)
            aux = aux->sig;
        nuevo->sig = aux;
        nuevo->ant = aux->ant;
        aux->ant->sig = aux->ant = nuevo;
    }
}

TSLista busca_pac(TLH LH, char dni[ST9])
{
    TSLista pac = NULL, aux;
    while (pac == NULL)
    {
        aux = LH->sub;
        while (aux && pac == NULL)
        {
            if (strcmp(aux->dni, dni) == 0)
                pac = aux;
            aux = aux->sig;
        }
        LH = LH->sig;
    }
    return pac;
}

void ia(TLD *LD, TLS LS, TCola *C){
    TElementoC x;
    TSL auxS;
    while (!vaciaC(*C)){
        sacaC(C,&x);
        ing = x.ing == 'N';
        while (LS){
            if (LS->tipo == x.tipo){
                auxS = LS->sub;
                while(auxS && (ing == 0 || enc == 0)){
                    if (ing == 0 && strcmp(auxS->dni,x.dni) == 0){
                        ing = 1;
                        strcpy(auxS->dni,"");
                    }
                    if (hi && auxS->sig == NULL && auxS->dni[0] == "")
                }
            }
        }
    }
}

int busca_pos(char v[], char x){
    int i = 0;
    while (strcmp(v[i],x))
        i++;
    return i;
}
void ib(TLH *LH,TLDP *LDP, int vc[], char vt[]){ //main: int vc[MAXV] = {0}, char vt[MAXV] = {'P','C','T','E','M'}
    TSLista acts,ants;
    TLH act,ant;
    TElementoC x;
    int i;
    act = *LH;
    while (act->num < 100)
        act = act->sig;
    while (act->num < 200){
        i = busca_pos(vt,act->tipo);
        acts = act->sub;
        while (acts){
            ants = acts;
            acts = acts->sig;
            if (strcmp(ants->dni,"")){
                vc[i]++;
                strcpy(x.dni,ants->dni);
                x.tipo = act->tipo;
                x.hi = x.ing = 'N';
                insertaLD(LDP,x);
            }
            free(ants);
        }
    }
}

void ic(int v[], int n, int *max, int *pos){
    if (n != 0){
        if (v[n] > *max){
            *max = v[n];
            *pos = v[n];
        }
        ic(v,n-1,max,pos);
    }

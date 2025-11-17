#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#define ST9 9
#define P 0
#define C 1
#define T 2
#define E 3
#define M 4

typedef struct nodito
{
    unsigned int num;
    char dni[ST9];
    struct nodito *sig;
} nodito;

typedef nodito *TSLista;

typedef struct nodoS
{
    unsigned int num;
    char tipo;
    TSLista sub;
    struct nodoS *sig;
} nodoS;

typedef nodoS *TLH;

typedef struct nodoD
{
    TElementoC dato;
    struct nodoD *sig, *ant;
} nodoD;

typedef nodoD *PnodoD;

typedef struct
{
    PnodoD pri, ult;
} TLDP;

void insertaLD(TLDP *LDP, TElementoC x);
TSLista busca_pac(TLH LH);
void ia(TLH *LH, TCola *C, TLDP *LDP);
void ib() void ic()

    void main()
{
}

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

void ia(TLH LH, TCola *C, TLDP *LDP)
{
    TElementoC x;
    TSLista act, ing;
    TLH aux;
    int cumple = 0, ctot = 0, cpos = 0;
    while (!vacia(C))
    {
        sacaC(C, &x);
        ing = NULL;
        if (x->ing == 'N')
            ing = busca_pac(LH, x.dni);
        aux = LH;
        while (aux && cumple == 0)
        {
            if (aux->tipo == x.tipo)
            {
                act = aux->sub;
                if (x.hi == 'S')
                {
                    if (act && act->sig == NULL && strcmp(act->dni, "") == 0)
                    {
                        cumple = 1;
                        strcpy(act->dni, x.dni);
                    }
                }
                else
                {
                    if (act && act->sig)
                    {
                        while (act && strcmp(act->dni, ""))
                            act = act->sig;
                        if (act)
                        {
                            cumple = 1;
                            strcpy(act->dni, x.dni);
                        }
                    }
                }
            }
            aux = aux->sig;
        }
        if (aux == NULL)
            inserta(LDP, x);
        if (ing)
            strcpy(ing->dni, "");
        ctot++;
        cpos += cumple;
    }
    if (ctot > 0)
        printf("el porcentaje d pedidos concretados es %f", (100.0 * cpos / ctot), "%");
}

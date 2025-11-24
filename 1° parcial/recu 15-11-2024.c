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
    TLC nuevoC;
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

void ib(TLC LCP, TLS LSC, char cod[ST3]){
    TLS aux;
    TSL act;
    unsigned int ant;
    auxS = LSC;
    TElementoP x;
    while (auxS && strcmp(auxS->cod,cod))
        auxS = auxS->sig;
    if (auxS){
        act = LCP->sub;
        x.num = ant = 0;
        while (act){
            if (strcmp(act->cod,cod) == 0){
                x.num++;
                x.dur = act->hora - ant;
                ant = act->hora;
                cargaP(&(aux->P),x);
            }
            act = act->sig;
        }
        printf("%s %s %d",aux->ctt,aux->nom,consulta(aux->P));
    }
    else
        printf("el corredor no termino la carrera");
}

void cargaP(TPila *P, TElementoP x){
    TElementoP z;
    if (!vaciaP(*P)){
        sacaP(P,&z);
        if (x.dur > z.dur)
            cargaP(P,x);
        else
            poneP(P,z);
    }
    pone(P,x);
}

void corredores(TLS LS,char c1,char c2,char ctt){
    int i = 0;
    while (i < 2){
        if (strcmp(LS->ctt,ctt) == 0){
            i++;
            if (i == 1)
                strcpy(c1,LS->cod);
            else
                strcpy(c2,LS->cod);
        }
        LS = LS->sig;
    }
}

void ic(TLS LS, TLC LC,char ctt){
    TSL act,ant;
    TLC auxC;
    char c1,c2;
    int i;
    auxC = LC;
    corredores(LS,c1,c2,ctt);
    do{
        i = 0;
        auxC = auxC->sig;
        act = auxC->sub;
        ant = NULL;
        while (i < 2){
            elim = NULL;
            if (strcmp(act->cod,c1) == 0 || strcmp(act->cod,c2) == 0){
                i++;
                elim = act;
                act = act->sig;
                if (ant == NULL)
                    auxC->sub = act;
                else
                    ant->sig = act;
            }
            if (elim){
                free(elim);
            }
            else{
                ant = act;
                act = act->sig;
            }
        }
    }
    while (auxC != LC);
}
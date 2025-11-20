#include <stdio.h>
#include <string.h>
#include "pilas.h"
#define ST40 41
#define ST30 31
#define ST10 11
#define ST13 14


typedef struct nodoC{
    char rs[ST40];
    char prov[ST30];
    float porc;
    struct nodoC *sig;
} nodoC;

typedef nodoC *TListaC;

typedef struct {
    char rs[ST40];
    char prov[ST30];
    char mp[ST10];
    char fecha[ST10];
    char hora[ST10];
    char cuit[ST13];
    float importe;
} TRV;

typedef struct {
    char rs[ST40];
    float recb,recn;
} TRR;

void buscaMP(TPila *P, char mp[ST10], float *coef){
    TElementoP x;
    if (!vaciaP(*P)){
        sacaP(P,&x);
        if (strcmp(x.mp,mp) == 0)
            *coef = x.coef;
        else
            buscaMP(P,mp,porc);
        poneP(P,x);
    }
}

void ia(TListaC *LC,TPila *P){
    TRV rv;
    TRR rr;
    float coef;
    char act[ST40],prov[ST30];
    TListaC nuevo;
    FILE *aven = fopen("VENTAS.TXT","rt");
    FILE *ares = fopen("RESUMEN.DAT", "ab"); //asumo que se abren bien

    while (fscanf(aven, "%s %s %s %s %s %s %f",rv.rs,rv.prov,rv.mp,rv.fecha,rv.hora,rv.cuit,&rv.importe) == 7){
        if (cumple(rv.rs, rv.fecha)){
            strcpy(act, rv.rs);
            strcpy(prov,rv.prov);
            rr.recb = rr.recn = 0;
            while (strcmp(act,rv.rs) == 0 && !feof(aven)){
                if (cumple(rv.rs,rv.fecha)){
                    rr.recb += rv.importe;
                    rr.recn += rv.importe;
                }
                fscanf(aven, "%s %s %s %s %s %s %f", rv.rs, rv.prov, rv.mp, rv.fecha, rv.hora, rv.cuit, &rv.importe);
            }
            if (rr.recb > 0){
                strcpy(rr.rs,act);
                buscaMP(P, rv.mp, &coef);
                rr.recn = rr.recn * coef;
                fwrite(rr,sizeof(TRR),1,ares);
            }
            if (!esta(*LC,act)){
                nuevo = (TListaC)malloc(sizeof(nodoC));
                nuevo->porc = 4.5;
                strcpy(nuevo->prov,prov);
                strcpy(nuevo->rs, act);
                nuevo->sig = (*LC)->sig;
                (*LC)->sig = *LC = nuevo;
            }
        }
    }
    fclose(aven); fclose(ares);
}

void elimQ(TListaC *LC, char Q[ST30]){
    TListaC act, ant, elim;
    if (*LC){
        act = *LC->sig;
        ant = *LC;
        if (act == ant && strcmp(act->prov,Q) == 0){
            free(*LC);
            *LC = NULL;
        }
        else{
            do{
                if (strcmp(act->prov,Q)==0){
                    elim = act;
                    ant->sig = act = act->sig;
                    free(elim);
                }
                else{
                    ant = act;
                    act = act->sig;
                }
            }
            while (act != *LC);
            if (strcmp(act->prov,Q)==0){
                ant->sig = act->sig;
                *LC = ant;
                free(act);
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ST7 8
#define ST3 4
#define ST8 9
#define ST5 6
#include "colas.h"

typedef struct nodoS{
    char dom[ST7],fecha[ST8],hora[ST5];
    struct nodoS *sig;
} nodoS;

typedef nodoS *TLS;

typedef struct nodito{
    char dom[ST7];
    int obs;
    struct nodito *sig;
}nodito;

typedef nodito *TSL;

typedef struct nodoD{
    char puesto[ST3];
    TSL sub;
    struct nodoD *sig,*ant;
} nodoD;

typedef nodoD *PnodoD;

typedef struct{
    PnodoD pri,ult;
} TLD;

int incorrecto(char dom[ST7], char fecha[ST8]){
    int i;
    switch (strlen(dom)){
        case 7:i=6;
            break;
        case 6:i=5;
            break;
    }
    if ((dom[i-1] == '1' && dom[i-1] == '0') || dom[i-1] == '0')
        return dom[i] != fecha[7];
    else
        return 1;
}

void elimina_turnos(TLS *LS){
    int cont = 0;
    float prc = 0;
    TLS act,ant,elim;
    act = *LS;
    while (act){
        prc++;
        if (incorrecto(act->dom,act->fecha)){
            cont++;
            elim = act;
            act = act->sig;
            if (elim == *LS)
                *LS = act;
            else
                ant->sig = act;
            free(elim);
        }
        else{
            ant = act;
            act = act->sig;
        }
    }
    if (prc > 0)
        printf("el porcentaje de turnos eliminados es %5.2f",1.0*cont/prc*100);
}

int cuenta(TLD LD){
    PnodoD aux;
    int i=0;
    aux = LD.pri;
    while (aux)
        i++;
    return i;
}

int tiene_turno(TLS LS, char dom[ST7]){
    while (LS && strcmp(LS->dom,dom) <= 0 && LS->fecha[5] != '4')
        LS = LS->sig;
    return LS != NULL;
}

void simula(TLD LD, TCola *C, TLS LS){
    TCola Caux;
    TElementoC x;
    TSL act,ant,nuevo;
    PnodoD aux;
    int n,pos,i;
    n = cuenta(LD);
    while (!vaciaC(*C)){
        sacaC(C,&x);
        if (tiene_turno(LS,x.dom)){
            pos = rand() % N+1;
            if (pos){
                i = 0;
                nuevo = (TSL)malloc(sizeof(nodito));
                nuevo->obs = 0;
                strcpy(nuevo->dom,x.dom);
                nuevo->sig = NULL;
                aux = LD.pri;
                while (i < pos){
                    i++
                    aux = aux->sig;
                }
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
            else
                printf("no hay puestos disponibles");
        }
        else
            poneC(&Caux,x);
    }
    while(!vaciaC(Caux)){
        sacaC(&Caux,&x);
        poneC(C,x);
    }
}

/*void elimina_auto(PnodoD puesto, char dom[]){
    TSL act, ant;
    act = puesto;
    ant = NULL;
    while (strcmp(act->dom,dom) != 0){
        ant = act;
        act = act->sig;
    }
    if (ant)
        ant->sig = act->sig;
    else
        puesto->sub = act->sig;
    free(act);
}*/

void ejc(TLD LD){
    FILE *arch = fopen("TESTEOS.TXT","rt");
    char dom[ST7],puesto[ST3], estado;
    int obs;
    PnodoD aux;
    TSL act,ant;
    if (arch){
        while (fscanf(arch,"%s %s %d %c",puesto,dom,&obs,&estado) == 4){
            aux = LD.pri;
            while (strcmp(aux->puesto,puesto))
                aux = aux->sig;
            act = aux->sub; ant = NULL;
            while (strcmp(act->dom,dom)){
                ant = act;
                act = act->sig;
            }
            if (estado == 'R'){
                if (ant)
                    aux->sub = act;
                else
                    ant->sig = act->sig;
                free(act);
            }
            else
                act->obs += obs;
        }
    }
}
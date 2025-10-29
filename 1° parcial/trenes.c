#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"

typedef struct nodito{
    char dest;
    struct nodito *sig;
} nodito;

typedef nodito *TSLista;

typedef struct nodoD{
    char cod, nom[31];
    TSLista sub;
    struct nodoD *sig,*ant;
} nodoD;

typedef nodoD *PnodoD;

typedef struct {
    PnodoD pri, ult;
} TListaD;

void a(TListaD *LD){
    FILE * arch;
    int cant, i;
    char cod, nom[31], dest;
    PnodoD aux, nuevod;
    TSLista ant, nuevos;
    arch = fopen("INICIAL.TXT","rt");
    if (arch == NULL)
        printf("no abrio");
    else{
        while (fscanf(arch,"%c %s %d",&cod,nom,&cant) == 3){
            aux = LD->pri;
            while (aux && aux->cod < cod)
                aux = aux->sig;
            nuevod = (PnodoD)malloc(sizeof(nodoD));
            nuevod->cod = cod;
            strcpy(nuevod->nom,nom);
            nuevod->ant = nuevo->sig = NULL;
            if (LD->pri == NULL)
                LD->pri = LD->ult = nuevod;
            else
                if (aux == NULL){
                     LD->ult->sig = nuevod;
                     nuevod->ant = LD->ult;
                     LD->ult = nuevod;
                }
                else
                    if (aux->cod != cod)
                        if (aux == LD->pri){
                            nuevod->sig = aux;
                            aux->ant = nuevod;
                            LD->pri = nuevod;
                        }
                        else{
                            nuevod->sig = aux;
                            nuevod->ant = aux->ant;
                            aux->ant->sig = nuevod;
                            aux->ant = nuevod;
                        }
                    else{
                        free(nuevod);
                        nuevod = aux;
                    }
            act = nuevod->sub;
            ant = NULL;
            for (i=1 ; i<cant ; i++){
                fscanf(arch,"%d", &cod);
                while 
            }

        }
    }
}

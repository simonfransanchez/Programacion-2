#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ST15 16
#define ST20 21
#define ITP "DUKI"

typedef struct nodito{
    char id[ST15],titulo[ST20];
    unsigned int dur;
    struct nodito *sig;
} nodito;

typedef nodito *TSL;

typedef struct nodoD{
    unsigned int id;
    TSL sub;
    struct nodoD *sig,*ant;
} nodoD;

typedef nodoD *PnodoD;

typedef struct {
    PnodoD pri,ult;
} TLD;


void main(){}

PnodoD busca(TLD LD, unsigned int idp){
    PnodoD aux = NULL;
    if (LD.pri)     
        if (idp >= LD.pri && idp <= LD.ult){
            aux = LD.pri;
            while (aux->id < idp)
                aux = aux->sig;
            if (aux->id != idp)
                aux = NULL;
        }
    return aux;
}

void ai(TLD LD, TCola *C, unsigned int idx){
    TCola Caux;
    TElementoC x;
    PnodoD auxD;
    TSL auxS;
    long int tot = 0;
    while (!vaciaC(*C)){
        sacaC(C,&x);
        auxD = busca(LD,x.idp);
        if (auxD){
            auxS = auxD->sub;
            while (auxS && strcmp(auxS->id,x.idc) != 0)
                auxS = auxS->sig;
            if (auxS && (strncmp(auxS->id,ITP,4) != 0 || auxD->id != idx))
                tot += auxS->dur;
        }
        poneC(&Caux,x);
    }
    while (!vaciaC(Caux)){
        saca(&Caux,&x);
        poneC(C,x);
    }
    printf("el tiempo de reproduccion de la playlist es %d horas y %5.2f minutos",tot/3600,tot%3600 * 60);
}

void aii(TCola *C, unsigned int idx){
    TElementoC x;
    TCola Caux;
    while (!vaciaC(*C)){
        sacaC(C,&x);
        if (x.idp != idx || strncmp(x.idc,ITP,4) != 0)
            poneC(&Caux,x);        
    }
    while (!vaciaC(Caux)){
        sacaC(Caux,&x);
        poneC(C,x);
    }
}

void b(TLD LD, unsigned int x, unsigned int y, char id[]){
    PnodoD aux;
    TSL act,ant,elim;
    int cont = 0;
    if (LD.pri){
        printf("Intérprete: %s\n",id);
        aux = LD.pri;
        while (cont < 2){
            if (aux->id == x || aux->id == y){
                cont++;
                printf("PLAYLIST %u\n",aux->id);
                printf("id cancion\ttitulo cancion\n");
                act = aux->sub;
                while (act){
                    if (strncmp(act->id,id) == 0){
                        elim = act;
                        act = act->sig;
                        if (elim == aux->sub)
                            aux->sub;
                        else
                            ant->sig;
                        printf("%s\t%s",elim->id,elim->titulo);
                        free(elim);
                    }
                    else{
                        ant = act;
                        act = act->sig;
                    }  
                }
            }
        }
    }
}
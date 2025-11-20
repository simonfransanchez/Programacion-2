#include <stdio.h>
#include <string.h>
#include "colas.h"
#define ST7 8
#define ST3 4

typedef struct nodoC{
    char pat[ST7],vip,rad[ST3],lib;
    int cap;
    struct nodoC *sig;
} nodoC;

typedef nodoC *TLC

typedef struct nodoS{
    char pat[ST7];
    TCola C;
    struct nodoS *sig;
} nodoS;

typedef nodoS *TLS;

int verifica(char c, char rad[ST3]);
void agregaviaje(TLS LS,TElementoC x,char pat[ST7]);
void ia(TLC LC, TLS LS);
void ib(TLS LS);
void ic()

void main(){}

void agregaviaje(TLS *LS, TElementoC x, char pat[ST7]){
    TLS ant = NULL,act,nuevo;
    act = *LC;
    while (act && strcmp(act->pat,pat) == 1){
        ant = act;
        act = act->sig;
    }
    if (act)
        if (strcmp(act->pat, pat) == 0)
            poneC(&(act->C),x);
        else{
            nuevo = (TLS)malloc(sizeof(nodoS));
            strcpy(nuevo->pat,pat);
            iniciaC(&(nuevo->C));
            poneC(&(nuevo->C),x);
            if (ant == NULL){
                nuevo->sig = act;
                *LC = nuevo;
            }
            else{
                nuevo->sig = act;
                ant->sig = nuevo;
            }
        }
    else{
        nuevo->sig = NULL;
        ant->sig = nuevo
    }
}

int verifica(char c, char rad[ST3])
{
    int i = 0,aux = 0;
    while (i<strlen(rad) && !aux){
        aux = c == rad[i];
        i++; 
    }
    return aux;
}

void ia(TLC LC, TLS LS){
    FILE *arch = fopen("VIAJES.DAT","rb");
    TElementoC r;
    TLC auxC;
    int cumple, auto;
    if (arch){
        while (fread(&r,sizeof(TElementoC),1,arch) == 1){
            auxC = LC; auto = 0;
            do{
                auxC = auxC->sig;
                if (auxC->lib == 'S' && auxC->cap >= r.cant && verifica(r.rad,auxC->rad)){
                    if (auxC->vip == r.vip)
                        cumple = 1;
                    if (!(auxC->vip == 'S' && r.vip == 'N'))
                        auto = 1; 
                }          
            }
            while (auxC != LC && !cumple);
            if (auto){
                auxC->lib = 'N';
                agregaviaje(LS,r,auxC->pat);
                printf("%s",auxC->pat);
            }
            else
                printf("no se pudo");
        }
    }
    else
        printf("no se abrio el archivo papu");
    fclose(arch);
}
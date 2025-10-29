#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void pasaP(TPila *P, TPila *PA);
void a(TPila *P, int *cant);
void b(TPila *P, float *prom);
void c(TPila *P, int *max, int *min);

void main(){}

void pasaP(TPila *P, TPila *PA){
    int aux;
    while (!vaciaP(*P)){
        sacaP(P,&aux);
        poneP(PA,aux);
    }
}

void a(TPila *P, int *cant){
    int aux;
    *cant = 0;
    while (!vaciaP(*P)){
        sacaP(P,&aux);
        if (aux == 0) 
            (*cant)++;
    }
}

void b(TPila *P, float *prom){
    TPila PA;
    int aux, cont = 0;
    *prom = 0;
    while (!vaciaP(*P)){
        cont++;
        sacaP(P,&aux);
        *prom += aux;
        poneP(&PA,aux);
    }
    pasaP(&PA,P);
}

void c(TPila *P, int *max, int *min){
    TPila PA;
    int aux;
    if (!vaciaP(*P)){
        sacaP(P,&aux);
        *max = *min = aux;
        poneP(&PA,aux);
        while (!vaciaP(P)){
            sacaP(P,&aux);
            if aux>*max
                *max = aux
            else
                if aux<*min
                    *min = aux;
            poneP(&PA,aux);
        }
        pasaP(&PA,P);
    }

}
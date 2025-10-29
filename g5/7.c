#include <stdio.h>
#include "pilas.h"

void muestra(TPila *P);

void main(){}

void muestra(TPila *P){
    TElementoP x;
    if (!vaciaP(*P)){
        sacaP(P,&x);
        printf("%d",x);
        muestra(P);
        poneP(P,x);
    }    
}


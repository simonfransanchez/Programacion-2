#include <stdio.h>
#include "pilas.h"

void transforma(TPila *P);

void main(){}

void transforma(TPila *P){
    int x;
    if (!vaciaP(*P)){
        sacaP(P,&x);
        transforma(TPila P);
        x = x*(-1);
        poneP(P,x);
    }
}
#include <stdio.h>
#include "pilas.h"

typedef struct nodito{

}


void main(){}

void eja(TPila *P){
    FILE *arch = fopen("REMERAS.DAT","rb");
    TElementoP x;
    if (arch){
        iniciaP(P);
        while (fread(&x,sizeof(TElementoP),1,arch) == 1){
            poneP(&P,x);
        }
    }
    else
        printf("no se abrio el archivo");
}

void ejb(TLS *LS)
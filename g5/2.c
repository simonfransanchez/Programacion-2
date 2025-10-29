#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

int main(){
    char c;
    TPila P,PA;
    FILE * arch = fopen("caracteres.txt","rt");
    iniciaP(&P);
    iniciaP(&PA);
    while (fscanf(arch,"%c",c)==1)
        poneP(&P,c);
    while (!vaciaP(P)){
        sacaP(&P,&c);
        printf("%c",c)
        poneP(&PA,c);
    }
    while (!vaciaP(PA)){
        sacaP(&PA);
        poneP(&P);
    }
    return 0;
}
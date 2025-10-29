#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#define MAX 20;
int main(){
    TPila P,PA;
    char c[MAX];
    FILE * arch = fopen("votantes.txt","rt");   //ASUMO QUE ABRIO Y NO ES NULO
    iniciaP(&P);
    iniciaP(&PA);
    while (fscanf(arch,"%s",c) == 1)
        poneP(&P);
    while (!vaciaP(P)){
        sacaP(&P,&c);
        printf("%s",c);
        poneP(&PA,c);
    }
    while (!vaciaP(PA)){
        sacaP(&PA,&c);
        printf("%s",c);
    }
    return 0;
}
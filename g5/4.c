#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

void main(){
    TCola C;
    FILE * arch = fopen("numeros.txt","rt");
    int n;
    while (fscanf(arch,"%d",n)==1)
        poneC(&C,n);
       
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

void ej1a(int mat[][MAX], int n, int i, int j, int gr, TCola *C, int *acum){
    if (i>=0){
        if(j>=0){
            if (j<=i)
                *acum += mat[i][j];
            if (mat[i][j] > 0)
                gr++;
            ej1a(mat,n,i,j-1,gr,C,acum);
        }
        else{
            if (gr>1){
                TElementoC x;
                x.vert = i;
                x.gr = gr;
                poneC(C,x);
            }
            ej1a(mat,n,i-1,n,0,C,acum);
        }
    }
}

int ej3(arbolN A, pos p, int k, int n){
    pos c;
    int aux = 0;
    if (!nulo(p) && n <= k){
        c = hijomasizq(p,A);
        if (nulo(c))
            aux += info(p,A) == 0;
        else{
            while (!nulo(c)){
                aux += ej3(A,c,k,n+1);
                c = hnoder(c,A);
            }
        }
    }
    return aux;
}
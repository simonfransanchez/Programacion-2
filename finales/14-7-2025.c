#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ST20 21
#define MAX 20

typedef struct nodoC{
    char pal[ST20];
    struct nodoC *sig;
} nodoC;

typedef nodoC *TLC;

int es_vocal(char c){
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
}

int cuenta_voc(char s[]){
    int i,cont = 0,n = strlen(s);
    for (i = 0 ; i < n ; i++)
        cont += es_vocal(s[i]);
    return cont;
}

int verifica(TLC LC, int cant){
    TLC aux;
    int cumple = 0;
    if (LC){
        aux = LC;
        do{
            aux = aux->sig;
            cumple = cuenta_voc(aux->pal) == cant;
        }
        while (aux != LC && cumple == 0);
    }
    return cumple;
}

int ej1a(char mat[][MAX], TLC LC, int i, int j, int n, int cant){
    if (i<0)
        return 0;
    else
        if (j<0)
            return verifica(LC,cant) || ej1a(mat,LC,i-1,n,n,0);
        else{
            cant += es_vocal(mat[i][j]);
            return ej1a(mat,LC,i,j-1,n,cant);
        }
}

void ej1b(TLC LC, TCola *C, char c){
    TLC aux;
    TElementoC x;
    if (LC){
        iniciaC(C);
        aux = LC;
        do{
            aux = aux->sig;
            if (aux->pal[0] == c){
                x.cv = cuenta_voc(aux->pal);
                x.cc = strlen(aux->pal) - cuenta_voc(aux->pal);
                poneC(C,x);
            }
        }
        while (aux != LC);
    }
}

int ej2(arbolN A, pos p){
    pos c;
    if (nulo(p))
        return 1;
    else
        if (nulo(hijomasizq(p,A))){
            c = hnoder(p,A);
            if (!nulo(c))
                return es_vocal(info(c,A)) && ej2(A,c);
            else
                return 1;
        }
        else
            return ej2(A,hijomasizq(p,A)) && ej2(A,hnoder(p,A));
}

int ej3(int mat[][MAX], int n){
    int cont, i, j, acum;
    for (i = 0 ; i < n ; i++)
        if (mat [i][i] > 0){
            acum = 0;
            for (j = 0 ; j < i ; j++)
                acum += mat[i][j];
            for (j = i+1 ; j < n ; j++)
                acum += mat[i][j];
            cont += acum > mat[i][i];
        }
    return cont;
}
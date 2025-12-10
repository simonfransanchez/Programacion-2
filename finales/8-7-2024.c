#include "pilas.h"
#include <stdio.h>
#include <stdlib.h>
#define ST10 11
#define ST4 5
#define MAX 5
#define MES 7

typedef struct nodito{
    unsigned int cod,num,dur;
    float imp;
    char fecha[ST4];
    struct nodito *sig;
} nodito;

typedef nodito *TSL;

typedef struct nodoC{
    char nom[ST10]
    float tot;
    unsigned int cant;
    TSL sub;
    struct nodoC *sig;
} nodoC;

typedef nodoC *TLC;

typedef struct{
    unsigned int cod,nc1,nc2;
    char fecha[ST4];
} TRA;

TLC busca(TLC LC, char x[]){
    TLC aux = NULL;
    if (LC){
        if (strcmp(LC, x) > 0){
            aux = LC;
            do
                aux = aux->sig;
            while (aux != LC && strcmp(aux->nom,x) < 0);
        }
        else 
            if (strcmp(aux->nom, x) < 0)
    }
    return aux;
}

void ej2i(TLC LC, char x[]){
    FILE *arch;
    TLC auxC;
    TRA r;
    TSL auxS;
    int cont = 0;
    arch = fopen("CAMBIOS.DAT","rb");
    if (arch){
        auxC = busca(LC, x);
        if (auxC){
            if (auxC->sub){
                while (fread(&r,sizeof(TRA),1,arch) == 1){
                    auxS = auxC->sub;
                    while (auxS && auxS->cod < r.cod)
                        auxS = auxS->sig;
                    if (auxS->cod == r.cod && r.nc1 == auxS->num){
                        auxS->num = r.nc2;
                        strcpy(auxS->fecha,r.fecha);
                    }
                    else
                        cont++;
                }
                printf("hubieron %d errores",cont);
            }
            else
                printf("no hay obras a realizar");
        }
        else
            printf("la ciudad %s no se encuentra registrada",x);
    }
    else
        printf("no abrio el archivo");
}

void ej2ii(TLC LC, TPila *P, char c[], unsigned int k, unsigned int x, float f){
    TElementoP xp;
    TLC auxC;
    TSL act,ant,elim;
    int v[MAX] = {0}, mes, i;
    auxC = busca(LC,c);
    if (auxC){
        act = auxC->sub;
        while (act){
            if ((act->num == k || act->num == x) && act->imp > f){
                elim = act;
                act = act->sig;
                if (elim == auxC->sub)
                    auxC->sub = act;
                else
                    ant->sig = act;
                xp.imp = elim->imp;
                xp.dur = elim->dur;
                strcpy(x.fecha,elim->fecha);
                poneP(P,x);
                mes = (x.fecha[0] - '0') * 10 + (x.fecha[1] - '0');
                v[mes-MES]++;
            }
        }
        for (i = 0 ; i < MAX ; i++)
            printf("Mes %d: %d obras pospuestas\n");
    }
    else
        printf("la ciudad %s no se encuentra registrada", c);
}

int ej3(arbolN A, pos p){ // ej3(A,raiz(A))
    pos c;
    int aux = 0, gr = 0;
    if (!nulo(p)){
        c = hijomasizq(p,A);
        while (!nulo(c) && aux < 3){
            gr++;
            aux += ej3(A,c);
            c = hnoder(c,A);
        }
        aux += gr == 3;
    }
    return aux;
}

int ej4(int mat[][10], int i, int j, int n, int cant, int gr){
    if (cant < 3)
        if (i<0)
            return 0;
        else
            if (j<0){
                if (gr == 3)
                    cant++;
                return ej4(mat,i-1,n,n,cant,0);
            }    
            else{
                if (mat[i][j] > 0)
                    gr++;
                return ej4(mat,i,j-1,n,cant,gr);
            }
    else
        return 1;

}
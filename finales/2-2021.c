#include <stdio.h>
#include <stdlib.h>

typedef struct nodito{
    int div;
    struct nodito *sig;
} nodito;

typedef nodito *TSL;

typedef struct nodoD{
    int n;
    TSL sub;
    struct nodoD *sig, *ant;
} nodoD;

typedef nodoD *PnodoD;

typedef struct{
    PnodoD pri,ult;
} TLD;

PnodoD busca(TLD LD, int k){
    PnodoD aux = NULL;
    if (LD.pri->n <= k && LD.ult->n >= k){
        aux = LD.pri;
        while (aux && aux->n != k)
            aux = aux->sig;
    }
    return aux;
}

void ej2i(TLD LD, int k){
    PnodoD aux;
    TSL act,ant,elim;
    int cont = 0;
    aux = busca(LD,k);
    if (aux){
        act = aux->sub;
        while (act)
            if (aux->n%act->div != 0){
                cont++;
                elim = act;
                act = act->sig;
                if (elim == aux->sub)
                    aux->sub = act;
                else
                    ant->sig = act;
                free(elim);
            }
            else{
                ant = act;
                act = act->sig;
            }
        if (cont > 0)
            printf("se eliminaron %d numeros",cont);
        else
            printf("todos los numeros son divisores de %d",aux->n);
    }
    else
        printf("no esta");
}

void ej2ii(TLD LD, int x){
    PnodoD aux;
    FILE *arch;
    TSL auxS;
    int i;
    if (LD.pri){
        arch = fopen("DIVI.TXT", "w");
        if (arch){
            aux = LD.pri;
            while (aux){
                if (aux->n % 2 == 0){
                    i = 0;
                    auxS = aux->sub;
                    while (auxS && i<=x){
                        i++;
                        auxS = auxS->sig;
                    }
                    if (i == x)
                        fprintf(arch,"%d\n",aux->n);
                }
                aux = aux->sig;
            }
        }
        else
            printf("no se abrio el archivo")
    }
    else
        printf("la lista esta vacia");
    close(arch);
}

void ej3(arbolN A, pos p, int k, int n, int *nivel){ //main: nivel = 999999, inicia  ej3(A,Raiz(A),k,1,&nivel);
    pos c;
    if (!nulo(p) && n <= *nivel){
        c = hijomasizq(A,p);
        ej3(A,c,k,n+1,nivel);
        if (info(p,A) == k)
            *nivel = n;
        else
            while (!nulo(p)){
                c = hnoder(c,A);
                ej3(A,c,k,n,nivel);
            }
    }
}

void determina(TElementoP x, TLA v){
    
}

void ej4(TPila *P, TLA v[]){
    TElementoP x;
    int aux;
    if (!vaciaP(*P)){
        sacaP(P,&x);
        ej4(P,v);
        aux = determina(x,v);
        if (aux){
            poneP(P,x);
        }
    }
}
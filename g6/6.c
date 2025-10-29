#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct nodito{
    char nom[MAX], est;
    int edad;
    struct nodito *sig;} nodito;

typedef nodito *TSLista;

typedef struct nodo{
    char nom[MAX]:
    int p;
    TSLista sub;
    struct nodo *sig;} nodo;

typedef nodo * TLista;

void a(TLista L, char k);
void b(TLista L, int x);
int c(TLista L, char e[], int p);
void d(TLista L);

void main(){}

void a(TLista L, char k){
    TSLista aux;
    int cant_list, max = 0, tot_list = 0;
    char club[MAX];
    while (L){
        aux = L->sub;
        cant_list = 0;
        printf("%s\n",L->nom)
        while (aux){
            if (aux->nom[0] == k){
                printf("%s\n",aux->nom);
                cant_list++;
            }
            aux = aux->sig;
        }
        if (cant_list > max){
            max = cant_list;
            strcpy(club,L->nom);
        }
        L = L->sig;
    }
}

void b(TLista L, int x){
    float prom = 0;
    int contj;
    TSLista aux;
    while (L->p >= x){
        printf("%s\n",L->nom);
        contj = 0;
        prom = 0;
        aux = L->sub;
        while (aux){
            contj++;
            prom += aux->edad;
            printf("%s\n",aux->nom);
            aux = aux->sig;            
        }
        printf("el promedio de edad en %s es %f\n\n",L->nom,prom/contj);   
        L = L->sig;
    }
}

int c(TLista L, char e[], int p){
    while (L!=NULL && strcmp(L->nom,e) != 0)
        L = L->sig;
    if (L)
        return (L->p == p);
    else
        return 0;
}

void d(TLista L)
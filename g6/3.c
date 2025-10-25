#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct nodo{
    char pal[MAX];
    int frec;
    struct nodo *sig;} nodo;

typedef nodo *TLista;

int esta(TLista L, char s[]);
void cargaL(TLista *L);

void main(){}

/*int esta(TLista L, char s[]){
    while ((L != NULL) && (strcmp(L->dato,s) != 0)){
        L = L->sig;
    }
    if (L == NULL)
        return 0;
    else
        return 1;
}*/

/*void cargaL(TLista *L){
    FILE *arch = fopen("palabras.txt","rt");
    TLista aux,nuevo;
    if (arch == NULL)
        printf("no abrio el arch");
    else{
        char s[MAX];
        nuevo = (TLista)malloc(sizeof(nodo));
        if (*L == NULL){
            fscanf(arch,"%s",s); 
            strcpy(nuevo->dato,s);
            nuevo->frec = 1;
            nuevo->sig = NULL;
            *L = nuevo;
        }
        else 
            while (fscanf(arch,"%s",s) == 1){
            }
    }    
}*/


void carga(TLista *L){
    FILE *arch = fopen("palabras","rt");
    TLista nuevo, act, ant;
    act = *L;
    if (arch){
        while (fscanf(arch,"%s",s) == 1){
            while (act != NULL && strcmp(s,act->pal)>0){
                ant = act;
                act = act->sig;
            }
            if (strcmp(s,act->pal) == 0)
                (act->frec)++;
            else{
                nuevo = (TLista)malloc(sizeof(nodo));
                nuevo->frec = 1;
                strcpy(nuevo->pal,s);
                if (strcmp(s,act->pal)<0){
                    nuevo->sig = ant->sig;
                    ant->sig = nuevo;
                }
                else{
                    nuevo->sig = NULL;
                    *L = nuevo;
                }
            }
        }
    }

}
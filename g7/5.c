#include <stdlib.h>

int prof(arbol A);
int cadmasl(arbol A);
int cantder(arbol A);

void main(){}

int prof(arbol A){
    if (!A)
        return -1;
    else
        return 1 + (prof(A->izq)>prof(A->der))? prof(A->izq):prof(A->der);
}

int cadmasl(arbol A){
    if (!A)
        return 0;
    else{
        int max = strlen(A->dato)
        int maxi = cadmasl(A->izq);
        int maxd = cadmasl(A->der);
        if (maxi > maxd)
            if (maxi > max)
                return maxi;
            else
                return max;
        else
            if (maxd > max)
                return maxd;
            else
                return max;
    }
}


#include <stdio.h>
#include <stdlib.h>

/*int ej2(arbol1 A, pos p, int n, int k)
{
    pos c;
    int acum = 0, gr = 0, aux = 1;
    if (!nulo(p) && n < k)
    {
        c = hijomasizq(p);
        while (!nulo(c) && aux)
        {
            gr++;
            acum += info(c, A);
            aux = ej2(A, c, n + 1, k);
            c = hnoder(c);
        }
        if (gr > 0 && gr % 2 == 0 && info(p, A) > 0)
            if (aux)
                aux = (1.0 * acum / gr >= 2 * info(p, A));
    }
    return aux;
}*/

typedef struct nodoady
{
    int vert, peso;
    struct nodoady *sig;
} nodoady;

typedef nodoady *TLista;

int ej2(arbolN, pos p, int k, int n)
{
    pos c;
    int aux = 1, gr = 0, acum = 0, dato;
    if (!nulo(p) && n < k)
    {
        dato = info(p, A);
        c = hijomasizq(p);
        if (!nulo(c))
        {
            while (!nulo(c) && aux)
            {
                gr++;
                acum += info(c, A);
                aux = ej2(A, c, k, n + 1);
                c = hnoder(c);
            }
            if (aux)
                aux = (dato > 0 && gr % 2 == 0 && 1.0 * acum / gr >= dato);
        }
    }
    return aux;
}

int obtiene(TLista v[], int n)
{
    int i, cant, min = 99999, bucle;
    TLista elim, antelim, act, ant;
    for (i = 0; i <= n; i++)
    {
        if (v[i])
        {
            act = v[i];
            bucle = 0;
            elim = NULL;
            while (act && elim == NULL)
            {
                if (act->vert == i)
                    bucle = act->peso;
                else
                {
                    if (act->peso < min)
                    {
                        min = act->peso;
                        antelim = ant;
                    }
                    if (bucle > min)
                        elim = antelim->sig;
                }
                ant = act;
                act = act->sig;
            }
            if (elim)
            {
                cont++;
                antelim->sig = elim->sig;
                free(elim);
            }
        }
    }
    return cont;
}

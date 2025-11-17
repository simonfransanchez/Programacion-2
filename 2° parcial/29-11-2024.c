#include <stdio.h>

#include "nario.h"

int verifica(arbolN A, pos p)
{
    pos c, h;
    int pri;
    c = h = hijomasizq(p, A);
    if (!nulo(c))
    {
        pri = info(c, A);
        c = hnoder(c, A);
        if (!nulo(c) && pri == info(c, A))
        {
            while (!nulo(c))
            {
                h = hnoder(h);
                c = hnoder(c);
            }
            return pri != info(h, A);
        }
        else
            return 0;
    }
    else
        return 0;
}

int nmin(arbolN A, pos p, int n)
{
    int izq, der;
    if (nulo(p))
        return 9999;
    else if (verifica(A, p))
        return n;
    else
    {
        izq = nmin(A, hijomasizq(p, A), n + 1);
        der = nmin(A, hnoder(p, A), n);
        return (izq < der) ? izq : der;
    }
}

void nminalt(arbolN A, pos p, int n, int *nivel)
{ // main: nivel = 9999
    if (!nulo(p) && n < *nivel)
        if (verifica(A, p))
            *nivel = n;
        else
        {
            nminalt(A, hijomasizq(p, A), n + 1, nivel);
            nminalt(A, hnoder(p, A), n, nivel);
        }
}
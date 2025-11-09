#include <stdio.h>
#include <stdlib.h>

int ej2(arbol1 A, pos p, int n, int k)
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
}
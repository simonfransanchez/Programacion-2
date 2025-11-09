

int ej(arbol A, pos p)
{
    pos c;
    int aux = 0, condh = 1, gr = 0;
    if (!nulo(p))
    {
        c = hijomasizq(p, A);
        while (!nulo(c) && aux == 0)
        {
            gr++;
            if (!esvocal(info(c, A)))
                condh = 0;
            aux = ej(A, p);
            c = hnoder(c);
        }
        if (aux == 0)
            aux = (gr > 0 && gr % 2 == 0 && esvocal(info(p)) && condh);
    }
    return aux;
}

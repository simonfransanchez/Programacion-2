


int suma(arbol A, int nact, int x){     // llamo con (A,1,x)
    if (!A || (!A->izq && !A->der))
        return 0;
    else
        if ((A->izq && !A->der) || (!A->izq && A->der) && x == nact)
            return A->dato;
        else
            return suma(A->izq,nact+1,x) + suma(A->der,nact+1,x);
}   
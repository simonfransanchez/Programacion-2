
void muestra(arbol A, int niv, int x){
    if (!A && niv < x){
        muestra(A->izq,niv+1,x);
        muestra(A->der,niv+1,x);
    }
    else
        if (niv == x)
            printf("%s",A->dato);
}

void muestratodo(arbol A){
    if (A)
        if(!A->izq && !A->der){
            printf("%s",A->dato);
        else{
            muestratodo(A->izq);
            muestratodo(A->der);
        }
    }
}
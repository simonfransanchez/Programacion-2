


void nivel(arbol A, int nact, int *nmax, int *max){ // llamo con nivel(A,0,0,0)
    if (!A){
        nact++;
        if (A->dato[0] == 'A' && strlen(A->dato) > max){
            *max = strlen(A->dato);
            *nmax = nact;
        } 
        nivel(A->izq,nact + 1,nmax,max);
        nivel(A->der,nact + 1,nmax,max);
    }
}
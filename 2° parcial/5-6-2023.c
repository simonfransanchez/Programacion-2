

//EJERCICIO 1
void ej1(arbol A, int n, int k, int v[]){
    if (A && n<=k){
        if (!esvocal(A->dato))
            v[n]++;
        ej1(A->izq,n+1,k,v);
        ej1(A->der,n,k,v);
    }
}

// EJERCICIO 2
int ej2(arbolN A, pos p, int G){
    pos c;
    int gr = 0, aux = 0, dato;
    if (!nulo(p))
        dato = info(A,p);
        aux = (gradoN(A,p) == G && dato<0 && dato%2 != 0);
        c = hijomaizq(A,p);
        while (!nulo(c) && aux == 0){
            aux = ej2(A,c,G);
            c = hnoder(c,A);
        }
    return aux;
}

//EJERCICIO 3
void muestra(int mat[][MAX], int n){
    int gre,grs,i,j,contv;
    for(i = 0; i<n ; i++){
        grs = gre = 0;
        while(j<n && mat[i][i]){
            grs += mat[i][j];
            gre += mat[j][i];
            j++;
        }
        if (mat[i][i] && gre == grs){
            contv++;
            printf("%c",('A' + i));
        }
    }
    printf("porcentaje es %f",)
}
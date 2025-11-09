/*Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice*/

#define MAX 10

int grent(int mat[][MAX], int n, int vert){
    int i, gr = 0;
    for (i = 0 ; i<=n ; i++)
        gr += mat[i][vert];
    return gr;
}

int grsal(int mat[][MAX], int n, int vert){
    int i, gr = 0;
    for (i = 0 ; i<=n ; i++)
        gr += mat[vert][i];
    return gr;
}

int grado(int mat[][MAX], int n, int vert){
    int i, gr = 0;
    for (i = 0 ; i<=n ; i++)
        gr += mat[vert][i];
    for (i = 0 ; i<=n ; i++)
        gr += mat[i][vert];
    
    return gr;
}
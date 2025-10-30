/*23. Dado un árbol N-ario de enteros, desarrollar funciones utilizando TDA N.ARIO para:
a) retornar la cantidad de nodos que posee.
b) hallar el porcentaje de claves pares
c) retornar su grado
d) hallar la cantidad de nodos de grado impar que hay en niveles impares.
e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual
a la cantidad de hijos. (función int y función void)
f) obtener el promedio de las claves del nivel K (dato)*/

int cant(arbol A, pos p)
{
    int cont = 0;
    pos c;
    if (!nulo(p))
    {
        cont++;
        c = hijomasizq(p);
        while (c)
        {
            cont += cant;
            c = hnoder(c);
        }
    }
    return cont;
}

void porc(arbol A, pos p, int *ctot, int *cpar){
    pos c;
    if (!nulo(p)){
        *ctot++;
        if (info(p) % 2 == 0)
            *cpar;
        porc(A,hijomasizq(p),ctot,cpar);
        porc(A,hnoder(p),ctot,cpar);
    }
}

int grado(arbol A, pos p){
    pos c;
    int act = 0, gr = 0, max = 0;
    if (!nulo(p)){
        c = hijomasizq(p);
        while (!nulo(c)){
            act++;
            gr = grado(A,c);
            if (gr > max)
                max = gr;
            c = hnoder(c);
        }
        max = (act > max)? act:max;
    }
    return max;
}

int cantimp(arbol A, pos p){
    pos c;
    int cont = 0;
    if (!nulo(p)){
        
    }
}
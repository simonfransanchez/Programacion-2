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
    if (A)
    {
        cont++;
        c = hijomasizq(p);
        while (c)
        {
            cont += cant;
            c = hnoder(c);
        }
    }
    return 0;
}

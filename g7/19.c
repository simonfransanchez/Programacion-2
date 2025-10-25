/*Dado un árbol binario que proviene de la transformación de un bosque, determinar qué
cantidad de árboles lo componían. */

int cantA(arbol bosque)
{
    int i = 0;
    while (bosque)
    {
        i++;
        bosque = bosque->der;
    }
}
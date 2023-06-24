#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden. (sin variables enteras, solo pilas)
int main()
{
    Pila a,aux,valor;

    inicpila(&a);
    inicpila(&aux);
    inicpila(&valor);

    apilar(&a, 5);
    apilar(&a, 3);
    apilar(&a, 2);
    apilar(&a, 1);

    leer(&valor);


    while(!pilavacia(&a)){
        if (tope(&a) < tope(&valor)){
            apilar(&aux, desapilar(&a));
        } else {
            apilar(&a, desapilar(&valor));
        }
    }

    while(!pilavacia(&aux)){
        apilar(&a, desapilar(&aux));
    }

    mostrar(&a);

    return 0;
}

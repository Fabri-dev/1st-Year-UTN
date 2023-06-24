#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila a, aux, impar, par;
    inicpila(&par);
    inicpila(&a);
    inicpila(&aux);
    inicpila(&impar);

    printf("PILA A \n ");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);




    while(!pilavacia(&a)){
        apilar(&aux, desapilar(&a));
        if (!pilavacia(&a)){
            apilar(&aux, desapilar(&a));
        } else {
            apilar(&impar, desapilar(&aux));
        }
    }

    if (!pilavacia(&impar)){
        printf("LA PILA ES IMPAR PUTOOO");
    } else {
        apilar(&par, desapilar(&aux));
        printf("LA PILA ES PAR GIL");
    }

    return 0;
}

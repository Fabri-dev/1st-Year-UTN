#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila modelo, a, aux;
    inicpila(&aux);
    inicpila(&modelo);
    inicpila(&a);

    printf("PILA MODELO \n");
    leer(&modelo);


    printf("PILA A \n");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);

    mostrar(&modelo);
    mostrar(&a);

    while(!pilavacia(&a) && !pilavacia(&modelo)){
        if (tope(&a)!= tope(&modelo)){
            apilar(&aux, desapilar(&a));
        }
        else{
            desapilar(&a);
        }
    }

    while(!pilavacia(&aux)){
        apilar(&a, desapilar(&aux));
    }

    printf("Quedaron unicamente los elementos que tengan distinto valor que el tope de pila MODELO \n");

    mostrar(&modelo);
    mostrar(&a);

    return 0;
}

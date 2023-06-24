#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila a, b, auxA, auxB;

    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    printf("PILA A: ");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);

    printf("PILA B: ");
    leer(&b);
    leer(&b);
    leer(&b);
    leer(&b);
    leer(&b);



    mostrar(&a);
    mostrar(&b);

    while(!pilavacia(&a) && !pilavacia(&b) && (tope(&a) == tope(&b)))
    {
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));

    }

    if (pilavacia(&a) && pilavacia(&b))
    {
        printf("Las pilas son iguales");
    }
    else
    {
        printf("Las pilas son distintas");
    }

    while(!pilavacia(&auxA) && !pilavacia(&b))
    {
        apilar(&a, desapilar(&auxA));
        apilar(&b, desapilar(&auxB));
    }

    mostrar(&a);
    mostrar(&b);

    return 0;
}

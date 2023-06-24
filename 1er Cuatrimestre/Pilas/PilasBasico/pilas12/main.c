#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila modelo, a, auxA, auxM;
    inicpila(&auxM);
    inicpila(&auxA);
    inicpila(&modelo);
    inicpila(&a);

    printf("PILA MODELO \n");
    leer(&modelo);
    leer(&modelo);



    printf("PILA A \n");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);

    mostrar(&modelo);
    mostrar(&a);

    while(!pilavacia(&modelo))
    {
        while(!pilavacia(&a))
        {
            if (tope(&a)== tope(&modelo))
            {

                desapilar(&a);
            }
            else
            {
                apilar(&auxA, desapilar(&a));
            }
        }
        while (!pilavacia(&auxA)){
            apilar(&a, desapilar(&auxA));
        }
        apilar(&auxM, desapilar(&modelo));
    }



    while(!pilavacia(&auxA))
    {
        apilar(&a, desapilar(&auxA));
    }

    printf("---Quedaron unicamente los elementos que tengan igual valor que el tope de pila MODELO ---\n");

    mostrar(&modelo);
    mostrar(&a);

    return 0;
}

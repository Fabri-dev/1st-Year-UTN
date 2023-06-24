#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila a,b,aux,ayb;
    char op;

    inicpila(&a);
    inicpila(&b);
    inicpila(&aux);
    inicpila(&ayb);

    do
    {
        printf("INGRESE ELEMENTOS EN PILA A \n");
        leer(&a);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);

    }
    while (op == 's');

    do
    {
        printf("INGRESE ELEMENTOS EN PILA B \n");
        leer(&b);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);

    }
    while (op == 's');


    while(!pilavacia(&a))
    {
        while(tope(&a) < tope(&ayb)){
            apilar(&aux, desapilar(&ayb));
        }
        if (tope(&a) > tope(&ayb) || pilavacia(&ayb)){
            apilar(&ayb, desapilar(&a));
        }
        while(!pilavacia(&aux)){
            apilar(&ayb, desapilar(&aux));
        }
    }



    mostrar(&a);
    mostrar(&b);
    mostrar(&ayb);
    mostrar(&aux);

    return 0;
}

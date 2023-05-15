#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila pilota, especial, aux;
    char op='s';

    inicpila(&pilota);
    inicpila(&aux);
    inicpila(&especial);

    do {
            leer(&pilota);
            printf("Desea continuar? s/n :");
            fflush(stdin);
            scanf("%c", &op);
    } while (op == 's');

    mostrar(&pilota);

    apilar(&especial,desapilar(&pilota));

    mostrar(&especial);

    while(!pilavacia(&pilota)){
        apilar(&aux, desapilar(&pilota));
    }

    mostrar(&aux);

    apilar(&pilota, desapilar(&especial));

    while(!pilavacia(&aux)){
        apilar(&pilota, desapilar(&aux));
    }

    printf("PILOTA");
    mostrar(&pilota);
    printf("AUX");
    mostrar(&aux);
    printf("ESPECIAL");
    mostrar(&especial);







    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int main()
{
    Pila dada, distinta, pilota;
    char op='s';

    inicpila(&pilota);
    inicpila(&dada);
    inicpila(&distinta);

    do {
            leer(&pilota);
            printf("Desea continuar? s/n :");
            fflush(stdin);
            scanf("%c", &op);
    } while (op == 's');

    printf("PILOTA: \n");
    mostrar(&pilota);
    while(!pilavacia(&pilota)){
        if (tope(&pilota) != 8){
        apilar(&distinta, desapilar(&pilota));
    } else {
        apilar(&dada, desapilar(&pilota));

    }

    }

    printf("PILOTA: \n");
    mostrar(&pilota);
    printf("DADA: \n");
    mostrar(&dada);
    printf("DISTINTA: \n");
    mostrar(&distinta);


    return 0;
}

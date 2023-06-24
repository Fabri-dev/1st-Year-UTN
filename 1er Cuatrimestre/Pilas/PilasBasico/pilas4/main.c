#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
 Pila origen, aux, destino;
 char op= 's';

 inicpila(&origen);
 inicpila(&aux);
 inicpila(&destino);

     do {
            leer(&origen);
            printf("Desea continuar? s/n :");
            fflush(stdin);
            scanf("%c", &op);
    } while (op == 's');

    printf("ORIGEN: \n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&aux, desapilar(&origen));
    }
    while(!pilavacia(&aux)){
        apilar(&destino, desapilar(&aux));
    }

    printf("ORIGEN: \n");
    mostrar(&origen);
    printf("DESTINO: \n");
    mostrar(&destino);


    return 0;
}

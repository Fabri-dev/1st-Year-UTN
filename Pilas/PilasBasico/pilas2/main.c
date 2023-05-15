#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila origen, destino;
    char op='s';


    inicpila(&origen);
    inicpila(&destino);

    do {
            leer(&origen);
            printf("Desea continuar? s/n :");
            fflush(stdin);
            scanf("%c", &op);
    } while (op == 's');

    printf("ORIGEN: \n");
    mostrar(&origen);
    printf("... llevando todos los datos a pila destino... \n");

    while(!pilavacia(&origen)){
           apilar(&destino, desapilar(&origen));
    }

    printf("ORIGEN: \n");
    mostrar(&origen);

    printf("DESTINO: \n");
    mostrar(&destino);

    return 0;
}

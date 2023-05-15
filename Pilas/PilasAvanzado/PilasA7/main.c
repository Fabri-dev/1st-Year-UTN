#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.
int main()
{
    Pila datos, busqueda, basura;
    char op;
    int contador = 0, numero;

    inicpila(&basura);
    inicpila(&datos);
    inicpila(&busqueda);

    do{
        leer(&datos);
        printf("Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c",&op);
        contador++;
    }while(op == 's');

    printf("Que numero desea buscar en datos? \n");
    leer(&busqueda);

    for (int i=0; i < contador; i++){
        if(tope(&datos) == tope(&busqueda)){
            printf("\nNUMERO ENCONTRADO EN PILA DE DATOS \n");
            break;
        }else{
            apilar(&basura, desapilar(&datos));
        }
    }
    if (pilavacia(&datos)){
        while(!pilavacia(&basura)){
            apilar(&datos, desapilar(&basura));
        }
        printf("\nEL NUMERO BUSCADO NO EXISTE \n");
    }


    printf("---------------------SU BUSQUEDA------------------ \n");
    numero = tope(&busqueda);
    printf("%i \n", numero);
    printf("---------------------PILA DATOS------------------");
    mostrar(&datos);


    return 0;
}

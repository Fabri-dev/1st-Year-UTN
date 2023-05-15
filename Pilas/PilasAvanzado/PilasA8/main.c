#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.
int main()
{
    Pila datos, eliminar, auxD;
    char op;
    int contador,resultado;
    inicpila(&datos);
    inicpila(&eliminar);
    inicpila(&auxD);

      do{
        leer(&datos);
        printf("Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c",&op);
        contador++;
    }while(op == 's');

    printf("INGRESE EL VALOR QUE QUIERE ELIMINAR \n");
    leer(&eliminar);

    printf("-----------------------------PILA DE DATOS------------------------\n");
    mostrar(&datos);

    for(int i=0; i < contador; i++){
        if (tope(&datos) == tope(&eliminar)){
            desapilar(&datos);
        }else{
            apilar(&auxD, desapilar(&datos));
        }
    }
    if (pilavacia(&datos)){
        printf("EL VALOR NO SE ENCUENTRA EN LA PILA DE DATOS \n");
    }else{
        printf("VALOR ELIMINADO DE LA PILA DE DATOS \n\n");
    }
    while(!pilavacia(&auxD)){
        apilar(&datos, desapilar(&auxD));
    }

    printf("-----------------------------NUMERO------------------------------\n");
    resultado= tope(&eliminar);
    printf("%i \n", resultado);
    printf("-----------------------------NUEVA PILA DE DATOS------------------------\n");
    mostrar(&datos);


    return 0;
}

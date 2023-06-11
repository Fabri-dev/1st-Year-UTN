#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int verificarCuit(int cuit)
{
    int minimo=2000000, maximo= 10000000;
    if (cuit < minimo || cuit > maximo )
    {
        return 1; // si se pasa
    }
    return 0; // si existe
}

Monotributista crearUnMonotributista()
{
    Monotributista aux;
    int comprobacion=1;

    while(comprobacion == 1)
    {
        printf("Ingrese su numero de CUIT:");
        scanf("%i",&aux.cuit);
        comprobacion = verificarCuit(aux.cuit);
        if(comprobacion == 1)
        {
            printf("Ingrese un CUIT valido \n");
        }
    }

    printf("Ingrese su nombre y apellido: ");
    fflush(stdin);
    gets(aux.nya);

    return aux;
}

int cargarArregloMono(Monotributista arr[])
{
    int validos;
    char op='s';
    Monotributista aux;
    while(op=='s')
    {
        aux= crearUnMonotributista();
        arr[validos]= aux;

        validos+=1;

        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }

    return validos;
}





















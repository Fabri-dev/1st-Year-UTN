#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

///1:

int verificarCuit(int cuit)
{
    int minimo=2000000, maximo= 10000000;
    if (cuit < minimo || cuit > maximo )
    {
        printf("Ingrese un CUIT valido \n");
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

///2:

int verificarTipoFactura(char letra)
{
    if (letra == 'A' || letra =='B')
    {
        return 0;
    }
    printf("Ingrese un tipo de factura valido \n");
    return 1;
}
int verificarMontoTotal(int monto)
{
    int maximo=500000;

    if (monto <0 || monto > maximo)
    {
        printf("Ingrese un monto valido \n");
        return 1;
    }
    return 0;

}

int verificarMonotributista(Monotributista arr[],int validosMono, int cuit)
{
    for (int i=0; i < validosMono; i++)
    {
        if (arr[i].cuit == cuit)
        {
            return 0;
        }
    }
    printf("Nro de CUIT inexistente, a continuacion le crearemos uno: \n");
    return 1;

}

Factura crearFactura(Monotributista arr[],int validosMono)
{
    int comprobacion=1;
    Factura auxF;

    while(comprobacion != 0)
    {
        printf("Ingrese el tipo de factura: ");
        fflush(stdin);
        scanf("%c",&auxF.tipoFactura);
        comprobacion= verificarTipoFactura(auxF.tipoFactura);
    }
    comprobacion=1;
    while(comprobacion != 0)
    {
        printf("Ingrese su numero de CUIT: "); // para saber si es monotributista
        scanf("%i",&auxF.m.cuit);
        comprobacion= verificarMonotributista(arr,validosMono,auxF.m.cuit);
        if (comprobacion == 1)
        {
            printf("----------Creando Monotributista---------\n");
            auxF.m= crearUnMonotributista();
        }
    }
    comprobacion=1;
    while(comprobacion != 0)
    {
        printf("Ingrese el monto total: ");
        scanf("%i",&auxF.montoTotal);
        comprobacion= verificarMontoTotal(auxF.montoTotal);
    }

    return auxF;
}

int cargarArregloFacturas(Factura arrF[],Monotributista arrM[], int validosMono)
{
    char op;
    int validosFact=0;
    Factura auxF;
    do
    {
        auxF= crearFactura(arrM,validosMono);
        arrF[validosFact]= auxF;
        validosFact+=1;

        printf("Desea seguir cargando facturas? s/n: ");
        fflush(stdin);
        scanf("%c",&op);

    }while (op=='s');


    return validosFact;
}
















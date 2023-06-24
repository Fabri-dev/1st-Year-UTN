#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define DIM 20

int main()
{

    Monotributista arregloMono[DIM];
    Factura arregloFac[DIM];
    int validosMono=0, validosFact=0;

    //1:
    validosMono= cargarArregloMono(arregloMono);

    //2:
    validosFact= cargarArregloFacturas(arregloFac,arregloMono,validosMono);

    //3:


    return 0;
}










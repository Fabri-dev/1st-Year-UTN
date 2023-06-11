#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define DIM 20











int main()
{
    Disfraz arregloDisfraces[DIM];
    char archivoH[DIM]="DisfracesHombres";
    char archivoM[DIM]="DisfracesMujeres";

    menu(arregloDisfraces,archivoH,archivoM);


    return 0;
}













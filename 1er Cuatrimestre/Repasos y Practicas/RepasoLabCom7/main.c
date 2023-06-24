#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define dimFila 3
#define dimCol 3
#define MAXDIM 30
int main()
{
    int matriz[dimFila][dimCol]={{4,2,6},{3,9,8},{9,7,4}};
    Alumno arregloAlumnos[MAXDIM];
    char archivoA[15]="Aprobados";
    char archivoD[15]="Desaprobados";

    menu(matriz, arregloAlumnos,archivoA,archivoD);


    return 0;
}

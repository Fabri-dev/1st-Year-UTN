#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define FILAS 4
#define COLUMNAS 4
#define MAXDIM 20

int main()
{

    char archivoPacientes[]="Pacientes";
    float matriz[FILAS][COLUMNAS];
    float arregloPromedio[MAXDIM];

    menu(archivoPacientes,matriz,arregloPromedio);

    return 0;
}








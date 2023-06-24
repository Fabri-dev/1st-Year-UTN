#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAXDIM 30


int main()
{
    stDireccion arregloDireccion[MAXDIM];
    stPelicula arrPelicula[MAXDIM];
    char archivoPeliculas[]= "Peliculas";
    char archivoDirectoresBuenos[]= "DirectoresBuenos";
    char archivoDirectoresMalos[]="DirectoresMalos";
    menu(arregloDireccion,arrPelicula,archivoDirectoresMalos,archivoDirectoresBuenos,archivoPeliculas);

    return 0;
}

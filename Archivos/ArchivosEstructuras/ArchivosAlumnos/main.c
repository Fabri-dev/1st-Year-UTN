#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "prototipados.h"

const int MAX_DIM=20;

int main()
{
    char archivoAlumnos[]= "Alumnos";
    char archivoConArreglo[]= "AlumnosConArreglo";
    Pila pilaLegajos;
    inicpila(&pilaLegajos);

    stAlumno arregloAlumnos[MAX_DIM], arrAnio[MAX_DIM];

    int cant=0,datoBuscar=0,opsw=0, validos=0;
    char op='s';



    do
    {

        printf("ARCHIVOS PRIMITIVOS: \n");
        printf("1. Agregar un elemento al final de un archivo.\n");
        printf("2. Mostrar por pantalla el contenido de un archivo.\n");
        printf("3. Retornar la cantidad de registros que contiene un archivo.\n");
        printf("ARCHIVOS CON ESTRUCTURAS: \n");
        printf("4. Cargar un archivo \n");
        printf("5. Mostrar un archivo \n");
        printf("6. ??? \n");
        printf("7. Pila de  legajos de mayores de edad \n");
        printf("8. Contar cantidad de alumnos de determinada edad (pasa por parametro)\n");
        printf("9. Mostrar rango de edades desde un punto hasta otro (se pasan por parametro)\n");
        printf("10. Mostrar el alumno de mayor edad\n");
        printf("11. Contar cantidad de alumnos que cursan un determinado anio (se pasa por parametro)\n");
        printf("12. Arreglo to Archivo y despues Archivo to Arreglo con condicion \n");
        printf("13. Retornar cantidad de registros que tiene el archivo \n");
        printf("14.  \n");
        printf("15.  \n");
        printf("16.  \n");


        printf("Ingrese el inciso que quiere: ");
        scanf("%i",&opsw);




        switch(opsw)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            cargarArchivoAlumnos(archivoAlumnos);
            break;
        case 5:
            mostrarArchivo(archivoAlumnos);
            break;
        case 6:
            cargarArchivoAlumnos(archivoAlumnos);
            break;
        case 7:
            pasarAPilaLegajos(archivoAlumnos, &pilaLegajos);
            mostrar(&pilaLegajos);
            break;
        case 8:
            datoBuscar= preguntarDato();
            cant= contarAlumnosXDato(archivoAlumnos, datoBuscar);
            mostrarArchivo(archivoAlumnos);
            printf("La cantidad de alumnos mayores a %i es: %i \n", datoBuscar, cant);

            break;
        case 9:
            mostrarRangoEdad(archivoAlumnos,preguntarDato(),preguntarDato());
            break;
        case 10:
            mostrarMayorEdad(archivoAlumnos);
            break;
        case 11:
            datoBuscar= preguntarDato();
            cant= cantAlumnosXanio(archivoAlumnos,datoBuscar);
            mostrarArchivo(archivoAlumnos);
            printf("La cantidad de alumnos del anio %i es: %i \n",datoBuscar,cant);
            break;
        case 12:
            validos= cargarArregloAlumno(arregloAlumnos);
            arregloToArchivo(archivoConArreglo,arregloAlumnos,validos);
            archivoToArregloConCondicion(archivoConArreglo,arrAnio,preguntarDato(),validos);
            mostrarArregloAlumnos(arrAnio, validos);
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        case 16:
            break;
        default:
            break;
        }

        printf("Desea elegir otro insciso? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        } while(op=='s');

    return 0;
}










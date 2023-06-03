#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "prototipados.h"

const int MAX_DIM=20;

int main()
{
    //Archivos:
    char archivoAlumnos[]= "Alumnos";
    char archivoConArreglo[]= "AlumnosConArreglo";
    char archivoPrimitivo[]="ArchivoPrimitivo";

    //variables:
    stAlumno arregloAlumnos[MAX_DIM], arrAnio[MAX_DIM], alumnoMayor;
    int cant=0,datoBuscar=0,opsw=0, validos=0;
    char op='s';

    Pila pilaLegajos;
    inicpila(&pilaLegajos);




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
        printf("8. Contar cantidad de alumnos mayores a determinada edad (pasa por parametro)\n");
        printf("9. Mostrar rango de edades desde un punto hasta otro (se pasan por parametro)\n");
        printf("10. Mostrar el alumno de mayor edad\n");
        printf("11. Contar cantidad de alumnos que cursan un determinado anio (se pasa por parametro)\n");
        printf("12. Arreglo to Archivo y despues Archivo to Arreglo con condicion \n");
        printf("13. Retornar cantidad de registros que tiene el archivo \n");
        printf("14. Elegir un alumno entre el 1 al 9 \n");
        printf("15. Modificar un alumno existente \n");
        printf("16. Invertir los elementos del archivo \n");


        printf("Ingrese el inciso que quiere: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            cargarArchivoPrim(archivoPrimitivo);
            break;
        case 2:
            mostrarArchivoPrim(archivoPrimitivo);
            break;
        case 3:
            cant= contarRegistrosPrim(archivoPrimitivo);
            printf("La cantidad de registros que hay en el archivo es: %i", cant-1);
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
            printf("Ingrese la edad: \n");
            datoBuscar= preguntarDato();
            cant= contarAlumnosXDato(archivoAlumnos, datoBuscar);
            mostrarArchivo(archivoAlumnos);
            printf("La cantidad de alumnos mayores a %i es: %i \n", datoBuscar, cant);

            break;
        case 9:
            printf("1er dato DESDE que edad quiere mostrar, 2do dato HASTA que edad quiere mostrar: \n");
            mostrarRangoEdad(archivoAlumnos,preguntarDato(),preguntarDato());
            break;
        case 10:
            alumnoMayor= mostrarMayorEdad(archivoAlumnos);
            printf("ALUMNO MAYOR: \n");
            mostrarAlumno(alumnoMayor);
            break;
        case 11:
            printf("Ingrese el anio que quiere contar la cantidad de alumnos: \n");
            datoBuscar= preguntarDato();
            cant= cantAlumnosXanio(archivoAlumnos,datoBuscar);
            mostrarArchivo(archivoAlumnos);
            printf("La cantidad de alumnos del anio %i es: %i \n",datoBuscar,cant);
            break;
        case 12:
            printf("CARGANDO ARREGLO: \n");
            validos= cargarArregloAlumno(arregloAlumnos);
            printf("PASANDO ELEMENTOS DEL ARREGLO AL ARCHIVO \n");
            arregloToArchivo(archivoConArreglo,arregloAlumnos,validos);
            printf("Ingrese el anio de estudiantes que quiere guardar y mostrar en el arreglo: \n");
            archivoToArregloConCondicion(archivoConArreglo,arrAnio,preguntarDato(),validos);
            printf("ARREGLO NUEVO: \n");
            mostrarArregloAlumnos(arrAnio, validos);
            break;
        case 13:
            cant= contarCantidadDeRegistros(archivoAlumnos);
            printf("La cantidad de registros que hay es: %i \n",cant);
            break;
        case 14:
            mostrarPorDato(archivoAlumnos);
            break;
        case 15:
            system("cls");
            mostrarArchivo(archivoAlumnos);
            modificarArchivo(archivoAlumnos,preguntarDato()-1);
            break;
        case 16:
            printf("ARCHIVO NO INVERTIDO: \n\n");
            mostrarArchivo(archivoAlumnos);
            invertirElementosArchivo(archivoAlumnos);
            printf("ARCHIVO INVERTIDO: \n\n");
            mostrarArchivo(archivoAlumnos);
            break;
        default:
            break;
        }

        printf("Desea elegir otro insciso? s/n: ");
        fflush(stdin);
        scanf("%c",&op);

        system("cls");

        } while(op=='s');




    return 0;
}










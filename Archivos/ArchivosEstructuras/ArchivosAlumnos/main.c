#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct {
     char nombreYapellido [30];
     int legajo;
     int edad;
     int anio;

} stAlumno;

////  PROTOTIPADOS  \\\\\

stAlumno cargarAlumno();
void cargarArchivoAlumnos(char archivo[]);
void mostrarAlumno(stAlumno alumno);
void mostrarArchivo(char archivo[]);
void pasarAPilaLegajos(char archivo[], Pila* pilaLegajos);
int preguntarDato();
int contarAlumnosXDato(char archivo[], int dato);




int main()
{
    char archivoAlumnos[]= "Alumnos";
    Pila pilaLegajos;
    inicpila(&pilaLegajos);

    int cant,datoBuscar;



    //4:

    //cargarArchivoAlumnos(archivoAlumnos);


    //5:

    //mostrarArchivo(archivoAlumnos);

    //7:

    //pasarAPilaLegajos(archivoAlumnos, &pilaLegajos);
    //mostrar(&pilaLegajos);

    //8:
    //datoBuscar= preguntarDato();
    //cant= contarAlumnosXDato(archivoAlumnos, datoBuscar);
    //printf("La cantidad de alumnos mayores a %i es: %i", datoBuscar, cant);


    return 0;
}


stAlumno cargarAlumno()
{
    stAlumno aux;


        printf("\nIngrese el nombre y apellido del alumno: ");
        fflush(stdin);
        gets(&aux.nombreYapellido);
        printf("Ingrese la edad del alumno: ");
        scanf("%i",&aux.edad);
        printf("Ingrese el anio en el que se encuentra: ");
        scanf("%i",&aux.anio);
        printf("Ingrese el nro. de legajo: ");
        scanf("%i",&aux.legajo);
        printf("\n");

    return aux;
}

void cargarArchivoAlumnos(char archivo[])
{
    char op='s';
    stAlumno alumno;

    FILE * archi;
    archi = fopen(archivo,"ab");

    if (archi != NULL)
    {
        while(op=='s')
        {
            alumno= cargarAlumno();
            printf("Desea seguir cargando? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
            fwrite(&alumno,sizeof(stAlumno),1,archi);
        }

    fclose(archi);
    }


}

void mostrarAlumno(stAlumno alumno)
{
    puts("------------------------------------------------------------");
    printf("El nombre y apellido del alumno es: %s \n", alumno.nombreYapellido);
    printf("La edad es: %i \n", alumno.edad);
    printf("El anio en el que se encuentra es: %i \n", alumno.anio);
    printf("El legajo es: %i \n",alumno.legajo);
    puts("------------------------------------------------------------");

}

void mostrarArchivo(char archivo[])
{
    FILE * archi;

    stAlumno alumno;

    archi= fopen(archivo,"rb");

    if (archi!= NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                mostrarAlumno(alumno);
            }
        }
    fclose(archi);
    }
}

void pasarAPilaLegajos(char archivo[], Pila* pilaLegajos)
{
    FILE * archi;

    archi= fopen(archivo,"rb");

    stAlumno alumno;



    if (archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno,sizeof(stAlumno),1,archi);

            if(!feof(archi))
            {
                apilar(pilaLegajos, alumno.legajo);
            }
        }
        fclose(archi);
    }
    else
    {
        printf("Error: archivo corrompido");
    }

}

int preguntarDato()
{
    int dato;
    printf("Ingrese los mayores a que edad quiere buscar: ");
    scanf("%i", &dato);

    return dato;
}

int contarAlumnosXDato(char archivo[], int dato)
{
    FILE* archi;

    archi= fopen(archivo,"rb");

    stAlumno alumno;
    int i=0;

    if (archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(alumno.edad>dato)
                {
                    i++;

                }
            }
        }
        fclose(archi);
    }
    else
    {
        printf("archivo corrompido");
    }

    return i;
}








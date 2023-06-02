#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "prototipados.h"



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


    if(archi=fopen(archivo, "ab") != NULL)
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
    else
    {
        archi = fopen(archivo,"wb");
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
                if (alumno.edad >= 18)
                {
                apilar(pilaLegajos, alumno.legajo);
                }
            }
        }
        fclose(archi);
    }
    else
    {
        printf("Error: archivo corrupto");
    }

}

int preguntarDato()
{
    int dato;
    printf("Ingrese el dato: ");
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

void mostrarRangoEdad(char archivo[], int desde, int hasta)
{
    FILE * archi;

    archi= fopen(archivo,"rb");

    stAlumno alumno;

    if (archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno, sizeof(stAlumno),1, archi);
            if(!feof(archi))
            {
                if (alumno.edad >= hasta && alumno.edad <= desde)
                {
                    mostrarAlumno(alumno);
                }
            }
        }
        fclose(archi);
    }

}

void mostrarMayorEdad(char archivo[])
{
    FILE * archi;

    stAlumno alumno, alumnoMayor;

    archi= fopen(archivo, "rb");

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(alumnoMayor.edad < alumno.edad)
                {
                    alumnoMayor= alumno;
                }
            }
        }

            fclose(archi);
    }
        mostrarAlumno(alumnoMayor);
}

int cantAlumnosXanio(char archivo[], int dato)
{
    FILE* archi;

    archi=fopen(archivo,"rb");

    stAlumno alumno;

    int i=0;

    if(archi != NULL)
    {
        while(fread(&alumno,sizeof(alumno),1,archi)>0)
        {
            if(dato == alumno.anio)
            {
                i++;
            }
        }
        fclose(archi);
    }
    return i;
}

int cargarArregloAlumno(stAlumno arr[])
{
    char op='s';
    int i=0;

    while(op=='s')
    {
        arr[i]= cargarAlumno();
        i++;
        printf("Desea agregar mas alumnos? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    return i;
}

void arregloToArchivo(char archivo[], stAlumno arr[], int validos)
{
    FILE * archi;

    archi= fopen(archivo, "wb");

    if(archi != NULL)
    {
        for (int i=0; i < validos; i++)
        {
            fwrite(&arr[i],sizeof(stAlumno),1,archi);
        }
        fclose(archi);
    }
}

void archivoToArregloConCondicion(char archivo[], stAlumno arrAnio[], int dato ,int validos)
{
    FILE * archi;

    archi= fopen(archivo, "rb");

    stAlumno alumno;

    int i=0;

    if(archi != NULL)
    {
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0)
        {
            if (alumno.anio == dato)
            {
                arrAnio[i]=alumno;
                i++;
            }
        }
        fclose(archi);
    }


}

void mostrarArregloAlumnos(stAlumno arr[], int validos)
{
    for (int i=0;i<validos; i++)
    {
        mostrarAlumno(arr[i]);
    }
}

int contarCantidadDeRegistros(char archivo[])
{
    FILE* archi;

    if((archi=fopen(archivo,"rb"))!= NULL)
        {

        }



}



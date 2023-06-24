#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define dimFila 3
#define dimCol 3
#define MAXDIM 30

void menu(int mat[][dimCol],Alumno arregloAlumnos[],char archivoA[], char archivoD[])
{
    int opsw;
    char op='s';

    int dato=0, validos=0;

    while(op=='s')
    {
        puts("\t \nEjercicios: \n\n");

        puts("Ejercicio 1 \n");
        puts("Ejercicio 2 \n");
        puts("Ejercicio 3 \n");
        puts("Ejercicio 4 \n");
        puts("Ejercicio 5 \n");
        puts("Ejercicio 6 \n");
        puts("Ejercicio 7 \n");


        printf("Elija una opcion: ");
        scanf("%i",&opsw);


        switch(opsw)
        {
        case 1:
            printf("Ingrese el numero que quiere buscar en la matriz: \n");
            dato = preguntarDato();
            buscarNumeroEnMatriz(mat,dato) ? printf("El numero que busco existe :)") : printf("Numero buscado no existe :(");
            break;
        case 2:
            validos=cargarAlumnosToArreglo(arregloAlumnos);
            printf("\nUsted cargo esta cantida de alumnos: %i",validos);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Elija un numero correcto \n");
            break;

        }
            printf("\nQuiere seguir elegiendo ejercicios? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
            system("cls");
    }
}

//1:

int preguntarDato()
{
    int dato;
    printf("Ingrese un dato: ");
    scanf("%i",&dato);
    return dato;
}


int buscarNumeroEnMatriz(int mat[][3], int dato)
{
    for (int i=0; i< dimFila; i++)
    {
        for(int j=0; j<dimCol; j++)
        {
            if (dato == mat[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}


//2:

int verificarNota()
{
    int nota;
    int comprobacion=0;

    while(comprobacion==0)
    {
        printf("Ingrese la nota del alumno: ");
        scanf("%i",&nota);
        if(nota < 0 || nota > 10)
        {
            printf("Ingrese un nota valida \n");
            comprobacion= -1;
        }
        else
        {
            return nota;
        }

    }
return 0;
}


Alumno crearAlumno()
{
    Alumno aux;

    printf("Ingrese el nombre de la materia: ");
    fflush(stdin);
    gets(&aux.nombreMateria);
    printf("Ingrese el legajo del alumno: ");
    scanf("%i",&aux.legajo);
    printf("Ingrese el anio del alumno: ");
    scanf("%i",&aux.anio);

    aux.nota= verificarNota();



    return aux;
}

int cargarAlumnosToArreglo(Alumno arr[])
{
    int i=0;
    char op='s';
    Alumno aux;
    while(op=='s')
    {
        arr[i]= crearAlumno();
        i++;

        printf("\nQuiere seguir cargando el arreglo? s/n: ");
        fflush(stdin);
        scanf("%c",&op);

    }

    return i;
}

//3:

void arregloToArchivo(Alumno arrAlumnos[],int validos,char archivoA[], char archivoD[])
{
    FILE * archiA= fopen(archivoA,"ab");
    FILE * archiD= fopen(archivoD,"ab");


    if(archiA == NULL || archiD == NULL)
    {
        printf("Hubo un problema con los archivos");

    }
    else
    {
        for (int i=0; i <validos; i++)
        {
            if (arrAlumnos[i].nota < 6)
            {
                fwrite(&arrAlumnos[i],sizeof(Alumno),1,archiD);
            }
            else if(arrAlumnos[i].nota >= 6)
            {
                fwrite(&arrAlumnos[i],sizeof(Alumno),1,archiA);
            }
        }
        fclose(archiA);
        fclose(archiD);
    }

}

//4:

int contarRegistros(char archivo[])
{
    FILE * archi= fopen(archivo,"rb");

    int cantidad=0;

    if(archi==NULL)
    {
        printf("Error con archivo");
    }
    else
    {
        fseek(archi,sizeof(Alumno)-1,SEEK_END);
        cantidad= ftell(archi)/sizeof(Alumno);
        fclose(archi);
    }
    return cantidad;
}


//5:

void mostrarAlumno(Alumno aux)
{
    puts("\n--------------Alumno--------------");
    printf("El legajo es: %i \n",aux.legajo);
    printf("La materia es: %s \n",aux.nombreMateria);
    printf("El anio es: %i \n",aux.anio);
    printf("La nota es: %i \n",aux.nota);
    puts("-------------------------------------\n");

}

void mostrarAlumnosXMateria(char archivo[], char materia[])
{
    FILE * archi=fopen(archivo,"rb");
    Alumno aux;

    if(archi==NULL)
    {
        printf("Error con archivo");
    }
    else
    {
        while((fread(&aux,sizeof(Alumno),1,archi)>0))
        {
            if ((strcmp(aux.nombreMateria,materia)==0))
            {
                mostrarAlumno(aux);
            }

        }


        fclose(archi);
    }



}

//6:

//NO LO ENTIENDO


//7:

int verificarRegistro(int cantRegistros)
{
    int dato=0,comprobacion=0;
    while(comprobacion==0)
    {
        printf("Ingrese una posicion de un alumno: ");
        scanf("%i",&dato);
        if (dato > cantRegistros || dato < 0)
        {
            printf("Ingrese un registro valido");
            comprobacion = -1;
        }

    }

}

void mostrarAlumnoXRegistro(char archivo[])
{
    FILE * archi=fopen(archivo,"rb");
    Alumno aux;
    int cantRegistros=contarRegistros(archivo);
    int dato=verificarRegistro(cantRegistros);


    if (archi==NULL)
    {
        printf("Error con archivo");

    }
    else
    {
        fseek(archi,sizeof(Alumno)*dato,SEEK_SET);
        fread(&aux,sizeof(Alumno),1,archi);
        printf("EL ALUMNO BUSCADO ES: \n");
        mostrarAlumno(aux);
    }

}


void elegirArchivos(char archivoA[],char archivoD[])
{
    int op;

    printf("1. Archivo de Aprobados \n");
    printf("2. Archivo de Desaprobados \n");
    printf("De que archivo quiere buscar el alumno?: ");
    scanf("%i",&op);
    switch(op)
    {
    case 1:
        mostrarAlumnoXRegistro(archivoA);
        break;
    case 2:
        mostrarAlumnoXRegistro(archivoD);
        break;
    default:
        printf("Ingrese un archivo valido");
        break;
    }


}


























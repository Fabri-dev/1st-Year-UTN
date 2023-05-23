#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int DIM=30;

typedef struct
{
    int matricula;
    char nombre[30];
    char genero;
} stAlumno;

//// prototipados: \\\\

int cargarAlumnos(stAlumno arr[]);
void mostrarAlumnos(stAlumno arr[], int validos);
void mostrarNombreAlumno(stAlumno arr[], int pos);
void mostrarGeneroAlumno(stAlumno arr[], int pos);
void mostrarMatriculaAlumno(stAlumno arr[], int pos);
int buscarMatricula(stAlumno arr[], int validos,int nroMatricula);
void mostrarAlumnoPorMatricula(stAlumno arr[], int validos);
int buscarPosMenor(stAlumno arr[],int pos, int validos);
void ordenarxSeleccionxMatricula(stAlumno arr[], int validos);





int main()
{
    stAlumno Alumnos[DIM];

    int validos= cargarAlumnos(Alumnos);

    mostrarAlumnos(Alumnos, validos);

    ordenarxSeleccionxMatricula(Alumnos,validos);

    mostrarAlumnos(Alumnos,validos);

    return 0;
}
//1.
int cargarAlumnos(stAlumno arr[])
{
    int validos=0, i=0;
    char op='s';

    while(op =='s' && i< DIM)
    {
       printf("Ingrese el nombre del alumno: ");
       scanf("%s", &arr[i].nombre);

       printf("Ingrese el genero del alumno: ");
       fflush(stdin);
       scanf("%c", &arr[i].genero);

       printf("Ingrese el nro de matricula del alumno: ");
       scanf("%i", &arr[i].matricula);

       i++;

       printf("Desea continuar? s/n: ");
       fflush(stdin);
       scanf("%c", &op);

    }


    return i;
}

//2.
void mostrarNombreAlumno(stAlumno arr[], int pos)
{

        printf("Nombre de alumno: %s \n", arr[pos].nombre);


}

void mostrarGeneroAlumno(stAlumno arr[], int pos)
{

        printf("Genero de alumno: %c \n", arr[pos].genero);

}

void mostrarMatriculaAlumno(stAlumno arr[], int pos)
{


        printf("Matricula de alumno: %i \n", arr[pos].matricula);

}

void mostrarAlumnos(stAlumno arr[], int validos)
{
    for (int i=0; i< validos; i++)
    {
        printf("\n");
        mostrarNombreAlumno(arr,i);
        mostrarGeneroAlumno(arr,i);
        mostrarMatriculaAlumno(arr,i);
        printf("\n");
    }

}

//3.
int buscarMatricula(stAlumno arr[], int validos,int nroMatricula)
{
    for (int i=0; i<validos; i++)
    {
        if(nroMatricula== arr[i].matricula)
        {
            return i; // Retorno la posicion si el dato buscado es encontrado en el arreglo
        }
    }
    return -1; // Falso si el dato no se encuentra
}

void mostrarAlumnoPorMatricula(stAlumno arr[], int validos)
{
    int nroMatricula=0, posicion=0;

    printf("Ingrese el numero de matricula que busca: ");
    scanf("%i", &nroMatricula);
    posicion=buscarMatricula(arr, validos, nroMatricula);

    if(posicion!= -1)
    {
        printf("Alumno encontrado :)\n");
        mostrarNombreAlumno(arr, posicion);
        mostrarGeneroAlumno(arr, posicion);
        mostrarMatriculaAlumno(arr, posicion);
    }
    else
    {
        printf("Error: alumno no encontrado \n");
    }


}

//4.

int buscarPosMenor(stAlumno arr[],int pos, int validos)
{
    int posMenor=0;

    for (int i=pos; i<validos; i++)
    {
        if (arr[i].matricula < arr[posMenor].matricula)
        {
            posMenor=i;
        }
    }

    return posMenor;
}

void ordenarxSeleccionxMatricula(stAlumno arr[], int validos)
{
    int posMenor=0;
    stAlumno aux;


    for(int i=0; i< validos;i++)
    {
        posMenor=buscarPosMenor(arr,i,validos); // busco la posicion menor

        // ahora cambio de lugar la posicion donde esta el menor con la primera posicion

        aux= arr[i];

        arr[i]= arr[posMenor];

        arr[posMenor]= aux;

    }

}



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

stAlumno cargarAlumno();
int cargarAlumnos(stAlumno arr[]);
void mostrarAlumno(stAlumno estudiante);
void mostrarAlumnos(stAlumno arr[], int validos);
int preguntarMatricula();



int buscarMatricula(stAlumno arr[], int validos,int nroMatricula);
void mostrarAlumnoPorMatricula(stAlumno arr[], int validos);
int buscarPosMenor(stAlumno arr[],int pos, int validos);
void ordenarxSeleccionxMatricula(stAlumno arr[], int validos);
int buscarMatricula(stAlumno arr[], int validos,int nroMatricula);
void mostrarAlumnoPorMatricula(stAlumno arr[], int validos);





int main()
{
    stAlumno Alumnos[DIM];

    int validos= cargarAlumnos(Alumnos);

    return 0;
}
//1.

stAlumno cargarAlumno()
{
    stAlumno estudiante;
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", &estudiante.nombre);
    printf("Ingrese el genero del alumno: ");
    fflush(stdin);
    scanf("%c", &estudiante.genero);
    printf("Ingrese la matricula del alumno: ");
    scanf("%i", &estudiante.matricula);


    return estudiante;
}


int cargarAlumnos(stAlumno arr[])
{
   char op='s';
   int i=0;

   while(i < DIM && op =='s')
   {
       arr[i]= cargarAlumno();
       i++;
       printf("Desea continuar? s/n: ");
       fflush(stdin);
       scanf("%c", &op);

   }

    return i;
}

//2.

void mostrarAlumno(stAlumno estudiante)
{
    printf("El nombre del alumno es: %s \n", estudiante.nombre);
    printf("El genero del alumno es: %c \n", estudiante.genero);
    printf("La matricula del alumno es: %i \n", estudiante.matricula);
}

void mostrarAlumnos(stAlumno arr[], int validos)
{
    for (int i=0; i < validos; i++)
    {
        mostrarAlumno(arr[i]);
    }
}


//3.

int preguntarMatricula()
{
    int nroMatricula=0;
    printf("Ingrese el numero de matricula que busca: ");
    scanf("%i", &nroMatricula);
    return nroMatricula;
}



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
    int flag=0;

    char op='s';

    while(op=='s')
    {
        flag= buscarMatricula(arr,validos, preguntarMatricula());

        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);
    }

    if(flag != -1)
    {
        printf("Alumno encontrado :)\n");
        mostrarAlumno(arr[flag]);
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



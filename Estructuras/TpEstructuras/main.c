#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constantes:

const int DIM=30;

////  estructura:  \\\\

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
char preguntarGenero();
int retornarArregloGenero(stAlumno arr[], int validos, char dato, stAlumno arregloGenero[]);
void MostrarxGenero(stAlumno arr[], int validos);
void insertarxMatricula(stAlumno arr[], int validos, stAlumno dato);
void insertarxNombre(stAlumno arr[], int validos, stAlumno dato);
void ordenarxInsercionxMatricula(stAlumno arr[], int validos);
int cantEstudiantesxGenero(stAlumno arr[], int validos, char generoBuscado);




int main()
{
    stAlumno Alumnos[DIM];

    int validos=0, numGen=0;
    char datoGen;

    char op='s';
    int opsw=0;

    while(op=='s')
    {
        printf("Elija un insciso: \n\n");

        printf("1. Cargar un arreglo de alumnos hasta que el usuario decida. \n");
        printf("2. Mostrar arreglo de alumnos. Modularizar. \n");
        printf("3. Mostrar los datos de un alumno segun matricula. Modularizar. \n");
        printf("4. Ordenar por seleccion arreglo de alumno segun el numero de matricula. \n");
        printf("5. Mostrar alumnos de un genero determinado(se envia por parametro). Modularizar. \n");
        printf("6. Insertar un nuevo dato en arreglo de alumnos segun su matricula, conservando el orden. \n");
        printf("7. Ordenar por insercion arreglo de alumnos segun el nombre. \n");
        printf("8. Contar cantidad de estudiantes de un genero determinado(se envia por parametro). \n\n");

        printf("Opcion: ");
        scanf("%i", &opsw);

        switch(opsw)
        {
        case 1:
            validos= cargarAlumnos(Alumnos);
            break;
        case 2:
            mostrarAlumnos(Alumnos,validos);
            break;
        case 3:
            mostrarAlumnoPorMatricula(Alumnos,validos);
            break;
        case 4:
            ordenarxSeleccionxMatricula(Alumnos,validos);
            printf("Alumnos Ordenados por matricula: \n");
            mostrarAlumnos(Alumnos,validos);
            break;
        case 5:
            MostrarxGenero(Alumnos,validos);
            break;
        case 6:
            insertarxMatricula(Alumnos,validos,cargarAlumno());
            printf("Arreglo de alumnos con dato insertado: \n");
            mostrarAlumnos(Alumnos,validos+1);
            break;
        case 7:
            ordenarxInsercionxMatricula(Alumnos,validos);
            printf("Arreglo de alumnos ordenados por insercion segun matricula \n");
            mostrarAlumnos(Alumnos,validos);
            break;
        case 8:
            datoGen= preguntarGenero();
            numGen=cantEstudiantesxGenero(Alumnos,validos,datoGen);
            printf("El numero de estudiantes del genero |%c| es: %i \n",datoGen, numGen);
            break;
        default:
            printf("Error: Elija un numero correcto");
            break;

        }
        printf("\nQuiere elegir otros inscisos? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }


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
    printf("La matricula del alumno es: %i \n\n", estudiante.matricula);
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

    flag= buscarMatricula(arr,validos, preguntarMatricula());

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
        posMenor=buscarPosMenor(arr,i,validos-1); // busco la posicion menor

        // ahora cambio de lugar la posicion donde esta el menor con la primera posicion

        aux= arr[i];

        arr[i]= arr[posMenor];

        arr[posMenor]= aux;

    }

}


//5.

char preguntarGenero()
{
    char gen;
    printf("Ingrese el genero de alumnos que desea buscar: ");
    fflush(stdin);
    scanf("%c", &gen);
    return gen;

}



void MostrarxGenero(stAlumno arr[], int validos)
{
    stAlumno arregloGenero[DIM];

    char dato= preguntarGenero();

    int validosGenero= retornarArregloGenero(arr,validos,dato,arregloGenero);

    printf("La informacion de los alumnos del genero |%c| son: \n\n", dato);

    mostrarAlumnos(arregloGenero,validosGenero);



}

int retornarArregloGenero(stAlumno arr[], int validos, char dato, stAlumno arregloGenero[])
{
    int j=0;
    for(int i=0; i<validos; i++)
    {
        if (arr[i].genero==dato)
        {
            arregloGenero[j]= arr[i];
            j++;
        }
    }
    return j;
}

//6.

void insertarxMatricula(stAlumno arr[], int validos, stAlumno dato)
{
    int i= validos -1;

    while(i>=0 && arr[i].matricula>dato.matricula) //este es el criterio, en este caso el criterio es segun la matricula
    {
        arr[i+1]=arr[i];
        // mientras que la condicion sea V copio el TODOS los datos del alumno en la siguiente posicion del arreglo
        i--;
        // y ahora disminuyo en uno la posicion del contador
    }
    arr[i+1]= dato; // si la condicion es falsa copio el dato en la siguiente posicion ya que mi i esta una posicion anterior


}


//7.

void insertarxNombre(stAlumno arr[], int validos, stAlumno dato)
{
    int i= validos -1;

    while(i>=0 && (strcmp(arr[i].nombre,dato.nombre)==0)) //este es el criterio, en este caso el criterio es segun el nombre
    {
        arr[i+1]=arr[i];
        // mientras que la condicion sea V copio el TODOS los datos del alumno en la siguiente posicion del arreglo
        i--;
        // y ahora disminuyo en uno la posicion del contador
    }
    arr[i+1]= dato; // si la condicion es falsa copio el dato en la siguiente posicion ya que mi i esta una posicion anterior


}


void ordenarxInsercionxMatricula(stAlumno arr[], int validos)
{
    for (int i=0; i < validos; i++)
    {
        insertarxNombre(arr,i,arr[i]);
    }
}

//8.

int cantEstudiantesxGenero(stAlumno arr[], int validos, char generoBuscado)
{
    int contGenero=0;

    for(int i=0; i <validos; i++)
        if (generoBuscado==arr[i].genero)
            contGenero++;

    return contGenero;
}















#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// 1.Crear una función que los cargue, hasta que el usuario lo decida.

/// 2.Crear una función que busque dentro del arreglo de legajos y retorne la posición de un determinado valor.

/// 3.Hacer una función que reciba como parámetro todos los arreglos y encuentre el nombre correspondiente a un determinado legajo y lo imprima por pantalla. Se debe invocar la función 2.


const int MAX_DIM= 20;
const int MAX_LETRAS= 30;

void cargarParalelosYDevolverValidos(int legajos[], char nombres[][MAX_LETRAS],int anios[], int* validos);
void mostrarArregloParalelo(char nombres[][MAX_LETRAS],int legajos[],int edad[], int validos);
int devolverPosicionLegajo(int arr[], int validos, int busqueda);
int preguntarPosicionLegajo();
void condicionLegajo(int legajos[],int inidiceLegajo);
void buscarNombrexLegajo(char nombres[][MAX_LETRAS], int legajos[], int validos);
int encontrarPosicionNombre(char nombres[][MAX_LETRAS], int validos, int posInicial);
void ordenamientoXSeleccion(int edades[], int legajos[], char nombres[][MAX_LETRAS], int validos);
void insercion(char nombres[][MAX_LETRAS], int legajos[], int edades[], int posicion, char dato[], int datoLegajos, int datoEdades);
void ordenamientoxInsercion(char nombres[][MAX_LETRAS], int legajos[], int edades[], int validos);




int main()
{
    int legajos[MAX_DIM];
    char nombres[MAX_DIM][MAX_LETRAS];
    int anios[MAX_DIM];
    int validos= 0;

    cargarParalelosYDevolverValidos(legajos,nombres,anios, &validos);

    mostrarArregloParalelo(nombres,legajos,anios,validos);

    printf("validos: %i \n", validos);

    ordenamientoxInsercion(nombres,legajos,anios,validos);

    printf("ORDENADO");

    mostrarArregloParalelo(nombres,legajos,anios,validos);


    return 0;
}


void cargarParalelosYDevolverValidos(int legajos[], char nombres[][MAX_LETRAS],int anios[], int* validos)
{
    int i=0;
    char op='s';
    while(op=='s' && i < MAX_DIM)
    {
        printf("Ingrese el nombre del alumno: ");
        fflush(stdin);
        scanf("%s", &nombres[i]);
        printf("Ingrese la edad del alumno: ");
        scanf("%i", &anios[i]);
        printf("Ingrese el legajo del alumno: ");
        scanf("%i", &legajos[i]);
        i++;

        printf("Desea ingresar los datos de otro alumno? s/n: ");
        fflush(stdin);
        scanf("%c", &op);
    }

    *validos=i;

}
void mostrarArregloParalelo(char nombres[][MAX_LETRAS],int legajos[],int edad[], int validos)
{

    for (int i=0; i<validos; i++)
    {

        printf("-----------------------------------------------------\n");
        printf("Alumno nro: %i\n", i+1);
        printf("-----------------------------------------------------\n");
        printf("El nombre del alumno es: %s\n", nombres[i]);
        printf("La edad del alumno es: %i\n", edad[i]);
        printf("El legajo del alumno es: %i\n", legajos[i]);
        printf("-----------------------------------------------------\n");
    }
}
int devolverPosicionLegajo(int arr[], int validos, int busqueda)
{
    for (int i=0; i < validos; i++)
        if (arr[i] == busqueda)
            return i;
    return -1;
}
int preguntarPosicionLegajo()
{
    int legajo = 0;
    printf("Ingrese el legajo que busca: ");
    scanf("%i",&legajo);
    return legajo;
}
void condicionLegajo(int legajos[],int inidiceLegajo)
{
    if (inidiceLegajo != -1)
    {
        printf("Legajo %i buscado fue encontrado en la posicion: %i", legajos[inidiceLegajo], inidiceLegajo );
    }
    else
    {
        printf("Legajo buscado NO encontrado");
    }
}
void buscarNombrexLegajo(char nombres[][MAX_LETRAS], int legajos[], int validos)
{
    int busqueda=0, num=0;

    busqueda=preguntarPosicionLegajo();

    num= devolverPosicionLegajo(legajos,validos,busqueda);

    if (num != -1)
    {
        printf("El legajo nro: %i es de: %s", busqueda, nombres[num]);
    }
    else
    {
        printf("ERROR: El legajo %i no se encontro", busqueda);
    }

}
int encontrarPosicionNombre(char nombres[][MAX_LETRAS], int validos, int posInicial)
{
    int i = posInicial;
    int posMenor= posInicial;

    for (i; i<validos;i++)
    {
        if (strcmp(nombres[i], nombres[posMenor])< 0)
        {
            posMenor= i;
        }
    }

    return posMenor;
}
void ordenamientoXSeleccion(int edades[], int legajos[], char nombres[][MAX_LETRAS], int validos)
{
    int i=0, posMenor=0, aux= 0;
    char auxNombre[MAX_LETRAS];

    for (i; i<validos; i++)
    {
        posMenor= encontrarPosicionNombre(nombres,validos,i);

        // intercambio edades:
        aux = edades[i];
        edades[i]= edades[posMenor];
        edades[posMenor]=aux;

        // intercambio legajos:
        aux = legajos[i];
        legajos[i]= legajos[posMenor];
        legajos[posMenor]= aux;

        //intercambio nombres:

        strcpy(auxNombre,nombres[i]);
        strcpy(nombres[i],nombres[posMenor]);
        strcpy(nombres[posMenor], auxNombre);

    }

}
void insercion(char nombres[][MAX_LETRAS], int legajos[], int edades[], int posicion, char dato[], int datoLegajos, int datoEdades)
{
    int i= posicion-1;


    while(i >=0 && (strcmp(nombres[i],dato)<0))
    {
        strcpy(nombres[i+1], nombres[i]);
        legajos[i+1]= legajos[i];
        edades[i+1]= edades[i];
        i--;
    }
    strcpy(nombres[i+1], dato);
    legajos[i+1]=datoLegajos;
    edades[i+1]=datoEdades;
}
void ordenamientoxInsercion(char nombres[][MAX_LETRAS], int legajos[], int edades[], int validos)
{

    for (int i=0; i < validos; i++)
    {

        insercion(nombres,legajos,edades,i,nombres[i+1],legajos[i+1],edades[i+1]);

    }


}


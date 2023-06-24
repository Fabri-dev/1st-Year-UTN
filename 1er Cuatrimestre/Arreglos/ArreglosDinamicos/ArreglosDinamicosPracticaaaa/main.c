#include <stdio.h>
#include <stdlib.h>

const int MAXDIM=2;

int * crearArregloDinamico(int t);
int cargarArreglo(int arr[], int t);
void mostrarArreglo(int arr[], int validos);
int * cargarYagrandarArreglo(int * arr, int * t);


int main()
{
    int * arreglo;

    int t,validos;
    printf("Ingrese de que tamanio sera su arreglo: ");
    scanf("%i",&t);

    arreglo= crearArregloDinamico(t);
    validos= cargarArreglo(arreglo,t);
    mostrarArreglo(arreglo,validos);


    arreglo=cargarYagrandarArreglo(arreglo, &validos);
    printf("val: %i \n",validos);
    mostrarArreglo(arreglo,validos);



    return 0;
}

int * crearArregloDinamico(int t)
{
    int * aux= malloc(sizeof(int)*t);
    return aux;

}

int cargarArreglo(int arr[],int t)
{
    char op='s';
    int i=0;


    while(op== 's' && i<t)
    {
        printf("Ingrese un dato: ");
        scanf("%i",&arr[i]);
        i++;
        printf("Desea seguir cargando? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    return i;
}


void mostrarArreglo(int arr[], int validos)
{
    for (int i=0; i <validos; i++)
    {
        printf("Arreglo [%i]: %i \n", i, arr[i]);
    }
}


int * cargarYagrandarArreglo(int * arr, int * t)
{
    char op='s';
    int dimension= *t;

    printf("dimension: %i \n", dimension);
    while(op== 's')
    {
        printf("Ingrese un dato: ");
        scanf("%i",&arr[dimension]);
        arr = realloc(arr,sizeof(int)*(dimension+1));
        dimension++;
        printf("Desea seguir cargando? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }

    *t=dimension;


    return arr;




}







#include <stdio.h>
#include <stdlib.h>
/*
Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.
*/

int CargarArr_DevolverValidos(int arr[], int dimension);
int SumaElementos(int arr[], int validos);

int main()
{
    int arr[20];
    int dimension = 20, validos, suma;
    validos= CargarArr_DevolverValidos(arr,dimension);
    suma= SumaElementos(arr, validos);
    printf("La suma de todos los valores del arreglo es: %i", suma);
    return 0;
}

int CargarArr_DevolverValidos(int arr[], int dimension)
{
    char op;
    int i;
    do {
        printf("Ingrese un valor al arreglo: ");
        fflush(stdin);
        scanf("%i", &arr[i]);
        i++;
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);

    }while(op == 's' && i < dimension);

    return i;
}

int SumaElementos(int arr[],int validos)
{
    int suma=0;

    for (int i= 0; i < validos; i++)
    {
        suma += arr[i];
    }
    return suma;
}

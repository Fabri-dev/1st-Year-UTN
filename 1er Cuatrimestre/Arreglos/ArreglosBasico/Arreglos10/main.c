#include <stdio.h>
#include <stdlib.h>

/**
Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)
*/

void InvertirElementos(int arr[],int validos);
void MostrarArreglo(int arr[], int validos);



int main()
{
    int arreglo[10]= {1,2,3,4,5,6,8,9};
    int validos = 8;
    printf("Arreglo normal: \n");
    MostrarArreglo(arreglo, validos);
    printf("\n");
    InvertirElementos(arreglo, validos);
    printf("Arreglo Invertido: \n");
    MostrarArreglo(arreglo, validos);

    return 0;
}

void InvertirElementos(int arr[],int validos)
{
    for (int i = validos -1, j= 0; i >= 0 , j < i; i--, j++)
    {
        int aux1= arr[j];
        int aux2= arr[i];
        arr[j] = aux2;
        arr[i] = aux1;
    }
}

void MostrarArreglo(int arr[], int validos){
    for (int i=0; i < validos; i++)
    {
        printf("%i", arr[i]);
    }
}

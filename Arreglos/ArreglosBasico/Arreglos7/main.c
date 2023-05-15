#include <stdio.h>
#include <stdlib.h>
/*
Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.

*/
void InsertarLetra(char arr[], int validos , char letra);
void MostrarArreglo(char arr[], int validos);
int main()
{
    char ArregloDeCaracteres[8]= {'a','b','c','e','f'};
    int validos = 5;
    MostrarArreglo(ArregloDeCaracteres, validos);
    InsertarLetra(ArregloDeCaracteres, validos, 'd');
    printf("\n");
    MostrarArreglo(ArregloDeCaracteres, 6);

    return 0;
}

void InsertarLetra(char arr[], int validos , char letra)
{
    int posicion = validos - 1;
    while( posicion >= 0 && letra < arr[posicion])
    {
        arr[posicion+1] = arr[posicion];
        posicion--;
    }
    arr[posicion +1]= letra;

}
void MostrarArreglo(char arr[], int validos){
    for (int i=0; i < validos; i++)
    {
        printf("%c", arr[i]);
    }
}

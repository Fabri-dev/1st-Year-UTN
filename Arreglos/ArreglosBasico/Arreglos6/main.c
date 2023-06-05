#include <stdio.h>
#include <stdlib.h>

/*
6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.
*/

void BuscarCaracter(char arr[],int dimension, char letra);

int main()
{
    char ArregloDeCaracteres[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int dimension = 26;
    char letra;
    printf("Ingrese la letra que quiere buscar en el arreglo: ");
    fflush(stdin);
    scanf("%c", &letra);
    BuscarCaracter(ArregloDeCaracteres, dimension, letra);

    return 0;
}

void BuscarCaracter(char arr[],int dimension, char letra)
{
    int i=0;
    while(i<dimension)
    {
        if(arr[i] == letra)
        {
            return 1;
        }
        i++;
    }

    return 0;
}


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
    int busqueda= 0, cont = 0;
    for (int i=0; i<dimension; i++)
    {
        printf("%c \n", arr[i]);
        if (letra==arr[i])
        {
            busqueda= 1;
            cont = i;
            break;
        }
    }

    if (busqueda== 1)
    {

        printf("La letra: %c se encuentra en el arreglo en la posicion: arr[%i]\n",letra,cont+1 );
    }
}


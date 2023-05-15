#include <stdio.h>
#include <stdlib.h>
/**
Realizar una función que obtenga el máximo carácter de un arreglo dado.
*/

char LetraMax(char arr[], int validos);
void MostrarArreglo(char arr[], int validos);

int main()
{
    char ArrCar[20]={'z','a','c','f','y','s','x','h'};
    int validos = 8;
    char max= LetraMax(ArrCar, validos);
    MostrarArreglo(ArrCar, validos);
    printf("\n");
    printf("La letra maxima del arreglo de caracteres es: %c", max);
    return 0;
}

char LetraMax(char arr[], int validos)
{
    char max= arr[0];
    for (int i=0; i<validos; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void MostrarArreglo(char arr[], int validos){
    for (int i=0; i < validos; i++)
    {
        printf("%c", arr[i]);
    }
}

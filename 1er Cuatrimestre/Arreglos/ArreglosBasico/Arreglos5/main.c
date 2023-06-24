#include <stdio.h>
#include <stdlib.h>
/*
Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100.
(se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)

*/
int CargarElementosConComa(float arr[], int dimension);
float SumaConComa(float arr[], int validos);

int main()
{
    float arr[100];
    int dimension= 100;
    int validos= CargarElementosConComa(arr, dimension);
    float suma= SumaConComa(arr, validos);
    printf("La suma de todos los elementos del arreglo de numeros reales es: %.3f", suma);
    return 0;
}

int CargarElementosConComa(float arr[], int dimension)
{
    char op='s';
    int i= 0;
    do
        {
            printf("Ingrese un valor con coma al arreglo: ");
            scanf("%f", &arr[i]);
            i++;
            printf("Desea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
        }while (op == 's' && i < dimension);


    return i;
}

float SumaConComa(float arr[], int validos)
{
    float suma;
    for (int i=0; i<validos; i++)
    {
        printf("%.3f \n", arr[i]);
        suma+= arr[i];
    }
    return suma;
}

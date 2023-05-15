#include <stdio.h>
#include <stdlib.h>

/*
Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.
*/
int CargarArr_DevolverValidos(int arr[], int dimension);
void MostrarElementosArreglo(int arr[],int validos);


int main()
{
    int arr[20];
    int dimension = 20, validos;
    validos= CargarArr_DevolverValidos(arr,dimension);
    MostrarElementosArreglo(arr, validos);
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

void MostrarElementosArreglo(int arr[],int validos)
{
    for (int i= 0; i < validos; i++)
    {
        printf("Arr posicion [%i] = %i \n", i, arr[i]);
    }
}

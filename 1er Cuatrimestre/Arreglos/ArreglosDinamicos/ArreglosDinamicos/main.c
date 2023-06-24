#include <stdio.h>
#include <stdlib.h>

int contarPares(int arr[], int validos);
int* creardinamico(int t);
void pasarPares(int arr[], int validos, int arrdin[]);
void mostrarArreglo(int arr[], int validos);



int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int validos=10;
    int t= contarPares(arr, validos);

    int*a=creardinamico(t);

    pasarPares(arr, validos, a);

    mostrarArreglo(a, t);


    return 0;
}

int contarPares(int arr[], int val)
{
    int cont=0;
    for (int i=0; i<val; i++)
    {
        if (arr[i]%2== 0)
        {
            cont+=1;
        }
    }
    return cont;
}

int* creardinamico(int t)
{
    int* arrdin;
    arrdin=malloc(sizeof(int)*t);

    return arrdin;
}

void pasarPares(int arr[], int validos, int arrdin[])
{
    int j=0;
    for (int i=0; i<validos;i++)
    {
        if (arr[i]%2== 0)
        {
            arrdin[j]=arr[i];
            j++;
        }
    }


}

void mostrarArreglo(int arr[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("|%i|", arr[i]);
    }
}



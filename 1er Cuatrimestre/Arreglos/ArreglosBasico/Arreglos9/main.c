#include <stdio.h>
#include <stdlib.h>

/**

Realizar una función que determine si un arreglo es capicúa.

*/


int EsCapicua(int arr[], int validos);
int CargarArregloyRetornarValidos(int arr[], int dimension);
void MostrarArreglo(int arr[], int validos);

int main()
{
    int ArregloCap[10], dimension= 10;
    int validos= CargarArregloyRetornarValidos(ArregloCap, dimension);
    void MostrarArreglo(int arr[], int validos);
    int flag= EsCapicua(ArregloCap, validos);
    printf("Flag: %i \n", flag);
    printf("El arreglo ingresado %s", flag ? "Es capicua" : "NO es capicua");
    return 0;
}

int EsCapicua(int arr[], int validos)
{
    int inicio=0, finall= validos - 1;
    while(inicio != finall && inicio < finall)
    {
        if (arr[inicio] != arr[finall])
        {
            return 0;
        }
        inicio++;
        finall--;
    }
    return 1;

}

int CargarArregloyRetornarValidos(int arr[], int dimension)
{
    char op = 's';
    int i= 0;

    while(op == 's' && i< dimension)
    {
        printf("Ingrese un valor al arreglo: ");
        fflush(stdin);
        scanf("%i", &arr[i]);
        i++;
        printf("Desea Continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);
    }
    return i;


}

void MostrarArreglo(int arr[], int validos){
    for (int i=0; i < validos; i++)
    {
        printf("%i", arr[i]);
    }
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1=0,numero2=0;
    printf("Numero1: %i, Numero2: %i \n", numero1, numero2);
    CargarElementos(&numero1, &numero2);

    printf("Numero1: %i, Numero2: %i (Cargados por el usuario)", numero1, numero2);


    return 0;
}

void CargarElementos(int* num1, int* num2)
{
    printf("Ingrese un valor al num1: ");
    scanf("%i", num1);
    printf("Ingrese un valor al num2: ");
    scanf("%i", num2);
}

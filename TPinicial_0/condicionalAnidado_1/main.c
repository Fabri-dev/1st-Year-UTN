#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,resultado;

    printf("Ingrese num1: ");
    scanf("%i",&num1);

    printf("Ingrese num2: ");
    scanf("%i", &num2);

    if (num1 == num2){
        resultado = num1 * num2;
    } else if (num1 > num2){
        resultado = num1 - num2;
    } else if (num1 < num2) {
        resultado = num1 + num2;
    }
    printf ("El resultado es %i", resultado);
    return 0;
}

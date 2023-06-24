#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3, num_mayor;

    printf ("Ingrese 3 numeros: ");
    scanf("%i" "%i" "%i", &num1, &num2, &num3);

    if ((num1 > num2) && (num1 > num3)){
        num_mayor = num1;
    } else if ((num2 > num1) && (num2 > num3)){
        num_mayor = num2;
    } else if ((num3 > num1) && (num3 > num2)){
        num_mayor = num3;
    }

    printf("El numero mayor de los tres ingresados es: %i", num_mayor);

    return 0;
}

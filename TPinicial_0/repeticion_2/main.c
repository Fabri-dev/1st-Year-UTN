#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, max, cubo, cuarta;

    printf("Ingrese cuantos numeros quiere leer: ");
    scanf("%i", &max);

    for (i=1; i <= max; i++){
        printf("Ingrese un numero: ");
        scanf("%i", &num);
        cubo = pow(num, 3);
        cuarta = pow(num, 4);
        printf("El numero ingresado al cubo es: %i y a la cuarta es: %i \n", cubo, cuarta);

    }
    return 0;
}

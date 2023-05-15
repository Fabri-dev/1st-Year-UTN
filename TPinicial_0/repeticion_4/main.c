#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, max, i;

    printf("Ingrese cuantos numeros quiere leer: ");
    scanf("%i", &max);

    for (i= 1; i <= max; i++){
        printf("Ingrese un numero: ");
        scanf("%i", &num);
        if (num < 0){
            printf("El numero en positivo es: %i \n", (num * -1));
        } else if (num > 0){
            printf("El numero %i es positivo \n", num);
        } else if (num == 0){
            printf("El numero es 0 \n");
        } else {
            printf("Error ingrese un elemento valido \n");
        }
    }
    return 0;
}

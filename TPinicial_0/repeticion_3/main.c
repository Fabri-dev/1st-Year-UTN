#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, max, i;

    printf("Ingrese cuantos numeros quiere leer: ");
    scanf("%i", &max);

    for(i=1; i <= max; i++){

        printf("Ingrese un numero: ");
        scanf("%i", &num);
        if (num > 0){
            printf("%i \n", num);
        } else if(num < 0){
            printf("El numero ingresado es negativo \n");
        } else {
            printf("El numero ingresado es 0 \n");
        }

    }
    return 0;
}

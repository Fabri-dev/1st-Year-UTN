#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, resultado;

    printf("Ingrese el numero del cual quiere saber su tabla de multiplicacion: ");
    scanf("%i", &num);

    for (i=0; i <= 10; i++){
        resultado = num * i;
        printf(" %i x %i = %i \n", num, i, resultado);
    }
    printf("Esa es la tabla del %i", num);

    return 0;
}

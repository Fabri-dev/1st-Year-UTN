#include <stdio.h>
#include <stdlib.h>

int main()
{
    float notas,promedio,total,nota,i;
    printf("Ingrese la cantidad de notas que quiere ingresar: \n");
    scanf("%f", &notas);
        for (i=1; i <= notas ; i++){
        printf("Ingrese la nota: ");
        scanf("%f", &nota);
        total = total + nota;
    }
    promedio = total / notas ;
    printf("Su promedio es: %.2f \n",promedio) ;
    return 0;
}

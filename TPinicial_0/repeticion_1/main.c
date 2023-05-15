#include <stdio.h>
#include <stdlib.h>

int main()
{
    int suma, nota, notas, i;
    float promedio;
    char nombre[99];

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", &nombre);
    printf("Ingrese la cantidad de notas que quiere promediar: ");
    scanf("%i", &notas);

    for (i= 1; i<=notas; i++){
        printf("Ingrese la nota de %s: ", nombre);
        scanf("%i", &nota);
        suma += nota;
    }

    promedio = suma/notas;

    printf("El promedio de %s es: %.2f", nombre, promedio);


    return 0;
}

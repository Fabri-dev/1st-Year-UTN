#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cantAlumnos, notaMin, notaMax, i;
    float promedio, suma, nota;

    notaMax = 0;
    suma = 0;

    printf("Ingrese el total de alumnos para calcular la calificacion promedio: ");
    scanf("%i", &cantAlumnos);

    for (i = 1; i <= cantAlumnos; i++){

        printf("Ingrese la nota del alumno: ");
        scanf("%f", &nota);


        if (notaMin == 0){
            notaMin = nota;
        } else if (nota < notaMin){
            notaMin = nota;
        }

        if (nota > notaMax){
            notaMax = nota;
        }
        suma += nota;
    }
        promedio=suma/cantAlumnos;

        printf("La nota promedio de todos los alumnos es: %.2f \n", promedio);
        printf("La nota min es: %i, y la nota max es: %i \n", notaMin, notaMax);

    return 0;
}

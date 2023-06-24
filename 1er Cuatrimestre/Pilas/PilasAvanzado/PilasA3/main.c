#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila a;
    int contador= 0, suma= 0;
    float promedio;
    char op = 's';
    inicpila(&a);

    do {
        leer(&a);
        suma += tope(&a);
        printf("Desea continuar? s/n : ");
        fflush(stdin);
        scanf("%c", &op);
        contador++;

    } while (op == 's');

    promedio = (float)suma / contador;
    printf("%.2f", promedio);


    return 0;
}

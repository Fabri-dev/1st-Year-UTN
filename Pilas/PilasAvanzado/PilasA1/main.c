#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila a;
    int contador= 0, suma= 0;
    char op = 's';
    inicpila(&a);

        do {
        leer(&a);
        printf("Desea continuar? s/n : ");
        fflush(stdin);
        scanf("%c", &op);
        contador++;
    } while (op == 's');

    for (int i=0; i < contador; i++){
        suma = suma + tope(&a);
        desapilar(&a);

    }
    printf("La suma de todos los elementos de PILA A es: %i \n", suma);



    return 0;
}

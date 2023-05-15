#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila a;
    int contador= 0;
    char op = 's';
    inicpila(&a);

        do {
        leer(&a);
        contador++;
        printf("Desea continuar? s/n : ");
        fflush(stdin);
        scanf("%c", &op);
    } while (op == 's');

    mostrar(&a);
    printf("Su pila tiene %i elementos. \n", contador);


    return 0;
}

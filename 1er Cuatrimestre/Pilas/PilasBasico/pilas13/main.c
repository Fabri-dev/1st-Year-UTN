#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila limite, mayores, a, menores;
    inicpila(&menores);
    inicpila(&limite);
    inicpila(&mayores);
    inicpila(&a);

    printf("PILA LIMITE \n");
    leer(&limite);
    printf("PILA A \n");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);

    mostrar(&limite);
    mostrar(&a);

    while(!pilavacia(&a))
    {
        if(tope(&a) >= tope(&limite))
        {
            apilar(&mayores, desapilar(&a));
        }
        else
        {
            apilar(&menores, desapilar(&a));
        }
    }

    printf("------------PILA LIMITE----------------------------- \n");
    mostrar(&limite);
    printf("------------PILA MENORES---------------------------- \n");
    mostrar(&menores);
    printf("------------PILA MAYORES---------------------------- \n");
    mostrar(&mayores);

    return 0;
}

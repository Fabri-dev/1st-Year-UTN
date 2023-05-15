#include <stdio.h>
#include <stdlib.h>
#include"pila.h"

int main()
{
    Pila cap, aux, copia, basura;
    int numero;
    char op;

    inicpila(&basura);
    inicpila(&cap);
    inicpila(&aux);
    inicpila(&copia);

    do
    {
        leer(&cap);
        printf ("desea cargar mas numeros? S para si otro caracter para no: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    while (op=='s');

    while(!pilavacia(&cap))
    {
        numero = tope(&cap);
        apilar(&copia, numero);
        apilar(&aux, desapilar(&cap));
    }

    while(!pilavacia(&aux))
    {
        apilar(&cap,desapilar(&aux));
    }

    while(!pilavacia(&cap) && !pilavacia(&copia) && (tope(&cap) == tope(&copia))
    {
            apilar(&aux, desapilar(&cap));
            apilar(&basura,desapilar(&copia));
    }
    if (pilavacia(&aux) && pilavacia(&copia))
    {
        printf("LA PILA ES CAPICUA");
    } else {
        printf("LA PILA NO ES CAPICUA");
    }



    mostrar(&cap);

    return 0;
}

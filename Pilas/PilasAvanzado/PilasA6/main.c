#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    char continuar='s';
    Pila pila1, menores, mayores, auxMax;
    inicpila (&pila1);
    inicpila (&menores);
    inicpila(&mayores);
    inicpila(&auxMax);
    do
    {
        leer(&pila1);
        printf ("desea cargar mas numeros? S para si otro caracter para no: ");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while (continuar=='s');

    while (!pilavacia(&pila1))
    {
        apilar(&menores, desapilar(&pila1));
        while(!pilavacia(&pila1))
        {
            if(tope(&pila1)>tope(&menores))
            {
                apilar (&mayores, desapilar(&pila1));
            }
            else
            {
                apilar(&mayores, desapilar(&menores));
                apilar(&menores, desapilar(&pila1));

            }

        }

    }

    while (!pilavacia(&mayores))
    {
        apilar(&auxMax, desapilar(&mayores));
        while(!pilavacia(&auxMax))
        {
            if (tope(&mayores)<(tope(&auxMax)))
            {

                apilar(&menores, desapilar(&mayores));
            }
            else {
                apilar(&menores, desapilar(&auxMax));
            }

        }
    }

    mostrar(&auxMax);
    printf("-------PILA ORDENADA------");
    mostrar(&menores);
    mostrar(&mayores);



    return 0;
}

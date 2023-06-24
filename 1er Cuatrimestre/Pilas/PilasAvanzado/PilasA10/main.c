#include <stdio.h>
#include <stdlib.h>
#include"pila.h"
int main()
{
    Pila a,b,aux,aub,basura;
    char op;

    inicpila(&a);
    inicpila(&b);
    inicpila(&aux);
    inicpila(&aub);
    inicpila(&basura);

    do
    {
        printf("CONJUNTO A \n");
        leer(&a);
        printf("Desea ingresar mas numeros? s/n: ");
        fflush(stdin);
        scanf("%c", &op);

    }
    while(op == 's');

    do
    {
        printf("CONJUNTO B \n");
        leer(&b);
        printf("Desea ingresar mas numeros? s/n: ");
        fflush(stdin);
        scanf("%c", &op);

    }
    while(op == 's');

    while (!pilavacia(&a))
    {
        while(!pilavacia(&b))
        {

            if (tope(&a) == tope(&b))
            {
                apilar(&basura, desapilar(&b));
            }
            else
            {
                apilar(&aux, desapilar(&b));
            }

        }
        apilar(&aub, desapilar(&a));
        while(!pilavacia(&aux))
        {
            apilar(&b, desapilar(&aux));
        }
    }

    while(!pilavacia(&b))
    {
        apilar(&aub, desapilar(&b));
    }

    mostrar(&aub);


    return 0;
}

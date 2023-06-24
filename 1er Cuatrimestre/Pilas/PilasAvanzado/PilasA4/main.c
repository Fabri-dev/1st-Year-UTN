#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila a, mayorAux, menor,mayores;
    inicpila(&a);
    inicpila(&mayores);
    inicpila(&mayorAux);
    inicpila(&menor);

    leer(&a);
    leer(&a);
    leer(&a);

    while(!pilavacia(&a))
    {
        apilar(&menor, desapilar(&a));
        while (!pilavacia(&a))
        {
            if (tope(&a) < tope(&menor))
            {
                apilar(&mayores, desapilar(&menor));
                apilar(&menor, desapilar(&a));
            }
            else
            {
                apilar(&mayor);
            }
        }
    }

    while(!pilavacia(&mayores)){
        apilar(&mayorAux, desapilar(&mayores));
        while(!pilavacia(&mayorAux)){
            if(tope(&mayores) < tope(&mayorAux)){
                apilar(&menor, desapilar(&mayores))
            } else{
                apilar(&menor, desapilar(&mayoresAux));
            }
        }
    }

    mostrar(&mayorAux);
    mostrar(&mayores);
    mostrar(&a);
    mostrar(&menor);


    return 0;
}

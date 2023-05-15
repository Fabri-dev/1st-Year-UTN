#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{

    Pila pilita1, pilita2, aux1, aux2;
    inicpila (&pilita1) ;
    inicpila (&pilita2) ;
    inicpila (&aux1) ;
    inicpila (&aux2) ;

    apilar(&pilita1, 1);
    apilar(&pilita1, 2);
    apilar(&pilita1, 3);
    apilar(&pilita1, 4);
    apilar(&pilita1, 5);


    printf("PILITA 1");
    mostrar(&pilita1);

    apilar(&aux1, desapilar(&pilita1));
    apilar(&aux1, desapilar(&pilita1));
    apilar(&aux1, desapilar(&pilita1));


    while(!pilavacia(&pilita1)){
          apilar(&aux2, desapilar(&pilita1));
          }

          printf("PILITA 1");
          mostrar(&pilita1);

          printf("AUX 1");
          mostrar(&aux1);

          printf("AUX 2");
          mostrar(&aux2);


    return 0;
}

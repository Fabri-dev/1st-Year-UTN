#include <stdio.h>
#include <stdlib.h>
//En un almacén se hace un 20% de descuento a los clientes cuya compra supere los $5000
//¿Cuál será la cantidad que pagará una persona por su compra?



int main()
{
    int descuento;
    float compra, compracondes;
        printf("cual es el monto de la compra?\n");

        scanf("%f",&compra);

        printf("ingrese el descuento para aplicar a la compra\n");

        scanf("%i",&descuento);

    compracondes= compra - compra * descuento/100 ;
    printf("Su compra con descuento es: %.2f", compracondes) ;
    return 0;
}

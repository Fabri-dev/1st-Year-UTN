#include <stdio.h>
#include <stdlib.h>
    ///Hacer un algoritmo que calcule el total a pagar por la compra de camisas.
    ///Si se compran tres camisas o más se aplica un descuento del 20% sobre el total de la compra
    ///y si son menos de tres camisas un descuento del 10%

int main()
{
    int cantcam;
    float desc, precio, total, desc2;

    printf("Cuantas camisas compraste? \n");
    scanf("%i",&cantcam);
    printf("Cuanto pagaste por cada camisa? \n");
    scanf("%f", &precio);

    if (cantcam >= 3){
        desc = 0.2;

    }else{
        desc= 0.1 ;
    }

    desc2 = (cantcam * precio) * desc;
    total = cantcam * precio - cantcam * precio * desc;

    printf("El descuento es: %.2f\n", desc2);

    printf("El precio total a pagar por las camisas con el descuento es de: %.2f",total);

    return 0;
}

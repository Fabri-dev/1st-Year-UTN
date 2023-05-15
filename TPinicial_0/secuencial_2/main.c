#include <stdio.h>
#include <stdlib.h>

int main()
{
  float compra, resultado, descuento;

  printf("Ingrese el valor de su compra: ");
  scanf("%f", &compra);

  if (compra > 5000) {
    printf("Ingrese el descuento que le hara a su compra: ");
    scanf("%f", &descuento);
    resultado = compra - compra * (descuento/100);
    printf("El valor de su compra con descuento es: %.2f", resultado);
  }else{
    resultado = compra;
    printf("El valor de su compra es de: %.1f", resultado);
  }


    return 0;
}

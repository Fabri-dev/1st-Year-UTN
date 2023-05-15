#include <stdio.h>
#include <stdlib.h>
void CambiarSigno(int* num);

int main()
{
    int numero;
    printf("Ingrese un numero positivo: ");
    scanf("%i", &numero);
    if (numero > 0)
    {
    CambiarSigno(&numero);
    printf("El numero positivo pasado a negativo: %i", numero);

    }else{

    printf("El numero ya es negativo");
    }
    return 0;
}

void CambiarSigno(int* num)
{

    if (*num > 0)
    {
        *num*= -1;
    }
}

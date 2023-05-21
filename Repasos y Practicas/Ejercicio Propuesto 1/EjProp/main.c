#include <stdio.h>
#include <stdlib.h>

void declararCantyPrecio(int*, int*);
int montoTotal(int, int);
int descuento(int, int);
void mostrarCompra(int, int, int, int);
void vender(int*, int*);


int main()
{
    char op='s';
    int sumaTotal=0, prodVendido=0;


    while (op=='s' || op=='S')
    {
        vender(&sumaTotal,&prodVendido);
        printf("\n");
        printf("Desea hacer otra venta? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    printf("El monto total de las ventas de hoy es: %i \n", sumaTotal);
    printf("La cantidad de producto vendido hoy fue de: %i productos \n", prodVendido);




    return 0;
}
//a
void declararCantyPrecio(int * cant, int * precio)
{
    printf("Ingrese la cantidad de productos que compro: ");
    scanf("%i", cant);
    printf("Ingrese el precio por unidad: ");
    scanf("%i", precio);
}

//b
int montoTotal(int prod, int precio)
{
    int suma = prod * precio;
    return suma;
}

//c
int descuento(int suma, int prod)
{
    float desc=0;

    if (suma>1000 && prod >10)
    {
        desc=0.15;
    }
    else if(suma>2000 && prod>=25)
    {
        desc=0.2;
    }

    return (float)suma * desc;
}

//d

void mostrarCompra(int cant, int precioUnidad, int totalParcial, int desc)
{
    int montoPagar= totalParcial - desc;
    printf("Empresa Pirulo \n");
    printf("Cantidad de productos................ %i \n", cant);
    printf("Precio por producto................ $%i \n", precioUnidad);
    printf("Total parcial................ $%i \n", totalParcial);
    printf("Descuento aplicado................ -$%i \n", desc);
    printf("Monto a pagar................ $%i \n", montoPagar);
}


//e y f
void vender(int* sumaTotal, int* prodTotal)
{
    int cantProd=0, precioxunidad=0, suma=0, desc=0;
    declararCantyPrecio(&cantProd,&precioxunidad);
    suma=montoTotal(cantProd,precioxunidad);
    desc= descuento(suma,cantProd);
    mostrarCompra(cantProd,precioxunidad,suma,desc);

    *prodTotal+=cantProd;
    *sumaTotal+= suma-desc;
}













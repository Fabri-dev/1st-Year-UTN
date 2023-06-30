#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"
#define MAXDIMSTR 40


void menuPrincipal(char archivoDatosPersonales[], char archivoEmpleados[])
{
    char op='s';
    int opsw=0;

    do
    {
        elegirOpciones();

        opsw=preguntarDato();
        switch(opsw)
        {
        case 1:
            cargarArchivoDatosPersonales(archivoDatosPersonales);
            break;
        case 2:
            cargarArchivoEmpleado(archivoEmpleados,archivoDatosPersonales);
            break;
        case 3:
            elegirQueMostrar(archivoEmpleados,archivoDatosPersonales);
            break;
        case 4:
            break;
        case 5:
            break;
        }

        printf("Desea seguir navegando? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        limpiarPantalla();
    }
    while(op=='s');
}


void elegirQueMostrar(char archivoEmpleados[], char archivoDatosPersonales[])
{
    char op='s', flag=0, dato=0;
    int opsw=0;
    do
    {
        opcionesDeMostrar();
        opsw=preguntarDato();

             switch(opsw)
        {
        case 1:
            flag=0;
            mostrarEmpleados(archivoEmpleados);
            break;
        case 2:

            do
            {
                mostrarPuestos();
                printf("que puesto quiere mostrar?: ");
                dato=preguntarDato();
            }while(validarMostrarPuestos(dato)==1);

            elegirQuePuestoMostrar(archivoEmpleados,dato);
            flag=0;
            break;
        case 3:
            flag=0;
            break;
        case 4:
            flag=0;
            break;
        case 5:
            flag=1;
            op='s';
            break;
        default:
            puts("Ingrese un dato correcto");
            break;
        }

        if (flag == 0)
        {
            puts("Desea seguir mostrando empleados? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
        }


    }
    while(op=='s');

}

int validarMostrarPuestos(int dato)
{
    int flag=0;
    if (dato < 1 || dato>6)
    {
        flag=1;
        puts("Ingrese un dato correcto por favor");
    }
    return flag;

}


void opcionesDeMostrar()
{
    puts("---------------------------------------------------------");
    puts("1. Mostrar todos los empleados");
    puts("2. Mostrar empleados de un puesto en especifico");
    puts("3. Mostrar empleados de una edad especifica");
    puts("4. Mostrar empleados de una nacionalidad especifica");
    puts("5. Volver atras");
    puts("---------------------------------------------------------");
}


void elegirOpciones()
{
    puts("-----------------------------------------------------------------------------------------------");
    puts("1. Cargar archivo datos personales");
    puts("2. Cargar archivo empleados");
    puts("3. Mostrar empleados");
    puts("4. Consultar datos generales");
    puts("5. Modificar datos empleados");
    puts("---------------------------------Bienvenido, que desea hacer?---------------------------------- \n\n");
}

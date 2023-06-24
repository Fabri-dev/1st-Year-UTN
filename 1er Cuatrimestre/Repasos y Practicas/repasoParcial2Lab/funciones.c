#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



void menu(Disfraz arregloDisfraces[],char archivoM[], char archivoH[])
{
    int validos=0, dato=0, disfracesH=0, disfracesM=0;

    char op='s';
    int opsw;

    while (op=='s')
    {
        printf("EVALUACION: \n");
        printf("1) Ejercicio 1 \n");
        printf("2) Ejercicio 2 \n");
        printf("3) Ejercicio 3 \n");
        printf("4) Ejercicio 4 \n");
        printf("5) Ejercicio 5 \n");

        puts("\nQue ejercicio quiere elegir?: ");
        scanf("%i",&opsw);


        switch(opsw)
        {
        case 1:
            cargarArregloDisfraces(arregloDisfraces,&validos);
            printf("val: %i",validos);
            break;
        case 2:
            printf("-----Ingrese el precio-----\n");
            dato=preguntarDato();
            cantidadDeDisfracesXPrecio(arregloDisfraces,validos,dato,&disfracesH,&disfracesM);
            printf("La cantidad de disfraces mayores a %i es: \n",dato);
            printf("Hombres: %i \n",disfracesH);
            printf("Mujeres: %i \n",disfracesM);

            break;
        case 3:
            arregloToArchivos(archivoM,archivoH,arregloDisfraces,validos);
            printf("Disfraces pasados a los respectivos archivos :)");
            break;
        case 4:
            mostrarLosArchivos(archivoM,archivoH);
            break;
        case 5:

            break;
        default:
            printf("ingrese un ejercicio correcto \n");
            break;
        }

        printf("\nDesea elegir otro ejercicio? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");
    }

}


//1:

Disfraz cargarUnDisfraz()
{
    Disfraz aux;
    int comprobacion=0;

    printf("Ingrese el ID del disfraz: ");
    scanf("%i",&aux.id);

    printf("Ingrese el nombre del disfraz: ");
    fflush(stdin);
    gets(aux.nombreDisfraz);


    while(comprobacion==0)
    {
        printf("Ingrese el genero(hombre o mujer): ");
        fflush(stdin);
        gets(aux.genero);

        comprobacion= validarGenero(aux.genero); // si la comprobacion es 0 entonces voy a seguir preguntando el genero

        if (comprobacion==0)
        {
            puts("Ingrese un genero valido");
        }
    }
    printf("Ingrese el precio del alquiler del disfraz: ");
    scanf("%i",&aux.precioAlquiler);



    return aux;
}

int validarGenero(char genero[])
{

    if ((strcmp(genero, "hombre") == 0) || (strcmp(genero, "Hombre") == 0) || (strcmp(genero, "Mujer")==0) || (strcmp(genero, "mujer")==0))
    {
        return 1; // si es valido retorno 1

    }
    return 0; // sino retorno 0
}

void cargarArregloDisfraces(Disfraz arr[], int * validos)
{
    char op='s';
    Disfraz aux;

    while(op=='s')
    {
        aux = cargarUnDisfraz();
        arr[*validos]=aux;
        *validos+=1; // no retorno los validos ya que los estoy pasando por referencia

        printf("\nDesea seguir cargando disfraces al arreglo? s/n: ");
        fflush(stdin);
        scanf("%c",&op);

    }

}



//2:

int preguntarDato()
{
    int dato=0;
    printf("Ingrese un dato: ");
    fflush(stdin);
    scanf("%i",&dato);
    return dato;
}


int hombreOmujer(char genero[]) // en esta funcion verifico si el genero es hombre (1) o mujer (0)
{
    if ((strcmp(genero, "hombre") == 0) || (strcmp(genero, "Hombre") == 0))
    {
        return 1;

    }
    return 0;
}

void cantidadDeDisfracesXPrecio(Disfraz arr[],int validos,int dato, int* disfracesH, int* disfracesM)
{
    for(int i=0; i <validos; i++)
    {
        if ((hombreOmujer(arr[i].genero) == 1) && (arr[i].precioAlquiler > dato)) // entonces es hombre
        {
            *disfracesH+=1;
        }
        else if ((hombreOmujer(arr[i].genero) == 0) && (arr[i].precioAlquiler > dato)) // sino es mujer
        {
            *disfracesM+=1;
        }

    }


}
//3:
void arregloToArchivos(char archivoM[], char archivoH[], Disfraz arr[], int validos)
{
    FILE * archiH;
    FILE * archiM;

    archiH = fopen(archivoH,"ab");
    archiM = fopen(archivoM,"ab");

    int comprobacion=0;

    if ( (archiH != NULL) && (archiM != NULL) )
    {

        for (int i=0; i <validos; i++)
        {

            comprobacion= hombreOmujer(arr[i].genero);

            if (comprobacion == 1)
            {
                fwrite(&arr[i],sizeof(Disfraz),1,archiH);
            }
            else if (comprobacion == 0)
            {
                fwrite(&arr[i],sizeof(Disfraz),1,archiM);

            }

        }

        fclose(archiH);
        fclose(archiM);
    }
    else
    {
        printf("Error con los archivos");

    }


}


//4:

void mostrarDisfraz(Disfraz aux)
{
    puts("-------------Disfraz------------------");
    printf("El ID es: %i \n", aux.id);
    printf("El nombre es: %s \n", aux.nombreDisfraz);
    printf("El genero es: %s \n", aux.genero);
    printf("El precio del alquiler es: %i \n", aux.precioAlquiler);
    puts("--------------------------------------\n");

}

void mostrarArchivo(char archivo[])
{
    FILE * archi;
    Disfraz aux;
    archi = fopen(archivo,"rb");

    if(archi != NULL)
    {
        while(fread(&aux,sizeof(Disfraz),1,archi)>0)
        {
            mostrarDisfraz(aux);
        }

        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");
    }
}
void mostrarLosArchivos(char archivoM[],char archivoH[])
{
    printf("--------------DISFRACES HOMBRE------------------ \n");
    mostrarArchivo(archivoH);
    puts("---------------------------------------------------\n\n");
    printf("--------------DISFRACES MUJER---------------------\n");
    mostrarArchivo(archivoM);
    puts("---------------------------------------------------\n\n");
}
//5:


int comprobarNombre(char archivo[], char nombre[])
{
    FILE * archi;

    archi= fopen(archivo,"rb");


    Disfraz aux;

    if(archi != NULL)
    {
        while((fread(&aux,sizeof(Disfraz),1,archi)>0))
        {
            if(strcmp(aux.nombreDisfraz,nombre)==0)
            {
                return 1;
            }
        }

    }
    else
    {
        printf("Error con el archivo");
    }

    return 0;
}

void modificarNombreDisfraz(Disfraz * aux)
{



}

void modificarArchivo(char archivo)
{
    FILE * archi;
    char dato[20];
    int comprobacion=0;
    archi = fopen(archivo,"r+b");



    if(archi != NULL)
    {
        printf("-------------Tiene estos disfraces para modificar--------------------------\n");
        mostrarArchivo(archivo);

            while(comprobacion==0)
            {
            printf("Cual disfraz quiere modificar? (Ingrese su Nombre): ");
            gets(dato);
            comprobacion = comprobarNombre(archivo,dato);
                if (comprobacion == 0)
                {
                    printf("Ingrese un nombre valido");
                }

            }



        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");

    }



}











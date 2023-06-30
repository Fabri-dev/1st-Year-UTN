#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAXDIM 30


void menu(stDireccion arregloDireccion[], stPelicula arregloPelicula[], char archivoDirectoresMalos[],char archivoDirectoresBuenos[], char archivoPeliculas[])
{
    int idPel=0, idDirec=0;
    int opsw;
    char op='s';

    int validosDirecc=0, validosPeli=0;


    while(op=='s')
    {

        printf("------------Ejercicios---------------\n");
        printf("Ejercicio 1 \n");
        printf("Ejercicio 2 \n");
        printf("Ejercicio 3 \n");
        printf("Ejercicio 4 \n");
        printf("Ejercicio 5 \n\n");

        printf("Que ejercicio quiere elegir?: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            validosDirecc= cargarArregloDireccion(arregloDireccion,&idDirec);

            printf("valD= %i",validosDirecc);

            break;
        case 2:

            validosPeli = cargarArregloPelicula(arregloPelicula,arregloDireccion,validosDirecc,&idPel);

            printf("valP= %i", validosPeli);
            break;
        case 3:

            cargarArchivoDirectores(arregloDireccion,validosDirecc,archivoDirectoresBuenos,archivoDirectoresMalos);
            cargarArchivoPeliculas(arregloPelicula,validosPeli,archivoPeliculas);

            break;
        case 4:

            clasificarPeliculas(archivoPeliculas);
            printf("Peliculas catalogadas correctamente \n");
            break;
        case 5:

            mostrarArchivoPeliculas(archivoPeliculas);
            mostrarTodasLasDirecciones(archivoDirectoresBuenos,archivoDirectoresMalos);

            break;
        default:
            printf("Ingrese un ejercicio valido >:c \n");
            break;
        }
        printf("Desea seguir eligiendo ejercicios? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");
    }


}

int validarDatosDireccion(int dato)
{
    int maximo= 100;
    if(dato < 0 || dato > maximo)
    {
        printf("Ingrese un dato dentro de un rango valido \n");
        return 1;
    }
    else
    {
        return 0;

    }
}

stDireccion crearUnaDireccion(int * IDdirec)
{
    stDireccion aux;

    aux.idDireccion=*IDdirec;
    *IDdirec+=1;

    // printf("Ingrese el ID de la direccion: ");
    //scanf("%i",&aux.idDireccion);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(aux.nombre);
    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(aux.apellido);

    do
    {
        printf("Ingrese la cantidad de premios: ");
        scanf("%i",&aux.cantPremios);

    }
    while(validarDatosDireccion(aux.cantPremios));

    do
    {
        printf("Ingrese la cantidad de peliculas dirigidas: ");
        scanf("%i",&aux.cantPelisDirigidas);

    }
    while(validarDatosDireccion(aux.cantPelisDirigidas));

    return aux;

}


int cargarArregloDireccion(stDireccion arr[], int * IDdirec)
{
    char op='s';
    int i=0;

    while(op=='s')
    {
        arr[i]= crearUnaDireccion(IDdirec);
        i++;

        printf("Desea seguir cargando direcciones? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }

    return i;
}


int validarDuracion(int dato)
{
    int maximo=240;

    if (dato < 0 || dato > maximo)
    {
        printf("Ingrese una duracion valida \n");
        return 1;

    }
    else
    {
        return 0;
    }




}


int validarIDdireccion(stDireccion arr[],int validos, int dato)
{
    for (int i=0; i <validos; i++)
    {
        if (arr[i].idDireccion == dato )
        {
            return 0;
        }
    }

    printf("Ingrese una idDireccion valida \n");
    return 1;

}


stPelicula crearUnaPelicula(stDireccion arrDi[], int validosDi, int * IDpeli)
{
    stPelicula aux;

    aux.tipoMetraje=-9;

    aux.idPelicula=*IDpeli;
    *IDpeli+=1;

    //printf("Ingrese el ID de la pelicula: ");
    //scanf("%i",&aux.idPelicula);

    printf("Ingrese el nombre de la pelicula: ");
    fflush(stdin);
    gets(aux.nombre);

    do
    {
        printf("Ingrese la duracion de la pelicula: ");
        scanf("%i",&aux.minutosDuracion);

    }
    while(validarDuracion(aux.minutosDuracion));

    printf("Ingrese el genero de la pelicula: ");
    fflush(stdin);
    gets(aux.genero);

    printf("Ingrese el pais de la pelicula: ");
    fflush(stdin);
    gets(aux.pais);

    mostrarArregloDir(arrDi,validosDi);


    do
    {

        printf("Ingrese el IDdireccion de esta pelicula: ");
        scanf("%i",&aux.idDireccion);

    }
    while(validarIDdireccion(arrDi,validosDi,aux.idDireccion));




    return aux;
}

void mostrarArregloDir(stDireccion arr[],int validos)
{
    printf("Tiene estos ID de directores: \n");

    for (int i=0; i < validos; i++)
    {
        printf("(%i) \n",arr[i].idDireccion);
    }



}

int cargarArregloPelicula(stPelicula arrPel[], stDireccion arrDirecc[], int validosDirecc, int * IDpeli)
{
    char op='s';
    int i=0;

    while(op=='s')
    {
        arrPel[i]= crearUnaPelicula(arrDirecc,validosDirecc,IDpeli);
        i++;

        printf("Desea seguir cargando peliculas? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }

    return i;


}


void cargarArchivoPeliculas(stPelicula arr[],int validos, char archivoPeliculas[])
{
    FILE* archi= fopen(archivoPeliculas,"ab");


    if (archi != NULL)
    {
        for (int i=0; i < validos; i++)
        {
            fwrite(&arr[i],sizeof(stPelicula),1,archi);
        }
        printf("Peliculas cargadas exitosamente al archivo \n");

        fclose(archi);
    }
    else
    {

        printf("Error con el archivo \n");
    }



}

void cargarArchivoDirectores(stDireccion arr[],int validos,char archivoDirectoresBuenos[], char archivoDirectoresMalos[])
{
    FILE* archiBuenos= fopen(archivoDirectoresBuenos,"ab");
    FILE* archiMalos= fopen(archivoDirectoresMalos,"ab");

    int max=10;

    if (archiBuenos != NULL && archiMalos != NULL)
    {
        for (int i=0; i < validos; i++)
        {
            if(arr[i].cantPelisDirigidas > max)
            {
                fwrite(&arr[i],sizeof(stDireccion),1,archiBuenos);
            }
            else
            {
                fwrite(&arr[i],sizeof(stDireccion),1,archiMalos);
            }
        }
        printf("Directores cargados exitosamente a los respectivos archivos \n");

        fclose(archiBuenos);
        fclose(archiMalos);
    }
    else
    {

        printf("Error con archivos \n");
    }

}

void catalogarTipoMetraje(stPelicula * aux)
{
    int cortoMetraje=45;


    if(aux->minutosDuracion < cortoMetraje )
    {
        aux->tipoMetraje=0;
    }
    else if (aux->minutosDuracion > cortoMetraje)
    {
        aux->tipoMetraje=1;
    }


}


void clasificarPeliculas(char archivoPel[])
{
    FILE* archi= fopen(archivoPel,"r+b");
    stPelicula aux;
    int cortoMetraje=45;
    if(archi != NULL)
    {
        while(fread(&aux,sizeof(stPelicula),1,archi) > 0)
        {

            catalogarTipoMetraje(&aux);

            fseek(archi,sizeof(stPelicula)*-1,SEEK_CUR);

            fwrite(&aux,sizeof(stPelicula),1,archi);

        }

        fclose(archi);
    }
    else
    {
        printf("Error con el archivo \n");
    }
}

void mostrarDireccion(stDireccion aux)
{
    puts("-----------------DIRECCION---------------------- \n");
    printf("El id es: %i \n",aux.idDireccion);
    printf("El nombre es: %s \n",aux.nombre);
    printf("El apellido es: %s \n",aux.apellido);
    printf("La cantidad de premios son: %i \n",aux.cantPremios);
    printf("La cantidad de pelis dirigidas son: %i \n",aux.cantPelisDirigidas);

}

void mostrarPelicula(stPelicula aux)
{

    puts("-----------------PELICULA---------------------- \n");
    printf("El id es: %i \n",aux.idPelicula);
    printf("El nombre es: %s \n",aux.nombre);
    printf("Los minutos que dura son: %i \n",aux.minutosDuracion);
    printf("El genero es: %s \n",aux.genero);
    printf("El tipometraje es: %i \n",aux.tipoMetraje);
    printf("El pais es: %s \n",aux.pais);
    printf("El IDdireccion es: %i \n",aux.idDireccion);



}

void mostrarArchivoPeliculas(char archivoPel[])
{
    FILE * archi= fopen(archivoPel,"rb");

    stPelicula aux;

    puts("--------------------PELICULAS-----------------\n");

    if(archi != NULL)
    {
        while(fread(&aux,sizeof(stPelicula),1,archi) > 0)
        {
            mostrarPelicula(aux);


        }
        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");
    }

    puts("----------------------------------------------\n");


}

void mostrarArchivoDireccionUNO(char archivoDir[])
{
    FILE * archi= fopen(archivoDir,"rb");

    stDireccion aux;

    if(archi != NULL)
    {
        while(fread(&aux,sizeof(stDireccion),1,archi) > 0)
        {
            mostrarDireccion(aux);
        }
        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");
    }




}

void mostrarTodasLasDirecciones(char archivoDirBuenos[], char archivoDirMalos[])
{
    puts("--------------------DIRECCIONES-----------------\n");
    puts("Directores Buenos: \n\n");
    mostrarArchivoDireccionUNO(archivoDirBuenos);

    puts("Directores Malos: \n\n");
    mostrarArchivoDireccionUNO(archivoDirMalos);
    puts("----------------------------------------------\n");

}


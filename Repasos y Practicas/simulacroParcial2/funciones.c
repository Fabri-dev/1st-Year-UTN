#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define FILAS 4
#define COLUMNAS 4


void menu(char archivoPacientes[], float mat[FILAS][COLUMNAS], float arregloPromedio[])
{
    char op='s';
    int opsw;
    int dato=0,validos=0, cant=0,comprobacion=0;

    while(op=='s')
    {

        puts("-------------Parcial------------------\n");
        puts("1.Cargar un paciente a archivo");
        puts("Ejercicio 2 \n");
        puts("Ejercicio 3 \n");

        printf("Elija un ejercicio: \n");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            cargarArchivoPacientes(archivoPacientes);
            break;
        case 2:
            dato=cantPacientesFemeninos(archivoPacientes);
            printf("La cantidad de pacientes femeninos con dni mayor a 40 millones es: %i\n", dato);
            break;
        case 3:
            cant=contarRegistros(archivoPacientes);

                printf("Ingrese a partir de que paciente quiere mostrar: \n");
                dato = preguntarDato();


            mostrarArchivoPacientesXdato(archivoPacientes,dato);


            break;
        default:
            break;

        }

        printf("Desea elegir otro ejercicio? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }

}


Paciente crearPaciente()
{
    Paciente aux;

    puts("------------Cargando un paciente-------------\n");
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(&aux.nombre);
    printf("Ingrese el dni: ");
    scanf("%i",&aux.dni);
    printf("Ingrese la direccion: ");
    fflush(stdin);
    gets(aux.direccion);
    printf("Ingrese el sexo: ");
    fflush(stdin);
    scanf("%c",&aux.sexo);

    return aux;
}

void cargarArchivoPacientes(char archivo[])
{
    char op='s';
    Paciente aux;

    FILE * archi=fopen(archivo,"ab");

    if(archi != NULL)
    {
        while(op=='s')
        {
            aux=crearPaciente();
            fwrite(&aux,sizeof(Paciente),1,archi);

            printf("Desea seguir cargando pacientes? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
        }
        fclose(archi);

    }
    else
    {
        printf("Error con el archivo");
    }

}

int cantPacientesFemeninos(char archivo[])
{
    Paciente aux;
    int contador=0, maximo=40000000;

    FILE*archi=fopen(archivo,"rb");

    if(archi!= NULL)
    {
        while((fread(&aux,sizeof(Paciente),1,archi)) > 0)
        {
            if ( aux.dni > maximo)
            {
                contador+= 1;
            }
        }
        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");
    }


    return contador;
}




void cargarMatriz(float mat[FILAS][COLUMNAS])
{
    int dato=0;
    for (int i=0; i < FILAS; i++)
    {
        for (int j=0; j< COLUMNAS; j++)
        {
            printf("pos[%i][%i]= ", i, j);
            scanf("%i",&dato);
            mat[i][j]=dato;
        }
    }
    printf("Fin de matriz");


}

int valorPromedioFilaMatriz(float mat[FILAS][COLUMNAS], float arr[])
{
    float cont=0;
    int k=0;
    for (int i=0; i < FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            cont= mat[i][j];
        }
        arr[k]=cont/ COLUMNAS;
        cont =0;
        k++;
    }
    return k;

}

void mostrarArreglo(float arr[],int validos)
{
    for (int i=0; i < validos; i++)
    {

        printf("Promedio de la fila %i es: %i \n", i, arr[i]);
    }
}


int preguntarDato()
{
    int dato=0;
    printf("Ingrese un dato: ");
    scanf("%i",&dato);
    return dato;

}

void mostrarPaciente(Paciente aux)
{
    printf("--------------PACIENTE--------------------\n");
    printf("DNI: %i \n",aux.dni);
    printf("Nombre: %s \n",aux.nombre);
    printf("Direccion: %s \n",aux.direccion);
    printf("Sexo: %c \n", aux.sexo);
    printf("-------------------------------------------\n");

}

int contarRegistros(char archivo[])
{
    FILE*archi=fopen(archivo,"rb");
    int cantidadRegistros=0;

    if( archi != NULL)
    {
        fseek(archi,sizeof(Paciente)-1,SEEK_END);
        cantidadRegistros= ftell(archi) / sizeof(Paciente);
        fclose(archi);
    }
    else
    {
        printf("Error con el archivo \n");
    }
    return cantidadRegistros;
}

void mostrarArchivoPacientesXdato(char archivo[], int dato)
{
    int cantRegistros= contarRegistros(archivo);
    Paciente aux;

    FILE* archi=fopen(archivo,"rb");

    if(archi != NULL)
    {
        fseek(archi,sizeof(Paciente)-1,dato);
        while(fread(&aux,sizeof(Paciente),1,archi)>0)
        {
            mostrarPaciente(aux);
        }

        fclose(archi);
    }
    else
    {

        printf("Error con el archivo \n");
    }



}


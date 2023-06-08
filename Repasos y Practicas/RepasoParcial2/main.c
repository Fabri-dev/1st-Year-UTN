#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int FILAS=4;
const int COLUMNAS=4;
const int MAXCAR=30;

typedef struct
{
    int idSocio;
    char nombreYapellido[30];
    int categoria; // puede tomar los valores de 1,2,3 o 4
    int edad;

}socio;


void menu(int mat[][COLUMNAS], char archivo[] ,socio arreglo[]);
float promedioMatriz(int mat[][COLUMNAS]);
socio cargarUnSocio();
void cargarSociosArchivo(char archivo[]);
int preguntarDato();
float edadPromedioXCat(char archivo[], int categ);
int contarRegistros(char archivo[]);
void mostrarSocio(socio aux);
void mostrarDeterminadoSocio(char archivo[], int busqueda);
int archivoToArregloXcat(socio arr[],char archivo[],int dato);
int buscarNombreSocio(char archivo[], char nombreBuscado[]);


int main()
{
    int matriz[4][4]={{2,7,9,5},{8,3,7,5},{9,6,5,3},{2,4,2,5}};

    char archivo[]="Socios";

    socio arreglo[30];

    menu(matriz,archivo,arreglo);


    return 0;
}

void menu(int mat[][COLUMNAS], char archivo[] ,socio arreglo[])
{
    char op;
    int opsw;


    char nombreBuscado[MAXCAR];
    int dato=0, validos=0;
    float prom;



    do
    {
        printf("EVALUACION :)  \n");
        printf("Ejercicio 1 \n");
        printf("Ejercicio 2 \n");
        printf("Ejercicio 3 \n");
        printf("Ejercicio 4 \n");
        printf("Ejercicio 5 \n");
        printf("Ejercicio 6 \n");
        printf("Ejercicio 7 \n");
        printf("Ejercicio 8 \n");


        printf("Que ejercicio desea elegir? ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
        prom= promedioMatriz(mat);
        printf("El promedio de la matriz es: %.2f \n",prom);
            break;
        case 2:

            cargarSociosArchivo(archivo);

            break;
        case 3:

            printf("Ingrese la categoria de la que quiere buscar la edad promedio: \n");
            dato= preguntarDato();
            prom= edadPromedioXCat(archivo,dato);
            printf("El promedio de edad de la categoria %i es: %.2f",dato,prom);
            break;
        case 4:
            dato= contarRegistros(archivo);
            printf("La cantidad de registros es de: %i",dato);
            break;
        case 5:

            printf("Ingrese el socio quiere buscar: \n");
            dato=preguntarDato();
            mostrarDeterminadoSocio(archivo,dato);
            break;
        case 6:
            printf("Ingrese que categoria quiere pasar al arreglo: \n");
            dato= preguntarDato();
            validos=archivoToArregloXcat(arreglo,archivo,dato);
            printf("La cantidad de socios que hay de la categoria %i es: %i",dato,validos);
            break;
        case 7:
            puts("-----------------ARREGLO DE SOCIOS---------------\n");
            mostrarArregloSocios(arreglo,validos);
            break;
        case 8:
            printf("Ingrese el nombre que busca en el archivo de socios: ");
            fflush(stdin);
            gets(&nombreBuscado);
            dato= buscarNombreSocio(archivo,nombreBuscado);
            if (dato != -1)
            {
                printf("Socio encontrado :) \n");
                printf("El IDsocio de %s es: %i",nombreBuscado,dato);
            }
            else
            {
                printf("ERROR: nombre no encontrado");
            }
            break;
        default:
            printf("ERROR: Ingrese un ejercicio valido");
            break;
        }

        printf("\nDesea elegir otro ejercicio? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");
    }while(op=='s');





}

float promedioMatriz(int mat[][COLUMNAS])
{
    float prom, sum;

    int cantidad= FILAS * COLUMNAS;

    printf("numero de elementos: %i \n",cantidad);

    for (int i=0;i<FILAS;i++)
    {
        for (int j=0;j<COLUMNAS;j++)
        {
            sum+= mat[i][j];
        }
    }

    prom=sum/cantidad;

    return prom;
}

socio cargarUnSocio()
{
    socio aux;

    printf("Ingrese el nombre y apellido del socio: \n");
    fflush(stdin);
    gets(&aux.nombreYapellido);
    printf("Ingrese el ID del socio: ");
    scanf("%i",&aux.idSocio);
    printf("Ingrese la categoria del socio: ");
    scanf("%i",&aux.categoria);
    printf("Ingrese la edad del socio: ");
    scanf("%i",&aux.edad);

    return aux;
}


void cargarSociosArchivo(char archivo[])
{

    char op='s';
    socio aux;
    FILE * archi;

    archi= fopen(archivo,"ab");

    if (archi != NULL)
    {
        while(op=='s')
        {
            printf("CARGANDO UN SOCIO: \n");
            aux= cargarUnSocio();
            fwrite(&aux,sizeof(socio),1,archi);

            printf("Desea seguir cargando socios al archivo? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
        }

        fclose(archi);
    }
    else
    {
        printf("ERROR CON EL ARCHIVO");
    }


}

int preguntarDato()
{
    int aux;
    printf("Ingrese un dato: ");
    scanf("%i",&aux);
    return aux;
}


float edadPromedioXCat(char archivo[], int categ)
{
    int sum=0,cantidad=0;
    socio aux;
    float prom=0;

    FILE * archi;
    archi=fopen(archivo,"rb");

    if (archi != NULL)
    {
        while(fread(&aux,sizeof(socio),1,archi) > 0)
        {
            if(aux.categoria == categ)
            {
                sum= aux.edad;
                cantidad++;
            }

        }


        fclose(archi);
    }
    else
    {
        printf("ERROR");
    }


    prom=(float) sum/cantidad;
    return prom;

}

int contarRegistros(char archivo[])
{
    socio aux;
    int tam=0;


    FILE * archi;

    archi=fopen(archivo,"rb");

    if(archi!= NULL)
    {
        fseek(archi,sizeof(socio)-1,SEEK_END);
        tam=ftell(archi)/sizeof(socio);
        fclose(archi);
    }
    else
    {
        printf("ERROR");
    }

    return tam;

}

void mostrarSocio(socio aux)
{
    puts("\n---------SOCIO-----------\n");
    printf("El nombre del socio es: %s \n",aux.nombreYapellido);
    printf("El ID es: %i \n",aux.idSocio);
    printf("La categoria es: %i \n",aux.categoria);
    printf("La edad es: %i \n",aux.edad);
    puts("------------------------------------\n");



}

void mostrarDeterminadoSocio(char archivo[], int busqueda)
{
    socio aux;
    int tam=contarRegistros(archivo);
    busqueda-=1;

    FILE* archi;

    archi=fopen(archivo,"rb");

    if (archi != NULL)
    {
        if(busqueda < tam)
        {

            fseek(archi,sizeof(socio)*busqueda,SEEK_SET);
            fread(&aux,sizeof(socio),1,archi);
            printf("\nBusqueda exitosa :) \n");
            mostrarSocio(aux);

        }
        else
        {
            printf("Dato no existente \n");
        }




        fclose(archi);
    }
    else
    {
        printf("ERROR \n");
    }



}

void mostrarArregloSocios(socio arr[], int validos)
{
    for(int i=0; i < validos; i++)
    {
        mostrarSocio(arr[i]);
    }

}

int archivoToArregloXcat(socio arr[],char archivo[],int dato)
{
    int i=0;
    socio aux;
    FILE * archi;

    archi=fopen(archivo,"rb");

    if(archi != NULL)
    {

        while(fread(&aux,sizeof(socio),1,archi)>0)
        {
            if(aux.categoria == dato)
            {

                arr[i]=aux;
                i++;
            }

        }



        fclose(archi);
    }
    else
    {
        printf("ERROR");
    }





    return i;
}

int buscarNombreSocio(char archivo[], char nombreBuscado[])
{
    socio aux;
    int flag=0;

    FILE * archi;

    archi= fopen(archivo,"rb");

    if(archi != NULL)
    {
        while(fread(&aux,sizeof(socio),1,archi)>0)
        {
            if(strcmp(aux.nombreYapellido,nombreBuscado)==0)
            {
                return aux.idSocio;
            }
        }


        fclose(archi);
    return -1;
    }
    else
    {
        printf("ERROR\n");
    }

}































































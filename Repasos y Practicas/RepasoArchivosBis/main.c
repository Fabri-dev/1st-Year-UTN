#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXDIM=50;

typedef struct
{
    int idPelicula;
    char nombrePelicula[30];
    char director[20];
    char genero[20];
    char pais[20];
    int anio;
    int valoracion;
    int pm;      // (0- si es ATP / 13: mayor de trece /
    //16: mayor de 16 / 18: mayor de 18

    int eliminado;   // indica 1 o 0 si la película fue eliminada
} stPelicula;








void menu(char archivo[]);
stPelicula crearPelicula(int * IDpeli);
void eliminarPelicula(stPelicula *pelicula);
void cargarPeliArchivo(char archivo[], int*IDpeli);
void mostrarPelicula(stPelicula aux);
int preguntarDato();
void modificarPelicula(stPelicula * aux);






int main()
{

    char archivo[30]="Peliculas";

    menu(archivo);



    return 0;
}


void menu(char archivo[])
{
    int IDpeli=0;



    char op='s';
    int opsw;


    while(op=='s')
    {

        switch(opsw)
        {
        case 1:

            cargarPeliArchivo(archivo,&IDpeli);


            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;


        }


        printf("Quiere volver a elegir? s/n");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }






}

stPelicula crearPelicula(int * IDpeli)
{
    stPelicula aux;

    aux.idPelicula= *IDpeli;
    printf("Ingrese el nombre de la pelicula: \n");
    fflush(stdin);
    gets(aux.nombrePelicula);
    printf("Ingrese el director: \n");
    fflush(stdin);
    gets(aux.director);
    printf("Ingrese el genero: \n");
    fflush(stdin);
    gets(aux.genero);
    printf("Ingrese el pais de la pelicula: \n");
    fflush(stdin);
    gets(aux.pais);
    printf("Ingrese el anio en la que se publico: ");
    scanf("%i",&aux.anio);
    printf("Ingrese la valoracion: ");
    scanf("%i",&aux.valoracion);

    /// poner para que solo se puedan ingresar esos valores


    printf("Ingrese la clasificacion: (0 para ATP)(13 para mayores de 13)(16 para mayores de 16)(18 para mayores de 18)");
    scanf("%i",&aux.pm);


    aux.eliminado=0;

    *IDpeli+=1;

    return aux;

}


void eliminarPelicula(stPelicula *pelicula)
{

    pelicula->eliminado=1;

    printf("Pelicula Eliminada \n");
}



void cargarPeliArchivo(char archivo[], int*IDpeli)
{
    char op='s';

    stPelicula aux;

    FILE * archi;

    if ((archi=fopen(archivo,"ab")) != NULL)
    {

        while(op=='s')
        {
            aux= crearPelicula(IDpeli);

            fwrite(&aux,sizeof(stPelicula),1,archi);

            mostrarPelicula(aux);

            printf("Quiere volver a elegir? s/n");
            fflush(stdin);
            scanf("%c",&op);
            system("cls");


        }
        fclose(archi);
    }
    else
    {
        printf("ERROR");
    }


}

void mostrarPelicula(stPelicula aux)
{
    puts("---------------------PELICULA-------------------------");
    printf("El ID es: %i \n",aux.idPelicula);
    printf("El nombre es: %s \n",aux.nombrePelicula);

    printf("El director es: %s \n",aux.director);

    printf("El genero es: %s \n",aux.genero);

    printf("El pais en la que se filmo es: %s \n",aux.pais);

    printf("El anio en la que se publico es: %i \n",aux.anio);

    printf("La valoracion es: %i \n",aux.valoracion);

    printf("La clasificacion es: %i \n",aux.pm);

    aux.eliminado ? printf("La pelicula esta elimianda") : printf("La pelicula se encuentra disponible");


}

//FUNCION MOSTRAR TODAS LAS PELICULAS :









int preguntarDato()
{
    int dato=0;
    printf("Ingrese un dato: ");
    scanf("%i",&dato);

    return dato;
}



void modificarPelicula(stPelicula * aux)
{
    char op='s';
    int opsw;

    while(op=='s')
    {

        puts("\t\t PELICULA ELEGIDA\n");
        mostrarPelicula(*aux);

        puts("\n-----------QUE CAMPO QUIERE MODIFICAR?------------\n");


        printf("1.Nombre \n");
        printf("2.Director \n");
        printf("3.Genero \n");
        printf("4.Pais \n");
        printf("5.Anio \n");
        printf("6.Valoracion \n");
        printf("7.Clasificacion(PM) \n");
        printf("8.Todo \n");

        printf("\n");
        opsw= preguntarDato();


        switch(opsw)
        {
        case 1:
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(aux->nombrePelicula);
            break;
        case 2:
            printf("Ingrese el nuevo director: ");
            fflush(stdin);
            gets(aux->director);
            break;
        case 3:
            printf("Ingrese el nuevo genero: ");
            fflush(stdin);
            gets(aux->genero);
            break;
        case 4:
            printf("Ingrese el nuevo pais: ");
            fflush(stdin);
            gets(aux->pais);
            break;
        case 5:
            printf("Ingrese el nuevo anio: ");
            scanf("%i",aux->anio);
            break;
        case 6:
            printf("Ingrese la nueva valoracion: ");
            scanf("%i",aux->valoracion);
            break;
        case 7:
            printf("Ingrese la nueva clasificacion: ");
            scanf("%i",aux->pm);
            break;
        case 8:
            printf("Ingrese todos los datos nuevos: \n");
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(aux->nombrePelicula);
            printf("Ingrese el nuevo director: ");
            fflush(stdin);
            gets(aux->director);
            printf("Ingrese el nuevo genero: ");
            fflush(stdin);
            gets(aux->genero);
            printf("Ingrese el nuevo pais: ");
            fflush(stdin);
            gets(aux->pais);
            printf("Ingrese el nuevo anio: ");
            scanf("%i",aux->anio);
            printf("Ingrese la nueva valoracion: ");
            scanf("%i",aux->valoracion);
            printf("Ingrese la nueva clasificacion: ");
            scanf("%i",aux->pm);
            break;
        default:
            printf("ERROR: ingrese un numero valido\n");
            break;
        }

        printf("\n------------------PELICULA MODIFICADA--------------------\n");
        mostrarPelicula(*aux);


        printf("Desea seguir modificando? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }

}













































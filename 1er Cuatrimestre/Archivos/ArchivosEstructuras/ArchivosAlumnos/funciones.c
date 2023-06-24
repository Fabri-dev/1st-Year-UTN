#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "prototipados.h"


void cargarArchivoPrim(char archivo[])
{
    FILE * archi; // Puntero al archivo para no trabajar con el archivo directamente (BUFFER)

    archi= fopen(archivo,"ab"); // Abro el archivo y elijo el modo

    int b=0;

    if (archi != NULL) // si el archivo no tuvo ningun problema para abrir
    {
        //contenido

        printf("Ingrese un valor para guardar: ");
        scanf("%i", &b);  //doy un valor a la variable para ingresar en el BUFFER


        // le paso la direccion de memoria de la variable b (que es de tamanio int)para que esta sea leida y cargada al BUFFER
        fwrite(&b,sizeof(int),1,archi);

        // cierro el archivo dentro del IF ya que si el archivo no existe para que lo voy a cerrar?
        fclose(archi);
    }


}

void mostrarArchivoPrim(char archivo[])
{
    FILE * archi;

    archi= fopen(archivo,"rb");

    int b=0,i=0;

    if (archi!= NULL)
    {
        while(!feof(archi))
        {

            fread(&b,sizeof(int),1,archi);
            if(!feof(archi))
            {

            printf("Numero %i = %i \n",i,b);
            }

            i++;
        }

        fclose(archi);
    }

}

int contarRegistrosPrim(char archivo[])
{
    FILE * archi;

    int cantidad;

    if ((archi=fopen(archivo,"rb") != NULL))
    {
        fseek(archi,sizeof(int),SEEK_END);
        cantidad= ftell(archi)/ sizeof(int);
    }
    return cantidad;
}


stAlumno cargarAlumno()
{
    stAlumno aux;


        printf("\nIngrese el nombre y apellido del alumno: ");
        fflush(stdin);
        gets(&aux.nombreYapellido);
        printf("Ingrese la edad del alumno: ");
        scanf("%i",&aux.edad);
        printf("Ingrese el anio en el que se encuentra: ");
        scanf("%i",&aux.anio);
        printf("Ingrese el nro. de legajo: ");
        scanf("%i",&aux.legajo);
        printf("\n");

    return aux;
}

void cargarArchivoAlumnos(char archivo[])
{
    char op='s', opArch;
    stAlumno alumno;

    FILE * archi;



    if((archi=fopen(archivo, "rb")) != NULL)
    {
        printf("El archivo ya esta creado, quiere sobrescrbirlo? s/n \n");
        fflush(stdin);
        scanf("%c",&opArch);
        fclose(archi);
        if(opArch == 's')
        {
            archi=fopen(archivo,"wb");

            while(op=='s')
        {
            alumno= cargarAlumno();
            printf("Desea seguir cargando? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
            fwrite(&alumno,sizeof(stAlumno),1,archi);
        }

        fclose(archi);


        }
        else
        {
            archi= fopen(archivo,"ab");

            while(op=='s')
        {
            alumno= cargarAlumno();
            printf("Desea seguir cargando? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
            fwrite(&alumno,sizeof(stAlumno),1,archi);
        }

        fclose(archi);
        }
    }


}

void mostrarAlumno(stAlumno alumno)
{
    puts("------------------------ALUMNO------------------------------");
    printf("El nombre y apellido del alumno es: %s \n", alumno.nombreYapellido);
    printf("La edad es: %i \n", alumno.edad);
    printf("El anio en el que se encuentra es: %i \n", alumno.anio);
    printf("El legajo es: %i \n",alumno.legajo);
    puts("------------------------------------------------------------\n");

}

void mostrarArchivo(char archivo[])
{
    FILE * archi;

    stAlumno alumno;

    archi= fopen(archivo,"rb");

    if (archi!= NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                mostrarAlumno(alumno);
            }
        }
    fclose(archi);
    }
}

void pasarAPilaLegajos(char archivo[], Pila* pilaLegajos)
{
    FILE * archi;

    archi= fopen(archivo,"rb");

    stAlumno alumno;

    int mayorEdad=18;

    if (archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno,sizeof(stAlumno),1,archi);

            if(!feof(archi))
            {
                if (alumno.edad >= mayorEdad)
                {
                apilar(pilaLegajos, alumno.legajo);
                }
            }
        }
        fclose(archi);
    }
    else
    {
        printf("Error: archivo corrupto");
    }

}

int preguntarDato()
{
    int dato;
    printf("Ingrese un dato: ");
    scanf("%i", &dato);

    return dato;
}

int contarAlumnosXDato(char archivo[], int dato)
{
    FILE* archi;

    archi= fopen(archivo,"rb");

    stAlumno alumno;
    int i=0;

    if (archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno,sizeof(stAlumno),1,archi);
            if(!feof(archi))
            {
                if(alumno.edad>dato)
                {
                    i++;

                }
            }
        }
        fclose(archi);
    }
    else
    {
        printf("archivo corrompido");
    }

    return i;
}

void mostrarRangoEdad(char archivo[], int desde, int hasta)
{
    FILE * archi;

    archi= fopen(archivo,"rb");

    stAlumno alumno;

    if (archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&alumno, sizeof(stAlumno),1, archi);
            if(!feof(archi))
            {
                if (alumno.edad >= hasta && alumno.edad <= desde)
                {
                    mostrarAlumno(alumno);
                }
            }
        }
        fclose(archi);
    }

}

stAlumno mostrarMayorEdad(char archivo[])
{
    FILE * archi;

    stAlumno alumno, alumnoMayor;

    archi= fopen(archivo, "rb");

    if(archi != NULL)
    {
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0)
        {
                if(alumnoMayor.edad < alumno.edad)
                {
                    alumnoMayor= alumno;
                }
        }

            fclose(archi);
    }
        return alumnoMayor;
}

int cantAlumnosXanio(char archivo[], int dato)
{
    FILE* archi;

    archi=fopen(archivo,"rb");

    stAlumno alumno;

    int i=0;

    if(archi != NULL)
    {
        while(fread(&alumno,sizeof(alumno),1,archi)>0)
        {
            if(dato == alumno.anio)
            {
                i++;
            }
        }
        fclose(archi);
    }
    return i;
}

int cargarArregloAlumno(stAlumno arr[])
{
    char op='s';
    int i=0;

    while(op=='s')
    {
        arr[i]= cargarAlumno();
        i++;
        printf("Desea agregar mas alumnos? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    return i;
}

void arregloToArchivo(char archivo[], stAlumno arr[], int validos)
{
    FILE * archi;

    archi= fopen(archivo, "wb");

    if(archi != NULL)
    {
        for (int i=0; i < validos; i++)
        {
            fwrite(&arr[i],sizeof(stAlumno),1,archi);
        }
        fclose(archi);
    }
}

void archivoToArregloConCondicion(char archivo[], stAlumno arrAnio[], int dato ,int validos)
{
    FILE * archi;

    archi= fopen(archivo, "rb");

    stAlumno alumno;

    int i=0;

    if(archi != NULL)
    {
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0)
        {
            if (alumno.anio == dato)
            {
                arrAnio[i]=alumno;
                i++;
            }
        }
        fclose(archi);
    }


}

void mostrarArregloAlumnos(stAlumno arr[], int validos)
{
    for (int i=0;i<validos; i++)
    {
        mostrarAlumno(arr[i]);
    }
}

int contarCantidadDeRegistros(char archivo[])
{
    FILE* archi;

    int cantRegistros=0;

    if((archi=fopen(archivo,"rb"))!= NULL)
        {
            fseek(archi,sizeof(stAlumno),SEEK_END);
            cantRegistros= ftell(archi)/sizeof(stAlumno) -1;

            fclose(archi);
        }

    return cantRegistros;
}

void mostrarPorDato(char archivo[])
{
    FILE * archi;
    int dato=0;
    stAlumno b;

    printf("Ingrese una posicion entre 1 y 9\n");
    dato=preguntarDato()-1;
    if (dato > 0 && dato < 9 )
    {


        if((archi=fopen(archivo,"rb")) != NULL)
        {
            fseek(archi,sizeof(stAlumno)*dato,SEEK_SET);
            fread(&b,sizeof(stAlumno),1,archi);
        }
        mostrarAlumno(b);
        fclose(archi);
    }
    else
    {
        printf("Error ingrese una posicion entre el 1 y 9 !!!");
    }

}

void modificarArchivo(char archivo[], int dato)
{
    FILE * archi;

    archi=fopen(archivo,"r+b");

    int cantRegistro= contarCantidadDeRegistros(archivo);

    stAlumno b;

    if (archi != NULL)
    {
        if(dato >= 0 && dato < cantRegistro)
        {

            fseek(archi,sizeof(stAlumno)*dato,SEEK_SET);
            fread(&b,sizeof(stAlumno),1,archi);
            modificarAlumno(&b);
            fseek(archi,sizeof(stAlumno)*-1,SEEK_CUR);
            fwrite(&b,sizeof(stAlumno),1,archi);

        }
        else
        {
            printf("ERROR POSICION INVALIDA");
        }


        fclose(archi);
    }

}

void modificarAlumno(stAlumno* modificado)
{
    int op=0;

    system("cls");


    puts("\n------------------ALUMNO ELEGIDO------------------------");
    mostrarAlumno(*modificado);

    printf("\n\n");


    printf("1. Modificar nombre y apellido \n");
    printf("2. Modificar edad \n");
    printf("3. Modificar anio \n");
    printf("4. Modificar legajo \n");
    printf("5. Modificar alumno entero \n");

    printf("\n");
    printf("Ingrese que quiere modificar: ");
    scanf("%i", &op);


    switch(op)
    {
    case 1:
        printf("Ingrese el nuevo nombre:");
        fflush(stdin);
        gets(modificado->nombreYapellido);
        break;
    case 2:
        printf("Ingrese la nueva edad: \n");
        scanf("%i",&modificado->edad);
        break;
    case 3:
        printf("Ingrese el nuevo anio: \n");
        scanf("%i",&modificado->anio);
        break;
    case 4:
        printf("Ingrese el nuevo legajo: \n");
        scanf("%i",&modificado->legajo);
        break;
    case 5:
        printf("Ingrese todos los datos nuevos del alumno: \n");
        (*modificado) = cargarAlumno();
        break;
    default:
        printf("Ingrese una opcion valida !!!");
        break;

    }

    puts("---------------------ALUMNO MODIFICADO------------------------");
    mostrarAlumno(*modificado);

}

void invertirElementosArchivo(char archivo[])
{
    FILE * archi;

    archi=fopen(archivo,"r+b");

    int i=0,j=contarCantidadDeRegistros(archivo)-1;



    stAlumno aux1,aux2;




    if(archi != NULL)
    {
        while(i <= j)
        {
            //Guardo las variables aux1 y aux2

            fseek(archi,sizeof(stAlumno)*i,SEEK_SET);
            fread(&aux1,sizeof(stAlumno),1,archi);
            fseek(archi,sizeof(stAlumno)*j,SEEK_SET);
            fread(&aux2,sizeof(stAlumno),1,archi);

            // las sobreescribo
            fseek(archi,sizeof(stAlumno)*j,SEEK_SET);
            fwrite(&aux1,sizeof(stAlumno),1,archi);
            fseek(archi,sizeof(stAlumno)*i,SEEK_SET);
            fwrite(&aux2,sizeof(stAlumno),1,archi);

            // aumento y disminuyo los respectivos contadores

            i++;
            j--;



        }
        fclose(archi);
    }
    else
    {
        printf("Error con archivo");
    }








}





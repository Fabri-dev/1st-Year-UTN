#include <stdio.h>
#include <stdlib.h>

void cargarArchivo(char archivo[]);
void mostrarArchivo(char archivo[]);










int main()
{
    char archivo1[]="ArchivoPrueba"; // le pongo nombre al archivo

    cargarArchivo(archivo1);
    cargarArchivo(archivo1);
    mostrarArchivo(archivo1);



    return 0;
}


void cargarArchivo(char archivo[])
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

void mostrarArchivo(char archivo[])
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

int contarRegistros(char archivo[])
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






























#include <stdio.h>
#include <stdlib.h>

int BuscarPosMenor(int arr[], int validos, int PosInicial);
void OrdenamientoSeleccion( int arr[], int validos);
int CargarArregloDevolverValidos(int arr[],int dimension);
void MostrarArreglo(int arr[], int validos);
void ordenamientoInsercion(int arr[], int validos);
void insertar(int arr[], int validos, int num);



int main()
{
    int op;
    int arreglo[30];
    int dimension= 30;
    printf("Cargar Arreglo\n");
    int validos= CargarArregloDevolverValidos(arreglo, dimension);
    printf("Elija su forma de ordenamiento: 1= seleccion, 2=insercion: ");
    scanf("%i", &op);


    switch(op){

    case 1:

    OrdenamientoSeleccion(arreglo, validos);
    MostrarArreglo(arreglo, validos);



        break;

    case 2:

    ordenamientoInsercion(arreglo, validos);
    MostrarArreglo(arreglo, validos);

        break;
    }



    return 0;
}





void insertar(int arr[], int validos, int num)
{
    int pos= validos;
    while (pos>= 0 && num < arr[pos])
    {
        arr[pos+1]= arr[pos];
        pos--;
    }
    arr[pos+1]= num;
}

void ordenamientoInsercion(int arr[], int validos ){
    int i= 0;
    while (i < validos -1)
    {
        insertar(arr,i,arr[i+1]);
        i++;
    }

}



int BuscarPosMenor(int arr[], int validos, int PosInicial)
{
    int PosMenor= PosInicial;
    for (int i=PosInicial; i< validos; i++)
    {
        if(arr[PosMenor] > arr[i])
        {
            PosMenor=i;
        }
    }
        return PosMenor;
}



void OrdenamientoSeleccion( int arr[], int validos)
{

    int i;
    for (i=0; i < validos ; i++)
    {

        int PosMenor= BuscarPosMenor(arr, validos, i);

        int aux= arr[i];
        arr[i]=arr[PosMenor];
        arr[PosMenor]= aux;

        printf("PosIn: %i , Validos: %i\n", i, validos);

    }
}

int CargarArregloDevolverValidos(int arr[],int dimension){
    int num, validos;
    char op='s';
    while(op=='s')
    {
        printf("Ingrese un valor al arreglo: ");
        fflush(stdin);
        scanf("%i", &arr[validos]);
        validos++;
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);
    }
    return validos;

}

void MostrarArreglo(int arr[], int validos){
    for (int i=0; i < validos; i++)
    {
        printf(" %i ", arr[i]);
    }
}

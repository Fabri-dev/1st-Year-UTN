#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

const int MAXDIM=30, MAXDIMFLOAT=100;
const int DIMCAR=30;

void menu(int arr[],Pila dada,float arrFloat[], char abecedario[], char arrCarateres[]);

int CargarArr_DevolverValidos(int arr[]);
void MostrarElementosArreglo(int arr[],int validos);
int SumaElementos(int arr[], int validos);
void CargarElementosAPila(int arr[],int validos, Pila* dada);
int CargarElementosConComa(float arr[]);
float SumaConComa(float arr[], int validos);
int BuscarCaracter(char arr[], char letra);
int cargarArrDeCaracteres(char arr[]);
void mostrarArregloDeCaracteres(char arr[], int validos);
void insertarCaracter(char arr[], int validos, char dato);
char LetraMax(char arr[], int validos);
int EsCapicua(int arr[], int validos);










int main()
{
    int arreglo[MAXDIM];
    Pila dada;
    inicpila(&dada);
    float arregloFloat[MAXDIMFLOAT];
    char Abecedario[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char arregloCaracteres[DIMCAR];



    menu(arreglo,dada,arregloFloat,Abecedario, arregloCaracteres);


    return 0;
}

void menu(int arr[],Pila dada,float arrFloat[], char abecedario[], char arrCaracteres[])
{
    char op;
    int opsw;
    int validos=0,suma=0, validosFloat=0, validosChar=0;
    char letra;
    float sumaFloat=0;
    do
    {
        printf("MENU EJERCICIOS \n");
        printf("1. Cargar arreglo \n");
        printf("2. Mostrar arreglo \n");
        printf("3. Sumar todos los elementos del arreglo \n");
        printf("4. Arreglo to pila\n");
        printf("5. Sumar todos los elementos de un arreglo float\n");
        printf("6. Indicar si un caracter se encuentra en un arreglo o no \n");
        printf("7. Insertar un caracter en un arreglo ordenado alfabeticamente \n");
        printf("8. Obtener el maximo caracter en un arreglo \n");
        printf("9. Determinar si un arreglo es capicua \n");
        printf("10. Invertir elementos de un arreglo \n");
        printf("11. Ordenar un arreglo por insercion \n");
        printf("13. Ordenar un arreglo por seleccion \n");
        printf("14. Ordenar dos arreglos en otro arreglo mas grande \n");
        printf("15. Suma de un vector \n");





        printf("\nIngrese que ejercicio quiere ejecutar: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            validos= CargarArr_DevolverValidos(arr);
            printf("Los validos del arreglo son: %i \n",validos);
            break;
        case 2:
            printf("ARREGLO: \n");
            MostrarElementosArreglo(arr,validos);

            break;
        case 3:
            suma= SumaElementos(arr,validos);
            printf("La suma de todos los elementos del arreglo es: %i \n",suma);
            break;
        case 4:
            printf("ARREGLO: \n");
            MostrarElementosArreglo(arr,validos);
            printf("\nPASADOS A PILA: \n");
            CargarElementosAPila(arr,validos,&dada);
            mostrar(&dada);

            break;
        case 5:

            printf("CARGO ARREGLO DE NUMEROS REALES: \n");
            validosFloat= CargarElementosConComa(arrFloat);
            sumaFloat= SumaConComa(arrFloat,validosFloat);
            printf("La suma del arreglo de numeros reales es: %.3f",sumaFloat);
            break;
        case 6:

            printf("Ingrese la letra que quiere buscar en el arreglo: ");
            fflush(stdin);
            scanf("%c", &letra);
            BuscarCaracter(abecedario, letra) ? printf("La letra |%c| se encuentra en el arreglo",letra) : printf("La letra |%c| NO se encuentra en el arreglo",letra) ;

            break;
        case 7:
            validosChar= cargarArrDeCaracteres(arrCaracteres);
            printf("Ingrese la letra que quiere insertar: ");
            fflush(stdin);
            scanf("%c", &letra);
            insertarCaracter(arrCaracteres,validosChar,letra);
            mostrarArregloDeCaracteres(arrCaracteres,validosChar+1);

            break;
        case 8:
            validosChar= cargarArrDeCaracteres(arrCaracteres);
            letra=LetraMax(arrCaracteres,validosChar);
            printf("La letra mayor es: %c", letra);
            break;
        case 9:

            validos=CargarArr_DevolverValidos(arr);
            EsCapicua(arr,validos) ? printf("El arreglo es capicua") : printf("El arreglo NO es capicua");

            break;
        case 10:
            break;
        case 11:

            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        default:
            break;
        }

        printf("\nDesea elegir otro ejercicio? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");
    }while(op=='s');



}




int CargarArr_DevolverValidos(int arr[])
{
    char op;
    int i;
    do {
        printf("Ingrese un valor al arreglo: ");
        fflush(stdin);
        scanf("%d", &arr[i]);
        i++;
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);

    }while(op == 's' && i < MAXDIM);

    return i;
}

void MostrarElementosArreglo(int arr[],int validos)
{
    for (int i= 0; i < validos; i++)
    {
        printf("Arr posicion [%i] = %i \n", i, arr[i]);
    }
}

int SumaElementos(int arr[],int validos)
{
    int suma=0;

    for (int i= 0; i < validos; i++)
    {
        suma += arr[i];
    }
    return suma;
}

void CargarElementosAPila(int arr[],int validos, Pila* dada)
{
    for (int i= 0; i < validos; i++)
    {
        apilar(dada, arr[i]);
    }
}

int CargarElementosConComa(float arr[])
{
    char op='s';
    int i= 0;
    do
        {
            printf("Ingrese un valor con coma al arreglo: ");
            scanf("%f", &arr[i]);
            i++;
            printf("Desea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
        }while (op == 's' && i < MAXDIMFLOAT);


    return i;
}

float SumaConComa(float arr[], int validos)
{
    float suma;
    for (int i=0; i<validos; i++)
    {
        printf("%.3f \n", arr[i]);
        suma+= arr[i];
    }
    return suma;
}

int BuscarCaracter(char arr[], char letra)
{
    int i=0;
    while(i<DIMCAR)
    {
        if(arr[i] == letra)
        {
            return 1;
        }
        i++;
    }

    return 0;
}

int cargarArrDeCaracteres(char arr[])
{
    int i=0;
    char op='s';

    while(op=='s' && i < DIMCAR)
    {
        printf("Ingrese una letra al arreglo: ");
        fflush(stdin);
        scanf("%c", &arr[i]);

        i++;

        printf("Desea seguir cargando elementos? s/n: ");
        fflush(stdin);
        scanf("%c",&op);

    }

    return i;
}
void mostrarArregloDeCaracteres(char arr[], int validos)
{
    for(int i=0; i < validos; i++)
    {
        printf("arr[%i] = %c \n",i, arr[i]);
    }

}

void insertarCaracter(char arr[], int validos, char dato)
{
    int i=validos-1;

    while(i>=0 && arr[i] > dato)
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=dato;

    printf("DATO INSERTADO :) \n");
}


char LetraMax(char arr[], int validos)
{
    char max= 0;
    for (int i=0; i<validos; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int EsCapicua(int arr[], int validos)
{
    int inicio=0, finall= validos - 1;
    while(inicio != finall && inicio < finall)
    {
        if (arr[inicio] != arr[finall])
        {
            return 0;
        }
        inicio++;
        finall--;
    }
    return 1;

}









































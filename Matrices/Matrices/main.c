#include <stdio.h>
#include <stdlib.h>
#include <string.h>



const int FILAS= 3;
const int COLUMNAS= 3;
const int MAX_FILAS=10;
const int MAX_CHAR=30;



void cargarMatrizUsuario(int [FILAS][COLUMNAS]);
void mostrarMatriz(int [FILAS][COLUMNAS]);
void matrizAleatoria(int [FILAS][COLUMNAS]);
int sumarMatriz(int matriz[FILAS][COLUMNAS]);
int contarMatriz(int matriz[FILAS][COLUMNAS]);
float promedioMatriz(int matriz[FILAS][COLUMNAS]);
int buscarElemento(int matriz[FILAS][COLUMNAS], int dato);
int cargarMatrizString(char mat[][MAX_CHAR]);
void mostrarMatrizStrings(char mat[][MAX_CHAR], int validos);
int buscarString(char mat[][MAX_CHAR], int validos, char dato[]);
void insertar(char mat[][MAX_CHAR], int validos, char dato[]);
void ordxInsercion(char mat[][MAX_CHAR], int validos);
int buscarPosMenor(char mat[][MAX_CHAR], int pos, int validos);
void ordxSeleccion(char mat[][MAX_CHAR], int validos);


int main()
{
    srand(time(NULL));
    int matriz[FILAS][COLUMNAS];
    char matrizchar[MAX_FILAS][MAX_CHAR];



    //cargarMatrizUsuario(matriz);

    matrizAleatoria(matriz);
    mostrarMatriz(matriz);

    //int sum= sumarMatriz(matriz);
    //float prom= promedioMatriz(matriz);
    //printf("\nLa suma de todos los elementos de la matriz es: %i \n", sum);
    //printf("El promedio de la matriz es: %.2f \n", prom);

    //int dato=0;
    //printf("Ingrese el numero que quiere buscar: ");
    //scanf("%i", &dato);

    //buscarElemento(matriz, dato) ? printf("Num Encontrado :)") : printf("ERROR: Numero no encontrado :(");

    int validos2=cargarMatrizString(matrizchar);
    mostrarMatrizStrings(matrizchar,validos2);

    ordxSeleccion(matrizchar,validos2);

    mostrarMatrizStrings(matrizchar,validos2);
    return 0;

    }








void cargarMatrizUsuario(int matriz[FILAS][COLUMNAS])
{
    for (int i=0; i<FILAS; i++)
    {
        for (int j=0; j<COLUMNAS; j++)
        {
            printf("Ingrese un elemento para la posicion [%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[FILAS][COLUMNAS])
{
    for (int i=0; i<FILAS; i++)
    {
        printf("| ");
        for (int j=0; j<COLUMNAS; j++)
        {
            printf(" %i ", matriz[i][j]);
        }
        printf(" |\n");
    }


}

void matrizAleatoria(int matriz[FILAS][COLUMNAS])
{
    int numRand=0;

    for(int i=0; i<FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            numRand= rand()%15;
            matriz[i][j]= numRand;
        }
    }
}

int sumarMatriz(int matriz[FILAS][COLUMNAS])
{
    int sum=0;

    for (int i=0; i<FILAS; i++)
    {
        for (int j=0; j<COLUMNAS; j++)
        {
            sum += matriz[i][j];
        }
    }
    return sum;
}

int contarMatriz(int matriz[FILAS][COLUMNAS])
{
    int cont=0;
    for (int i=0; i< FILAS; i++)
    {
        for (int j=0; j<COLUMNAS; j++)
        {
            cont += 1;
        }
    }
    return cont;
}

float promedioMatriz(int matriz[FILAS][COLUMNAS])
{
    float suma= sumarMatriz(matriz);
    float cont= contarMatriz(matriz);
    float promedio= (float) suma / cont;
    return promedio;
}

int buscarElemento(int matriz[FILAS][COLUMNAS], int dato)
{
    int flag=0;
    for (int i=0; i<FILAS; i++)
    {
        for (int j=0; j<COLUMNAS; j++)
        {
            if (dato == matriz[i][j])
            {
                flag=1;
            }
        }
    }
    return flag;
}

int cargarMatrizString(char mat[][MAX_CHAR])
{
    int i=0;
    char op='s';

    while(i < MAX_FILAS && op=='s')
    {
        printf("Ingrese un string: ");
        scanf("%s", &mat[i]);
        i++;
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);
    }
    return i;
}

void mostrarMatrizStrings(char mat[][MAX_CHAR], int validos)
{
    for (int i=0; i < validos; i++)
    {
        printf("| %s | \n", mat[i]);
    }
}

int buscarString(char mat[][MAX_CHAR], int validos, char dato[])
{
    for (int i=0; i <validos; i++)
    {
        if (strcmp(mat[i],dato)==0)
        {
            return i;
        }
    }
    return -1;
}

/// ORDENAMIENTOS
//insercion

void insertar(char mat[][MAX_CHAR], int validos, char dato[])
{
    int i= validos-1;

    while(i>=0 && strcmp(mat[i],dato) > 0)
    {
        strcpy(mat[i+1], mat[i]);
        i--;
    }
    strcpy(mat[i+1], mat[i]);

}

void ordxInsercion(char mat[][MAX_CHAR], int validos)
{

    for (int i=0; i < validos -1; i++)
    {
        insertar(mat,i,mat[i+1]);

    }
}

//seleccion

int buscarPosMenor(char mat[][MAX_CHAR], int pos, int validos)
{
    int posMenor= 0;
    int i=pos;
    for (i; i< validos; i++)
    {
        if (strcmp(mat[i],mat[posMenor])<0)
        {
            posMenor=i;
        }
    }
    return posMenor;
}


void ordxSeleccion(char mat[][MAX_CHAR], int validos)
{
    char aux[MAX_CHAR];
    int posMenor=0;
    for (int i=0; i<validos;i++)
    {
        posMenor= buscarPosMenor(mat,i,validos);
        strcpy(aux,mat[posMenor]);
        strcpy(mat[posMenor],mat[i]);
        strcpy(mat[i], aux);
    }

}









#include <stdio.h>
#include <stdlib.h>
#include <string.h>



const int FILAS= 3;
const int COLUMNAS= 3;
const int MAX_FILAS=10;
const int MAX_CHAR=30;



void cargarMatrizUsuario(int [FILAS][COLUMNAS]);
void mostrarMatriz(int [][COLUMNAS]);
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
int determinanteMatriz2x2(int mat[2][2]);
void cargarMat2x2(int mat[2][2]);
void mostrar2x2(int mat[2][2]);
int verificar2x2Inversa(int mat[2][2]);
void cargarMat2x5(int mat[2][5]);
void multiplicacionMatrices(int mat2x2[2][2], int mat2x5[2][5], int matRes[2][5]);
void mostrarMatrices(int mat2x2[2][2], int mat2x5[2][5], int matRes[2][5]);
int calcularInversa(int mat2x2[2][2], int inversa[2][2]);
int esSimetrica(int mat[3][3]);





int main()
{
    srand(time(NULL));
    int matriz[FILAS][COLUMNAS];
    char matrizchar[MAX_FILAS][MAX_CHAR];
    int mat2x2[2][2], inversa2x2[2][2];

    int mat2x5[2][5], matProd[2][5];

    /*
    cargarMat2x2(mat2x2);
    mostrar2x2(mat2x2);
    calcularInversa(mat2x2, inversa2x2);
    mostrar2x2(inversa2x2);
    */

    cargarMatrizUsuario(matriz);
    esSimetrica(matriz)? printf("La matriz es simetrica :) ") : printf("La matriz NO es simetrica :( ");

    return 0;

}







///1:
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


///2:
void mostrarMatriz(int matriz[][COLUMNAS])
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


///3:
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


///4:
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


///5:
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


///6:
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


///7:
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


///8:
void mostrarMatrizStrings(char mat[][MAX_CHAR], int validos)
{
    for (int i=0; i < validos; i++)
    {
        printf("| %s | \n", mat[i]);
    }
}


///9:
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


///10: ORDENAMIENTOS
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
    for (int i=0; i<validos; i++)
    {
        posMenor= buscarPosMenor(mat,i,validos);
        strcpy(aux,mat[posMenor]);
        strcpy(mat[posMenor],mat[i]);
        strcpy(mat[i], aux);
    }

}


///12:
int determinanteMatriz2x2(int mat[2][2])
{
    int i=0, j=1;
    int diagPrin=1, diagSec=1;
    int det=0;

    while(i<2 && j>=0)
    {
        diagPrin *= mat[i][i];
        diagSec *= mat[j][i];
        i++;
        j--;
    }

    return det= diagPrin - diagSec;


}

void cargarMat2x2(int mat[2][2])
{
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            printf("Ingrese un valor a la posicion [%i][%i] de la matriz: ", i, j);
            scanf("%i", &mat[i][j]);
        }

    }

}

void mostrar2x2(int mat[2][2])
{
    for (int i=0; i<2; i++)
    {
        printf("|");
        for (int j=0; j<2; j++)
        {
            printf(" %i ", mat[i][j]);
        }
        printf("|\n");

    }
}


///13:
int verificar2x2Inversa(int mat[2][2])
{
    if (determinanteMatriz2x2(mat) == 0)
    {
        return 1;
    }
    return 0;
}


///14:

void cargarMat2x5(int mat[][5])
{
    for (int i=0; i<2; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("Ingrese un valor en la posicion[%i][%i]: ", i, j);
            scanf("%i", &mat[i][j]);
        }
    }
}

void multiplicacionMatrices(int mat2x2[2][2], int mat2x5[2][5], int matRes[2][5])
{
    int i,j,k;

    for (i=0; i < 2; i++)
    {
        for (j=0; j<5; j++)
        {
            matRes[i][j]=0;
            for (k=0; k<2; k++)
            {
                matRes[i][j] += mat2x2[i][k] * mat2x5[k][j];
            }
        }
    }
}

void mostrarMatrices(int mat2x2[][2], int mat2x5[][5], int matRes[][5])
{
    printf("MATRIZ 2X2: \n");
    mostrar2x2(mat2x2);

    printf("MATRIZ 2X5: \n");
    for (int i=0; i<2; i++)
    {
        printf("|");
        for (int j=0; j<5; j++)
        {
            printf(" %i ", mat2x5[i][j]);
        }
        printf("|\n");
    }
    printf("MATRIZ 2X5 RESULTANTE: \n");

    for (int i=0; i<2; i++)
    {
        printf("|");
        for (int j=0; j<5; j++)
        {
            printf(" %i ", matRes[i][j]);
        }
        printf("|\n");
    }
}

/// 15:


int calcularInversa(int mat2x2[2][2], int inversa[2][2])
{
    int det= determinanteMatriz2x2(mat2x2) * -1;

    // MATRIZ ADJUNTA:
    int aux= mat2x2[0][0];
    mat2x2[0][0]=mat2x2[1][1];
    mat2x2[0][1] *= -1;
    mat2x2[1][0] *= -1;
    mat2x2[1][1]= aux;

    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            inversa[i][j]= mat2x2[i][j]* det;
        }
    }
}

/// 17:

int esSimetrica(int mat[3][3])
{
    int i=0,j=0, flag=0;

    for (i=0; i<3; i++)
    {
        for (j=1; j < 3; j++)
        {

        if (mat[i][j] != mat[j][i])
        {
            return 0;
        }
        }
    }




    return 1;

}

/// 18:


























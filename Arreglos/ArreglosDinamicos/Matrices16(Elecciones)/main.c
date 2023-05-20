#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matCabecera(char cand[][30]);
void mostrarTabla(char cabecera[][30], int cuerpo[][5]);
void totalVotos(int mat[][5], int sum[], float prom[]);



int main()
{
    char candidatos[4][30];
    int cuerpo[5][5]={{1,194,48,206,45}, {2,180,20,320,16}, {3,221,90,140,20}, {4,432,51,821,14}, {5,820,61,946,18}};
    int suma[4]={0};
    float promedio[4]={0};

    printf("\t\t\t\t ELECCIONES PUEBLO \"LA MATRIX\" \n");


    matCabecera(candidatos);
    mostrarTabla(candidatos,cuerpo);
    totalVotos(cuerpo, suma, promedio);

    for(int i=0; i<5; i++)
    {
        printf("suma= %i  promedio: %.2f\n",suma[i], promedio[i]);
    }

    return 0;
}

///1.

void matCabecera(char cand[][30])
{
    strcpy(cand[0], "Candidatos");
    int ascii=65;
    for (int i=1; i<5; i++)
    {
        strcpy(cand[i],"Candidato ");
        cand[i][10]=ascii;
        ascii++;
    }
}

void mostrarTabla(char cabecera[][30], int cuerpo[][5])
{
    for (int i=0; i<5; i++)
    {
        printf("\t| %s |", cabecera[i]);
    }
    printf("\n");

    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            printf("\t| %i |\t", cuerpo[i][j]);
        }
        printf("\n");
    }

}

///2.

void totalVotos(int mat[][5], int sum[], float prom[])
{
    int suma=0;
    float promedio=0;
    for (int i=1; i<5; i++)
    {
        for (int j=1; j<5; j++)
        {
            suma+=mat[i][j];
        }
        sum[i]= suma;
        prom[i]= (float)suma/5;
        suma=0;
        promedio=0;
    }

}










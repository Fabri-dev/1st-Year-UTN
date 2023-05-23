#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matCabecera(char cand[][30]);
void mostrarTabla(char cabecera[][30], int cuerpo[][5]);
int sumaVotos(int mat[5][5], int pos);
int totalVotos(int mat[5][5]);
void mostrarCalculo(int mat[5][5]);




int main()
{
    char candidatos[4][30];
    int cuerpo[5][5]={{1,194,48,206,45}, {2,180,20,320,16}, {3,221,90,140,20}, {4,432,51,821,14}, {5,820,61,946,18}};


    printf("\t\t\t\t ELECCIONES PUEBLO \"LA MATRIX\" \n");


    matCabecera(candidatos);
    mostrarTabla(candidatos,cuerpo);
    mostrarCalculo(cuerpo);


    return 0;
}

///1.

void matCabecera(char cand[][30])
{
    strcpy(cand[0], "Distrito");
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

int sumaVotos(int mat[5][5], int pos)
{
    int sum=0;
    for(int i=0; i <5; i++)
    {
        sum+= mat[i][pos];
    }
    return sum;
}

int totalVotos(int mat[5][5])
{
    int acumulador=0;
    for (int i=1; i<5; i++)
    {
        acumulador+= sumaVotos(mat,i);
    }

    return acumulador;
}

void mostrarCalculo(int mat[5][5])
{
    int acumulador=totalVotos(mat), suma=0, masVotado=0;
    float prom=0;
    char ascii= 65, asciiMasVotado=0;
    for (int i=1; i<5; i++)
    {
        suma= sumaVotos(mat,i);
        prom= (float)(suma*100)/acumulador;
        printf("La suma total de votos del candidato %c es: %i \n", ascii,suma);
        printf("\nEl promedio de votos emitidos es: %.2f \n\n", prom);
        if (prom>50)
        {
            asciiMasVotado=ascii;
        }
        ascii++;

        if (masVotado < suma)
        {
            masVotado= suma;

        }

    }
        printf("------------------CANDIDATO GANADOR----------------------\n");
        printf("El candidato con mas votos fue el %c, con un total de %i \n", asciiMasVotado, masVotado);
}












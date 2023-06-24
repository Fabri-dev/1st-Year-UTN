#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>



int main( )
{
    int mat[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int fil=0,col=0;
    for ( fil = 0; fil < 3; fil++)
    {
        printf ("\n\n\t") ; /* mostrar en formato matricial */
        for (char col = 0; col < 3; col++)
        {
            printf(" %d ", mat[fil][col]);
        }
    }
    printf("\n\n\t\t");
    system("pause");

    for ( fil = 0; fil < 3; fil++)
        printf(" %d", mat[fil][fil]); /* mostrar la diagonal principal */
    col = 2;
    printf ("\n\n\t\t\t") ;

    for ( fil = 0; fil < 3; fil++)
    {
        printf (" %d", mat[fil][col]);
        col-- ; /* mostrar la diagonal opuesta */
    }
    system("pause");

    for ( fil = 0; fil < 3; fil++)
    {
        printf ("\n\n\t") ; /*  para mostrar en formato matricial */
        for ( col = 0; col < 3; col++)
        {
            mat[fil][col] = 0; /* inicializar la matriz en cero*/
            printf (" %d ", mat[fil][col]); /* mostrar la matriz */
        }
    }
    system("pause");
    return 0;
}

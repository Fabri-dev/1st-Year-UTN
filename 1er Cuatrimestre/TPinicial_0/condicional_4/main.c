#include <stdio.h>
#include <stdlib.h>
///Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente

int main()
{
    int num1,num2 ;

    printf("Escribe un numero\n");
    scanf("%i",&num1);

    printf("Escribe otro numero\n");
    scanf("%i",&num2);

    if (num1 > num2){
        printf("%i , %i",num1,num2);
    }
    if(num2 > num1){
        printf("%i , %i", num2, num1);
    }
    return 0;

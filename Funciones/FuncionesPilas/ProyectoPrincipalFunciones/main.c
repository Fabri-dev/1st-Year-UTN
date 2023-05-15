#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarElementos(Pila* carlostevez);
void ejercicio2(Pila* carlostevez);
void ejercicio3(Pila* carlostevez);
int ejercicio4(Pila* carlostevez);
void ejercicio5(Pila* carlostevez, Pila* ordenada);
void ejercicio6 (Pila* carlostevez, int numIns);
void ejercicio7 (Pila* carlostevez, Pila* ordenada);
int ejercicio8(Pila* carlostevez);
int ejercicio9(Pila* carlostevez);


int main()
{
    int op;
    char continuar;
    Pila a,ordenada;
    inicpila(&a);
    inicpila(&ordenada);
    int menor, num;

    printf("||----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
    printf("||                                                                         ELIJA UN EJERCICIO SEGUN SU NUMERO                                                                       || \n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 1. Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el usuario.                                                                             || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 2. Hacer una funcion que pase todos los elementos de una pila a otra.                                                                                                            || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 3. Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.                                                                                 || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 4. Hacer una funcion que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.                                                       || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 5. Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funcion del ejercicio 4. (Ordenamiento por seleccion)   || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 6. Hacer una funcion que inserta en una pila ordenada un nuevo elemento, conservando el orden de esta.                                                                           || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 7. Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funcion del ejercicio 6.  (Ordenamiento por insercion)  || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 8. Hacer una funcion que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido.                                                      || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 9. Hacer una funcion que calcule el promedio de los elementos de una pila, para ello hacer tambien una funcion que                                                               || \n");
    printf("||    calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la funcion que calcula el promedio invoca a las otras 3.                             || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 10. Hacer una funcion que reciba una pila con numeros de un solo digito (es responsabilidad de quien usa el programa) y que transforme esos digitos en un numero decimal.        || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("|| 11. Ejercicios extra: con el fin de generar una experiencia de usuario diferente a la que otorga la libreria se requiere desarrollar las siguientes funciones:                   || \n");
    printf("||           °Realizar una funcion que cargue la pila sin utilizar la funcion leer.                                                                                                 || \n");
    printf("||           °Realizar una funcion que muestre la pila sin utilizar la funcion mostrar.                                                                                             || \n");
    printf("||                                                                                                                                                                                  || \n");
    printf("||----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");

    printf("\nINGRESE UN NUMERO COMO OPCION: ");
    scanf("%i", &op);
    do
    {

        switch(op)
        {
        case 1:
            cargarElementos(&a);

            break;
        case 2:
            cargarElementos(&a);
            ejercicio2(&a);
            break;
        case 3:
            cargarElementos(&a);
            ejercicio3(&a);
            break;
        case 4:
            cargarElementos(&a);
            mostrar(&a);
            menor = ejercicio4(&a);
            printf("\nEl numero menor es: %i", menor);
            break;
        case 5:
            cargarElementos(&a);
            printf("\nElementos de Pila A sin ordenar: \n");
            mostrar(&a);
            printf("\nOrdenando... \n");
            printf("\nPila ordenada en forma ascendente: \n");
            ejercicio5(&a, &ordenada);
            mostrar(&ordenada);
            break;
        case 6:
            cargarElementos(&a);
            printf("\nElementos de Pila A sin ordenar: \n");
            mostrar(&a);
            printf("\nOrdenando... \n");
            printf("\nPila ordenada en forma ascendente: \n");
            ejercicio5(&a, &ordenada);
            printf("Ingrese un num");
            scanf("%i", &num);
            ejercicio6(&ordenada, num);
            mostrar(&ordenada);


            break;
        case 7:
            cargarElementos(&a);
            mostrar(&a);
            ejercicio7(&a, &ordenada);
            mostrar(&ordenada);
            break;
        case 8:
            cargarElementos(&a);
            mostrar(&a);
            num=ejercicio8(&a);
            printf("El resultado de los dos primero elementos de la Pila son: %i", num);
            mostrar(&a);
            break;
        case 9:
            cargarElementos(&a);
            mostrar(&a);
            float resultado= ejercicio9(&a);
            break;
        case 10:
            break;
        default:
            break;

        }
    }
    while(continuar == 's');



    return 0;
}
void cargarElementos(Pila* carlostevez)
{
    char opcion;
    do
    {
        leer(carlostevez);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &opcion);
    }
    while(opcion == 's');
}
void ejercicio2(Pila* carlostevez)
{
    Pila aux;
    inicpila(&aux);
    while (!pilavacia(carlostevez))
    {
        apilar(&aux, desapilar(carlostevez));
    }
    printf("Elementos de pila movidos.");
    mostrar(&aux);

}
void ejercicio3(Pila* carlostevez)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);
    while (!pilavacia(carlostevez))
    {
        apilar(&aux, desapilar(carlostevez));
    }
    while(!pilavacia(&aux))
    {
        apilar(&aux2, desapilar(&aux));
    }
    printf("Elementos de pila movidos a otra pila.");
    mostrar(&aux2);
}
int ejercicio4(Pila* carlostevez)
{
    Pila aux,menor;
    inicpila(&aux);
    inicpila(&menor);

    apilar(&menor, desapilar(carlostevez));
    while (!pilavacia(carlostevez))
    {
        if (tope(carlostevez) > tope(&menor))
        {
            apilar(&aux, desapilar(carlostevez));
        }
        else
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(carlostevez));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(carlostevez, desapilar(&aux));
    }

    int numMenor = tope(&menor);
    return numMenor;
}
void ejercicio5(Pila* carlostevez, Pila* ordenada)
{

    while(!pilavacia(carlostevez))
    {

        int numerodepaso = ejercicio4(carlostevez);
        apilar(ordenada, numerodepaso);
    }
}
void ejercicio6 (Pila* carlostevez, int numIns)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(carlostevez) && numIns < tope(carlostevez))
    {
        apilar(&aux, desapilar(carlostevez));
    }

    apilar(carlostevez, numIns);

    while(!pilavacia(&aux))
    {
        apilar(carlostevez, desapilar(&aux));
    }

}
void ejercicio7 (Pila* carlostevez, Pila* ordenada)
{
    int numIns;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(carlostevez))
    {
        numIns = tope(carlostevez);
        ejercicio6(ordenada, numIns);
        desapilar(carlostevez);
    }
}
int ejercicio8(Pila* carlostevez)
{
    Pila aux;
    inicpila(&aux);
    int sum=0, cont=0;
    while (cont < 2)
    {
        sum += tope(carlostevez);
        apilar(&aux,desapilar(carlostevez));
        cont++;
    }
    while(!pilavacia(&aux))
    {
        apilar(carlostevez, desapilar(&aux));
    }
    return sum;

}
float sumarElementosPila(Pila* carlostevez){
    int sum=0, num;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(carlostevez)){
        num = tope(carlostevez);
        sum += num;
        apilar(&aux, desapilar(carlostevez));
    }
    while(!pilavacia(&aux)){
        apilar(carlostevez,desapilar(&aux));
    }
    return sum;
}
float contarElementosPila(Pila* carlostevez){
    int cont=0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(carlostevez)){
        cont++;
        apilar(&aux, desapilar(carlostevez));
    }
    while(!pilavacia(&aux)){
        apilar(carlostevez,desapilar(&aux));
    }
    return cont;
}
float promedioPila(float sum, float cont){
    float promedio = sum / cont;
    return promedio;

}

int ejercicio9(Pila* carlostevez)
{
    float sum,cont;
    sum = sumarElementosPila(carlostevez);
    printf ("La suma de todos los elementos de la pila es: %.2f \n", sum);

    cont = contarElementosPila(carlostevez);
    printf ("El numero de elementos que hay en la pila es: %.2f \n", cont);

    float promedio = promedioPila(sum, cont);
    printf("El promedio de la pila es: %.2f \n", promedio);

    return promedio;
}

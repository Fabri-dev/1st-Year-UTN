#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
const int MAX_DIM= 99;



    /// 3) Funciones y Pasaje de parametros
    //      a- Cargar (con intervención del usuario)  y de forma automática
    //          1- pila
    void cargarPilaUsuario(Pila* dada);
    //          2- arreglo
    int cargarArregloUsuarioYDevolverValidos(int arr[], int dimension);
    //      b- sumar
    //          1- pila
    int sumarPila(Pila dada);
    //          2- arreglo
    int sumarArreglo(int arr[], int validos);


    //      c- Mostrar
    //          1- pila
    void mostrarPila(Pila a);

    //          2- arreglo
    void mostrarArreglo(int arr[], int validos);

    //      d- Contar
    //          1- pila
    int contarPila(Pila dada);
    //          2- arreglo
    int contarArreglo(int arr[], int validos);

    //      e- Pasar
    //          1- pila to pila
    void pilaToPila(Pila* a, Pila* b);
    //          2- arreglo to pila según condición (<,>,==) y según dato (viene por parámetro)
    void arregloToPila(int arr[], int validos, Pila * a);
    //          3- pila to arreglo, según condición (<,>,==) y según dato (viene por parámetro)
    int pilaToArregloYDevolverValidos(int arr[], int dimension, Pila* a);

    /// 4) Punteros
    //      a- Intercambio de dos int
    void intercambiarVariablesPorReferencia(int* var1, int* var2);
    //      b- Generar pila ordenada
    //      c- Trabajar con arreglos

    /// 5) Búsqueda de un valor, búsqueda de mayor y menor
    //      a- Pila
    int busquedaPila(Pila a);
    //      b- Arreglo
    void busquedaArreglo(int arr[], int validos);

    /// 6) Insercion de un elemento ordenado
    //      a- Pila
    void insertarElementoPila(Pila* dada, int numIngresado);
    //      b- Arreglo
    void insertarElementoArreglo(int arr[], int validos, int numeroInsertado);
    /// 7) Algoritmo de ordenación por selección e inserción sobre  pilas y arreglos.
    //      a- Pilas
    void OrdenamientoxSeleccionPilas(Pila* dada, Pila* destino);
    void OrdenamientoxInsercionPilas(Pila* dada, Pila* destino);
    //      b- Arreglos
    void OrdenamientoxSeleccionArreglo(int arr[], int validos);
    int DevolverPosicionMenor(int arr[], int posFinal, int posInicial);
    void insertarArreglo(int arr[], int validos, int dato);
    void OrdenamientoxInsercionArreglo(int arr[], int validos);

int main()
{
    /// 1) Declaracion de variables:
    int variable1;
    Pila a;
    int arr[MAX_DIM];

    /// 2) Inicializacion:
    variable1= 8;
    inicpila(&a);
    arr[0]= 4;

    Pila destino;
    inicpila(&destino);

    int validos= cargarArregloUsuarioYDevolverValidos(arr, MAX_DIM);
    OrdenamientoxInsercionArreglo(arr, validos);
    mostrarArreglo(arr, validos);
    return 0;
}

int sumarPila(Pila dada)
{
    int suma= 0;
    while(!pilavacia(&dada))
    {
        suma += tope(&dada);
        desapilar(&dada);
    }
    return suma;
}

int sumarArreglo(int arr[], int validos)
{
    int suma=0;

    for (int i=0; i < validos; i++)
    {
        suma += arr[i];
    }
    return suma;
}

void cargarPilaUsuario(Pila* dada)
{
    char op;
    int valor;

    do
    {
        printf("Ingrese un valor para agregarlo a la pila: ");
        scanf("%i", &valor);
        apilar(dada, valor);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);
    }
    while(op=='s');
}

int cargarArregloUsuarioYDevolverValidos(int arr[], int dimension)
{
    char op;
    int i=0;
    do
    {
        printf("Ingrese un valor al arreglo: ");
        scanf("%i", &arr[i]);
        i++;
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);

    }
    while (op== 's' && i<dimension);
    return i;
}

void mostrarPila(Pila a)
{
    printf("\n Pila: \n ");
    while(!pilavacia(&a))
    {
        printf("| %i | \n", tope(&a));
        desapilar(&a);
    }
}

void mostrarArreglo(int arr[], int validos)
{
    printf("\n Arreglo: ");
    for (int i=0; i < validos; i++)
    {
        printf("| %i |", arr[i]);
    }
}

int contarPila(Pila dada)
{
    int contador=0;
    while(!pilavacia(&dada))
    {
        desapilar(&dada);
        contador++;
    }
    return contador;
}

int contarArreglo(int arr[], int validos)
{
    int i;
    for (i= 0; i <validos; i++)
    {
        printf("elemento %i en la posicion %i", arr[i], i);
    }
    return i;
}

void pilaToPila(Pila* a, Pila* b)
{
    while(!pilavacia(a))
    {
        apilar(b, desapilar(a));
    }
    printf("Todos los elementos fueron pasados a la otra pila, por referencia.");
}

void arregloToPila(int arr[], int validos, Pila * a)
{
    int condicion=0, numero=0;
    char op;

    printf("\n Quiere pasar los elementos de su arreglo hacia otra pila con alguna condicion? s/n: ");
    fflush(stdin);
    scanf("%c", &op);

    if (op=='s')
    {
        printf("Elija la condicion con la que quiere pasar los elementos: \n");
        printf("1. Mayor a (un numero que usted elija) \n");
        printf("2. Menor a (un numero que usted elija) \n");
        printf("3. Igual a (un numero que usted elija) \n");
        fflush(stdin);
        scanf("%i", &condicion);
        printf("Elija el numero para la condicion: ");
        fflush(stdin);
        scanf("%i", &numero);
    }

    switch (condicion)
    {
    case 1:
        for (int i= 0; i<validos; i++)
        {
            if (arr[i] > numero)
            {
                apilar(a, arr[i]);
            }
        }
        break;
    case 2:
        for (int i= 0; i<validos; i++)
        {
            if (arr[i] <numero)
            {
                apilar(a, arr[i]);
            }
        }
        break;
    case 3:
        for (int i= 0; i<validos; i++)
        {
            if (arr[i] == numero)
            {
                apilar(a, arr[i]);
            }
        }
        break;
    default:
        for (int i = 0; i < validos; i++)
        {
            apilar(a, arr[i]);
        }

        break;
    }

    mostrar(a);
}

int pilaToArregloYDevolverValidos(int arr[], int dimension, Pila* a)
{
    char op;
    int eleccion=0, numero=0, i=0;
    printf("Quiere pasar los elementos de su pila a un arreglo con una condicion? s/n: ");
    fflush(stdin);
    scanf("%c", &op);

    if (op== 's')
    {
        printf("Elija la condicion con la que quiere pasar los elementos: \n");
        printf("1. Menor a (numero que elija)");
        printf("2. Mayor a (numero que elija)");
        printf("3. Igual a (numero que elija)");
        fflush(stdin);
        scanf("%i", &eleccion);
        printf("Ingrese el numero que quiere usar para la condicion");
        fflush(stdin);
        scanf("%i", &numero);
    }

    switch(eleccion)
    {
    case 1:
        while(!pilavacia(a))
        {
            if(tope(a) < numero)
            {
                arr[i]= tope(a);
            }
            desapilar(a);
            i++;
        }
        break;
    case 2:
        while(!pilavacia(a))
        {
            if(tope(a) > numero)
            {
                arr[i]= tope(a);
            }
            desapilar(a);
            i++;
        }
            break;
        case 3:
            while(!pilavacia(a))
            {
                if(tope(a) == numero)
                {
                    arr[i]= tope(a);
                }
                desapilar(a);
                i++;
            }
                break;
            default:
                while(!pilavacia(a))
                {
                    arr[i]=tope(a);
                    desapilar(a);
                    i++;
                }
                break;
            }
            return i;
}

void intercambiarVariablesPorReferencia(int* var1, int* var2)
{
    int aux;
    aux= *var1;
    *var1 = *var2;
    *var2 = aux;
}

int busquedaPila(Pila a)
{
    Pila aux, basura;
    inicpila(&aux);
    inicpila(&basura);
    int num=0, buscar=0;
    int elegir=0;
    printf("Que elemento quiere buscar en la pila?: ");
    printf("1. Mayor");
    printf("2. Menor");
    printf("3. Numero a eleccion");
    fflush(stdin);
    scanf("%i", &elegir);

    switch(elegir)
    {
    case 1:
        apilar(&aux, desapilar(&a));

        while(!pilavacia(&a))
        {
            if (tope(&aux) > tope(&a))
            {
                apilar(&basura, desapilar(&aux));
                apilar(&aux, desapilar(&a));
            }
            else
            {
                apilar(&basura, desapilar(&a));
            }
        }
        num = tope(&aux);
        return num;
        break;
    case 2:
        apilar(&aux, desapilar(&a));

        while(!pilavacia(&a))
        {
            if (tope(&aux) < tope(&a))
            {
                apilar(&basura, desapilar(&aux));
                apilar(&aux, desapilar(&a));
            }
            else
            {
                apilar(&basura, desapilar(&a));
            }
        }
        num = tope(&aux);
        return num;
        break;
    case 3:
        printf("Ingrese el numero que desea buscar: ");
        fflush(stdin);
        scanf("%i", &buscar);
        while(!pilavacia(&a))
        {
            if (buscar == tope(&a))
            {
                apilar(&aux, desapilar(&a));
            }
            else
            {
                apilar(&basura, desapilar(&a));
            }
        }
        if (!pilavacia(&aux))
        {
            printf("Numero encontrado:");
            mostrar(&aux);
        }
        else
        {
            printf("Numero no encontrado");
        }
        break;
    default:
        printf("ERROR:No elegio ninguna opcion, vuelva a intentar.");
        break;
    }
}

void busquedaArreglo(int arr[], int validos)
{
    int op=0, num=0, flag=0;
    printf("Ingrese que desea buscar:");
    printf("1. Mayor del arreglo");
    printf("2. Menor del arreglo");
    printf("3. Un numero a eleccion");
    fflush(stdin);
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        for (int i=0; i<validos; i++)
        {
            if (arr[i] > num)
            {
                num = arr[i];
            }
        }
        return num;
        break;
    case 2:
        num=arr[num];
        for (int i=0; i<validos; i++)
        {
            if (arr[i]< num)
            {
                num= arr[i];
            }
        }
        return num;
        break;
    case 3:
        printf("Ingrese el numero que desea buscar en el arreglo: ");
        scanf("%i", &num);
        for (int i=0; i < validos; i++)
        {
            if (num == arr[i])
            {
                flag=1;
            }
        }
        if (flag == 1)
        {
            printf("Numero encontrado");
        }
        else
        {
            printf("Numero NO encontrado");
        }
        break;
    default:
        printf("ERROR: no ingreso ningun numero, vuelva a intentarlo");
        break;
    }
}

void insertarElementoPila(Pila* dada, int numIngresado)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(dada) && (tope(dada) > numIngresado))
    {
        apilar(&aux, desapilar(dada));

    }
    apilar(dada, numIngresado);

    while(!pilavacia(&aux))
    {
        apilar(dada, desapilar(&aux));
    }
}

void insertarElementoArreglo(int arr[], int validos, int numeroInsertado)
{
    int i = validos -1 ;
    while (i>=0 && numeroInsertado < arr[i])
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]= numeroInsertado;
}
void OrdenamientoxSeleccionPilas(Pila* dada, Pila* destino)
{
    Pila menor;
    Pila aux;
    inicpila(&aux);
    inicpila(&menor);


    while(!pilavacia(dada))
    {
    apilar(&menor, desapilar(dada));

        while(!pilavacia(dada))
        {
            if (tope(&menor) > tope(dada))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(dada));
            }
            else
            {
                apilar(&aux, desapilar(dada));
            }
        }

        apilar(destino, desapilar(&menor));

        while(!pilavacia(&aux))
        {
            apilar(dada, desapilar(&aux));
        }

    }

}

void OrdenamientoxInsercionPilas(Pila* dada, Pila* destino)
{
    Pila aux;
    inicpila(&aux);


    while(!pilavacia(dada))
    {
        insertarElementoPila(destino, desapilar(dada));

    }
}

int DevolverPosicionMenor(int arr[], int posFinal, int posInicial)
{
    int posMenor= posInicial;
    for (int i=posInicial; i< posFinal; i++)
    {

        if (arr[i] < arr[posMenor])
        {
            posMenor= i;
        }
    }
    return posMenor;
}

void OrdenamientoxSeleccionArreglo(int arr[], int validos)
{
    int posMenor,aux;
    for (int i= 0; i< validos; i++)
    {

        posMenor= DevolverPosicionMenor(arr, validos-1, i);
        aux= arr[i];
        arr[i]= arr[posMenor];
        arr[posMenor]= aux;
    }
}

void insertarArreglo(int arr[], int validos, int dato)
{
    int i= validos-1;
    while(i>=0 && dato<arr[i])
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=dato;
}


void OrdenamientoxInsercionArreglo(int arr[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        insertarArreglo(arr,i,arr[i]);
    }
}




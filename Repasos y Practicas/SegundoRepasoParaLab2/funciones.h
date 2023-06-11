#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/// Estructuras

typedef struct
{
int cuit; // ENTRE 2.000.000 Y 10.000.000
char nya [30];
}Monotributista;


typedef struct
{
int nroFactura;
char tipoFactura; // A, B EN MAYUSCULA
Monotributista m;
float montoTotal; //NO MAS DE $ 500.000 NO PUEDE HABER MONTOS NEGATIVOS
} Factura;


/// Prototipados

int verificarCuit(int cuit);
Monotributista crearUnMonotributista();
int cargarArregloMono(Monotributista arr[]);













#endif // FUNCIONES_H_INCLUDED

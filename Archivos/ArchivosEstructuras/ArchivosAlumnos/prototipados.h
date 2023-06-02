#include <stdio.h>
#include <malloc.h>

////  PROTOTIPADOS  \\\\\


typedef struct {
     char nombreYapellido [30];
     int legajo;
     int edad;
     int anio;

} stAlumno;

stAlumno cargarAlumno();
void cargarArchivoAlumnos(char archivo[]);
void mostrarAlumno(stAlumno alumno);
void mostrarArchivo(char archivo[]);
void pasarAPilaLegajos(char archivo[], Pila* pilaLegajos);
int preguntarDato();
int contarAlumnosXDato(char archivo[], int dato);
void mostrarRangoEdad(char archivo[], int desde, int hasta);
void mostrarMayorEdad(char archivo[]);
int cantAlumnosXanio(char archivo[], int dato);
int cargarArregloAlumno(stAlumno arr[]);
void arregloToArchivo(char archivo[], stAlumno arr[], int validos);
void archivoToArregloConCondicion(char archivo[], stAlumno arrAnio[], int dato ,int validos);
void mostrarArregloAlumnos(stAlumno arr[], int validos);



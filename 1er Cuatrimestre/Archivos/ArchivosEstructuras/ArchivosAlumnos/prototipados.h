#include <stdio.h>
#include <malloc.h>

////  PROTOTIPADOS


typedef struct {
     char nombreYapellido [30];
     int legajo;
     int edad;
     int anio;

} stAlumno;

//1:
void cargarArchivoPrim(char archivo[]);

//2:
void mostrarArchivoPrim(char archivo[]);

//3:
int contarRegistrosPrim(char archivo[]);



//4:
stAlumno cargarAlumno();
void cargarArchivoAlumnos(char archivo[]);

//5:
void mostrarAlumno(stAlumno alumno);
void mostrarArchivo(char archivo[]);

//6:???

//7:
void pasarAPilaLegajos(char archivo[], Pila* pilaLegajos);

//8:
int preguntarDato();
int contarAlumnosXDato(char archivo[], int dato);

//9:
void mostrarRangoEdad(char archivo[], int desde, int hasta);

//10:
stAlumno mostrarMayorEdad(char archivo[]);

//11:
int cantAlumnosXanio(char archivo[], int dato);

//12:
int cargarArregloAlumno(stAlumno arr[]);
void arregloToArchivo(char archivo[], stAlumno arr[], int validos);
void archivoToArregloConCondicion(char archivo[], stAlumno arrAnio[], int dato ,int validos);
void mostrarArregloAlumnos(stAlumno arr[], int validos);

//13:
int contarCantidadDeRegistros(char archivo[]);

//14:
void mostrarPorDato(char archivo[]);

//15:
void modificarArchivo(char archivo[], int dato);
void modificarAlumno(stAlumno* modificado);

//16:

void invertirElementosArchivo(char archivo[]);

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define dimFila 3
#define dimCol 3
/// Estructura

typedef struct
{
    int legajo;
    char nombreMateria[30];
    int anio;
    int nota;
}Alumno;



/// Funciones

void menu(int mat[][dimCol], Alumno arregloAlumnos[], char archivoA[], char archivoD[]);
int preguntarDato();
int buscarNumeroEnMatriz(int mat[][3], int dato);
int verificarNota();
Alumno crearAlumno();
int cargarAlumnosToArreglo(Alumno arr[]);






#endif // FUNCIONES_H_INCLUDED

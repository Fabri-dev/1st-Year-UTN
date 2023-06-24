#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///Estructura

typedef struct
{
 int id;
 char nombreDisfraz[40];
 char genero[10]; // hombre o mujer
 int precioAlquiler;

} Disfraz;


///Prototipados


void menu(Disfraz arregloDisfraces[],char archivoM[], char archivoH[]);
Disfraz cargarUnDisfraz();
int validarGenero(char genero[]);
void cargarArregloDisfraces(Disfraz arr[], int * validos);
int hombreOmujer(char genero[]);
void cantidadDeDisfracesXPrecio(Disfraz arr[],int validos,int dato, int* disfracesH, int* disfracesM);
int preguntarDato();
void arregloToArchivos(char archivoM[], char archivoH[], Disfraz arr[], int validos);
void mostrarDisfraz(Disfraz aux);
void mostrarArchivo(char archivo[]);
void mostrarLosArchivos(char archivoM[],char archivoH[]);

void modificarDisfraz(Disfraz * aux);






#endif // FUNCIONES_H_INCLUDED

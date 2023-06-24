#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define COLUMNAS 4
#define FILAS 4

///Estructura
typedef struct {
int dni;
char nombre [30];
char direccion[30];
char sexo; // ‘m’ o ‘f’
} Paciente;

///Prototipados

void menu(char archivoPacientes[], float mat[FILAS][COLUMNAS], float arregloPromedio[]);
Paciente crearPaciente();
void cargarArchivoPacientes(char archivo[]);
int cantPacientesFemeninos(char archivo[]);
void cargarMatriz(float mat[FILAS][COLUMNAS]);
int valorPromedioFilaMatriz(float mat[FILAS][COLUMNAS], float arr[]);
void mostrarArreglo(float arr[],int validos);




#endif // FUNCIONES_H_INCLUDED

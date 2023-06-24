#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXDIM 30


// estructuras

typedef struct {
    int idDireccion;
    char nombre[30];
    char apellido[30];
    int cantPremios;
    int cantPelisDirigidas;
}stDireccion;

typedef struct {
    int idPelicula;
    char nombre[30];
    int minutosDuracion;
    char genero[30];
    int tipoMetraje;
    char pais[30];
    int idDireccion;
}stPelicula;

//prototipados

void menu(stDireccion arregloDireccion[], stPelicula arregloPelicula[], char archivoDirectoresMalos[],char archivoDirectoresBuenos[], char archivoPeliculas[]);
int validarDatosDireccion(int dato);
stDireccion crearUnaDireccion(int * IDdirec);
int cargarArregloDireccion(stDireccion arr[], int * IDdirec);
int validarDuracion(int dato);
int validarIDdireccion(stDireccion arr[],int validos, int dato);
stPelicula crearUnaPelicula(stDireccion arrDi[], int validosDi, int * IDpeli);
int cargarArregloPelicula(stPelicula arrPel[], stDireccion arrDirecc[], int validosDirecc, int * IDpeli);
void cargarArchivoPeliculas(stPelicula arr[],int validos, char archivoPeliculas[]);
void cargarArchivoDirectores(stDireccion arr[],int validos,char archivoDirectoresBuenos[], char archivoDirectoresMalos[]);
void catalogarTipoMetraje(stPelicula * aux);
void clasificarPeliculas(char archivoPel[]);
void mostrarDireccion(stDireccion aux);
void mostrarPelicula(stPelicula aux);
void mostrarArchivoPeliculas(char archivoPel[]);
void mostrarArchivoDireccionUNO(char archivoDir[]);
void mostrarTodasLasDirecciones(char archivoDirBuenos[], char archivoDirMalos[]);
void mostrarArregloDir(stDireccion arr[],int validos);




#endif // FUNCIONES_H_INCLUDED

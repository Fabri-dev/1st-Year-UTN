#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXDIMSTR 40


///Prototipados

typedef struct
{
char nombre[MAXDIMSTR];
char apellido[MAXDIMSTR];
char nacionalidad[MAXDIMSTR];
int edad;
int DNI;
}stPersona;


typedef struct
{
stPersona datosPersonales;
char puesto[MAXDIMSTR];
int horasDiarias;
float salario;
}stEmpleado;

//validaciones
int validarNombreyApellido(char dato[]);
int validarPais(char dato[]);
int validarEdad(int dato);
int validarDNI(int dato);
int validarSiDniExiste(int dato,char archivoP[]);
int validarHorasDiarias(int dato);
int validarSalario(float dato);
int validarPuesto(int dato, char cargo[]);



//varios
int preguntarDato();
void mostrarPuestos();
void limpiarPantalla();



//Alta a datos personales
stPersona datosPersonales();

//cargar archivo datos personales
void cargarArchivoDatosPersonales(char archivo[]);

//Alta a empleado
stEmpleado cargarUnEmpleado(char archivoDatosPersonales[]);

//Cargar archivo empleados
void cargarArchivoEmpleado(char archivoEmp[],char archivoDatosPersonales[]);

//mostrar un empleado
void mostrarUnEmpleado(stEmpleado aux);

//mostrar todos los empleados
void mostrarEmpleados(char archivoEmpleados[]);

//mostrar empleados por datos especificos
void mostrarEmpleadosXpuesto(char archivoEmpleados[], char puesto[]);
void elegirQuePuestoMostrar(char archivoEmpleados[], int dato);




//Modificar archivo empleados
    //Dar de baja , etc

//Consultar datos empleados




























#endif // FUNCIONES_H_INCLUDED

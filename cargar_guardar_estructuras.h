/*Existe la posibilidad de que algunas funciones de cargar den un warning porque
el primer parametro no este inicializado. Es normal.*/

/*Estructuras del programa:*/
#ifndef T_USUARIOS_H
#define T_USUARIOS_H
typedef struct T_Usuarios{
  int Id_usuario;           //Identificador de usuario
  char Nomb_usuario[21];    //Nombre y apellido, max 20 char.
  char Localidad[21];       //Localidad de residencia, max 20 char.
  char Perfil_usuario[15];  //administrador o usuario
  char User[6];             //nombre de usuarios para acceder, max 5char.
  char Login[9];            //contrasena 8 caracteres max
  char Estado[10];          //Estado: Activo; Bloqueado
}T_Usuarios;
#endif

#ifndef T_VEHICULOS_H
#define T_VEHICULOS_H
typedef struct{
  char Id_mat[8];     //matricula del vehiculo
  int Id_usuario;     //id usuario dueno vehiculo
  int Num_plazas;     //numero de plazas disponibles, sin contar conductor
  char Desc_veh[51];  //descripcion del vehiculo, max 50 char.
}T_Vehiculos;
#endif

#ifndef T_VIAJES_H
#define T_VIAJES_H
typedef struct{       //estructura auxiliar para almecenar fecha
  int Dia;
  int Mes;
  int Ano;
}T_Fecha;

typedef struct{       //estructura auxiliar para almacenar hora
  int Hora;
  int Minutos;
}T_Hora;

typedef struct{
  int Id_viaje;
  char Id_mat[8];
  T_Fecha F_inic;
  T_Hora H_inic;
  T_Hora H_fin;
  int Plazas_libres;
  char Viaje[7];
  float Importe;
  char Estado[11];
}T_Viajes;
#endif

#ifndef T_PASOS_H
#define T_PASOS_H
typedef struct{
  int Id_viaje;
  char Poblacion[21];
}T_Pasos;
#endif

#ifndef T_INCIDENCIAS_H
#define T_INCIDENCIAS_H
typedef struct
{
  int Id_viaje;           //Id del viaje
  int Id_us_registra;     //Id del usuario que registra la incidecia
  int Id_us_incidencia;   //Id del usuario sobre el que recae la incidencia
  char Desc_incidencia[101];  //Descripcion de la incidencia, max 100 char.
  char Est_incidencia[9]; //Estado de la incidencia (abierta, validada, cerrada)
} T_Incidencias;
#endif

/*Funciones:*/

#ifndef CARGAR_USUARIOS_H
#define CARGAR_USUARIOS_H
/*
Cabecera: void cargar_usuarios(T_Usuarios **, int *);

Precondicion: recibe la direccion de memoria de un puntero de T_Usuarios, la
            direccion del vector vacio, y una posicion de memoria a entero.

Postcondicion: carga un vector dinamico desde usuarios.txt en el vector vacio,
            y el numero de elementos cargados esta en el puntero a entero.
*/
void cargar_usuarios(T_Usuarios **, int *);
#endif

#ifndef CARGAR_VEHICULOS_H
#define CARGAR_VEHICULOS_H
/*
Cabecera: void cargar_vehiculos(T_Vehiculos **, int *);

Precondicion: recibe la direccion de memoria de un puntero de T_Vehiculos, la
            direccion del vector vacio, y una posicion de memoria a entero.

Postcondicion: carga un vector dinamico desde vehiculos.txt en el vector vacio,
            y el numero de elementos cargados esta en el puntero a entero.
*/
void cargar_vehiculos(T_Vehiculos **, int *);
#endif

#ifndef CARGAR_VIAJES_H
#define CARGAR_VIAJES_H
/*
Cabecera: void cargar_viajes(T_Viajes **, int *);

Precondicion: recibe la direccion de memoria de un puntero de T_Viajes, la
            direccion del vector vacio, y una posicion de memoria a entero.

Postcondicion: carga un vector dinamico desde viajes.txt en el vector vacio,
            y el numero de elementos cargados esta en el puntero a entero.
*/
void cargar_viajes(T_Viajes **, int *);
#endif

#ifndef CARGAR_PASOS_H
#define CARGAR_PASOS_H
/*
Cabecera: void cargar_pasos(T_Pasos **, int *);

Precondicion: recibe la direccion de memoria de un puntero de T_Pasos, la
            direccion del vector vacio, y una posicion de memoria a entero.

Postcondicion: carga un vector dinamico desde pasos.txt en el vector vacio,
            y el numero de elementos cargados esta en el puntero a entero.
*/
void cargar_pasos(T_Pasos **, int *);
#endif

#ifndef CARGAR_INCIDENCIAS_H
#define CARGAR_INCIDENCIAS_H
/*
Cabecera: void cargar_incidencias(T_Incidencias **, int *);

Precondicion: recibe la direccion de memoria de un puntero de T_Incidencias, la
            direccion del vector vacio, y una posicion de memoria a entero.

Postcondicion: carga un vector dinamico desde incidencias.txt en el vector vacio
            y el numero de elementos cargados esta en el puntero a entero.
*/
void cargar_incidencias(T_Incidencias **, int *);
#endif

#ifndef GUARDAR_USUARIOS_H
#define GUARDAR_USUARIOS_H
/*
Cabecera: void guardar_usuarios(T_Usuarios *, int )

Precondicion: recibe un vector de T_Usuarios y la cantidad de elementos del
        vector
Postcondicion: guarda en usuarios.txt los datos del vector con un formato
          y libera la memoria reservada para el vector..
*/
void guardar_usuarios(T_Usuarios *, int);
#endif

#ifndef GUARDAR_VEHICULOS_H
#define GUARDAR_VEHICULOS_H
/*
Cabecera: void guardar_vehiculos(T_Vehiculos *, int)

Precondicion: recibe un vector de T_Vehiculos y la cantidad de elementos del
          vector

Postcondicion: guarda en vehiculos.txt los datos del vector con un formato
          y libera la memoria reservada para el vector.
*/
void guardar_vehiculos(T_Vehiculos *, int);
#endif

#ifndef GUARDAR_VIAJES_H
#define GUARDAR_VIAJES_H
/*
Cabecera: void guardar_viajes(T_Viajes *, int)

Precondicion: recibe un vector de T_Viajes y la cantidad de elementos del
          vector

Postcondicion: guarda en viajes.txt los datos del vector con un formato
          y libera la memoria reservada para el vector.
*/
void guardar_viajes(T_Viajes *, int);
#endif

#ifndef GUARDAR_PASOS_H
#define GUARDAR_PASOS_H
/*
Cabecera: void guardar_pasos(T_Pasos *, int)

Precondicion: recibe un vector de T_Pasos y la cantidad de elementos del vector

Postcondicion: guarda en pasos.txt los datos del vector con un formato
          y libera la memoria reservada para el vector.
*/
void guardar_pasos(T_Pasos *, int);
#endif

#ifndef GUARDAR_INCIDENCIAS_H
#define GUARDAR_INCIDENCIAS_H
/*
Cabecera: void guardar_incidencias(T_Incidencias, int)

Precondicion: recibe un vector de T_Incidencias y la cantidad de elementos del
          vector

Postcondicion: guarda en incidencias.txt los datos del vector con un formato
          y libera la memoria reservada para el vector.
*/
void guardar_incidencias(T_Incidencias *, int);
#endif

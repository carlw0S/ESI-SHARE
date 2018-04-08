#include "usuarios.h"
#include "vehiculos.h"
#include "viajes.h"
#include "incidencias.h"
#include <stdio.h>
#include <stdlib.h>
/*Existe la posibilidad de que algunas funciones de cargar den un warning porque
el primer parametro no este inicializado. Es normal.*/

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

#ifndef INTERCAMBIAR_ESPACIOS_H
#define INTERCAMBIAR_ESPACIOS_H
/* Funcion local
Cabecera: void intercambiar_espacios(char *);

Precondicion: Recibe una cadena de caracteres con caracter terminador

Postcondicion: Intercambia los guiones de la cadena por espacios. Los espacios
      por barras bajas y las barras bajas por espacios.
*/
static void intercambiar_espacios(char *);
#endif

#ifndef CONTAR_ELEMENTOS_H
#define CONTAR_ELEMENTOS_H
/* Funcion local
Cabecera: int contar_elementos_fichero(FILE*);

Precondicion: Recibe un fichero abierto con posibilidad de lectura

Postcondicion: a partir de la posicion del fichero, devuelte el numero de saltos
            de linea
*/
static int contar_elementos_fichero(FILE* );
#endif

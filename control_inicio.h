#include "viajes.h"
#include "incidencias.h"
#include "usuarios.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef COMPROBACION_HORAS_VIAJES_H
#define COMPROBACION_HORAS_VIAJES_H

void comprobacion_horas_viajes(T_Viajes *);
#endif


#ifndef COMPROBACION_INCIDENCIAS_H
#define COMPROBACION_INCIDENCIAS_H

void comprobacion_incidencias(T_Incidencias *);
#endif

#ifndef LOGIN_H
#define LOGIN_H
/*
Cabecera: int login (T_Usuarios * usuarios, int N);

Precondicion: Recibe un vector usuarios de T_Usuarios de N elementos cargado.

Postcondicion: Solicita al usuario del programa que introduzca un usuario y
      contrasena. Si ambos son correctos devuelve la id del usuario. Si el
      usuario existe pero la contrasena es incorrecta devuelve -1. Si el usuario
      no existe devuelve -2
*/
int login(T_Usuarios *, int );
#endif

/*Privada*/
#ifndef RM_FIN_LINEA_H
#define RM_FIN_LINEA_H

void rm_fin_linea(char *, int );
#endif

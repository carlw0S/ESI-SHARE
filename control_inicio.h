#include "viajes.h"
#include "usuarios.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

#ifndef check_HORAS_VIAJES_H
#define check_HORAS_VIAJES_H

void check_horas_viajes(T_Viajes *);
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

#ifndef PANTALLA_ERR_LOGIN_H
#define PANTALLA_ERR_LOGIN_H
/*
Cabecera: void pantalla_login_h(T_Usuarios * usuarios, int N, int * id);

Precondicion: Recibe un vector relleno de T_Usuarios, la cantida de
      elementos de este y la id (o resultado fallido de login()) del usuario

Postcondicion: Permite al usuario volver a intentar iniciar sesion, salir
      del programa o crear un nuevo usuario. Si desea salir, la id del usuario
      valdra 0.
*/
void pantalla_err_login(T_Usuarios *, int , int *);
#endif


#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H
/*
Cabecera: int menu_principal(T_Usuarios *, int N, int id);

Precondicion: recibe un vector de T_Usuarios cargado, la cantidad de usuarios y
      la id del usuario actual.

Postcondicion: imprime el menu adecuado a el usuario actual y devuelve:
      >El signo del numero dice si es un usuario o un administrador:
                + => usuario        - => administrador
      >1 para el/los perfil(es)
      >2 para el/los vehiculo(s)
      >3 para el/los viaje(s)
      >4 para el/las incidencia(s)
      >5 para salir
*/
void menu_principal(T_Usuarios *, int, int);
#endif

#ifndef LLAMADAS_MENU_H
#define LLAMADAS_MENU_H

void llamadas_menu(T_Usuarios * usuarios, int N, int id, int opt);
#endif

#ifndef TITULO_H
#define TITULO_H
/*
Cabecera: void titulo();

Precondicion:

Postcondicion: imprime el titulo del programa
*/
void titulo();
#endif

#ifndef CHECK_USUARIO_BLOQUEADO_H
#define CHECK_USUARIO_BLOQUEADO_H
/*
Cabecera: void check_usuario_bloqueado(T_Usuarios *, int N, int * id);

Precondicion: recibe un vector cargado de T_Usuarios, la cantidad de elementos y
      la id del usuario actual.

Postcondicion: Comprueba si el usuario esta bloqueado. En tal caso imprime el
      mensaje de error en la pantalla y cambia la id de usuario a 0.
*/
void check_usuario_bloqueado(T_Usuarios *, int, int*);
#endif


/*Privada*/
#ifndef RM_FIN_LINEA_H
#define RM_FIN_LINEA_H
/*
Cabecera: char * rm_fin_linea(char *, int n);

Precondicion: recibe una cadena de n caracteres

Postcondicion: sustituye el primer caracter '\n' que encuentre por un '\0'.
      Ademas devuelve la cadena.
*/
char * rm_fin_linea(char *, int );
#endif

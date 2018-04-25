#ifndef CHECK_HORAS_VIAJES_H
#define CHECK_HORAS_VIAJES_H
/*
Cabecera: void check_horas_viajes(T_Viajes *, int);

Precondicion: recibe un vector relleno de T_Viajes y la cantidad de viajes.

Postcondicion: si algun viaje abierto ha finalizado hace mas de una hora desde
        que se ejecuta en la funcion, lo cierra.
*/
void check_horas_viajes(T_Viajes *, int);
#endif

#ifndef INICIO_SESION_H
#define INICIO_SESION_H
/*
Cabecera: void incicio_sesion(T_Usuarios *, int, int *);

Precondicion: recibe un vector relleno de T_Usuarios, la cantidad de usuarios y
        la posicion de memoria de la id.

Postcondicion: Inicia sesion con datos solicitados al usuario
*/
void incicio_sesion(T_Usuarios **, int *, int *);
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
void pantalla_err_login(T_Usuarios **, int *, int *);
#endif


#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H
/*
Cabecera: void menu_principal(T_Usuarios *, int N, int id);

Precondicion: recibe un vector de T_Usuarios cargado, la cantidad de usuarios y
      la id del usuario actual.

Postcondicion: imprime el menu adecuado a el usuario actual y llama a la funcion
      adecuada.
*/
void menu_principal(T_Usuarios *, int, int);
#endif

#ifndef LLAMADAS_MENU_H
#define LLAMADAS_MENU_H
/*
Cabecera: void llamadas_menu(T_Usuarios *, int , int , int );

Precondicion: recibe un vector de usuarios relleno, la cantidad de usuarios, la
      id del usuario actual, y la opcion elegida en el menu principal.

Postcondicion: segun la opcion actual llama a la funcion adecuada.
*/
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

#ifndef INTRODUCIR_CREDENCIALES_H
#define INTRODUCIR_CREDENCIALES_H
/*
Cabecera: void introducir_credenciales(char user[6], char pass[9]);

Precondicion: recibe una cadena de 6 elementos y otra de 8

Postcondicion: pide al usuario que introduzca el user y lo guarda en la primera
          cadena, y la pass y la guarda en la segunda cadena. Si la longitud de
          alguno excede la maxima (5 char para user, 8 char para pass) da error
          y vuelve a intentarlo.
*/
void introducir_credenciales(char user[6], char pass[9]);
#endif

#ifndef POS_ID_H
#define POS_ID_H
/*
Cabecera: int pos_id(T_Usuarios *, int);

Precondicion: recibe un vector relleno de T_Usuarios, la cantidad de
          elemetos y una id.

Postcondicion: devuelve la posicion en el vector del usuario con la id dada.
*/
int pos_id(T_Usuarios *, int, int);
#endif

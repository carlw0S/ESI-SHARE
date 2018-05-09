#ifndef USUARIO_VEHICULOS_H
#define USUARIO_VEHICULOS_H
//cabecera: void usuario_vehiculos(T_Vehiculos *vehiculos, int *n)
//precondicion: estructura del vehiculo con los datos y un puntero entero n que es la cantidad de elementos del vector
//postcondicion: muestra los datos del vehiculo del usuario
void usuario_vehiculos(T_Vehiculos *vehiculos, int *n);
#endif

#ifndef LISTA_VEHICULOS_H
#define LISTA_VEHICULOS_H
//cabecera: void lista_vehiculos (T_Vehiculos * vehiculos, int n)
//precondicion: estructura del vehiculo con los datos y un puntero entero n que es la cantidad de elementos del vector
//postcondicion: muestra la lista de vehiculos
void lista_vehiculos (T_Vehiculos * vehiculos, int n);
#endif

#ifndef ANADIR_VEHICULO_H
#define ANADIR_VEHICULO_H
//cabecera: void anadir_vehiculo(T_vehiculos *vehiculos,int n)
//precondicion: estructura del vehiculo con los datos y un puntero entero n que es la cantidad de elementos del vector
//postcondicion: añade un nuevo vehiculo a la lista
void anadir_vehiculo(T_vehiculos *vehiculos,int n);
#endif

#ifndef ELIMINAR_TUVEHICULO_H
#define ELIMINAR_TUVEHICULO_H
//cabecera: void eliminar_tuvehiculo(T_Vehiculos *vehiculos, int *n, int Id_usuario);
//precondicion: estructura del vehiculo con los datos y un puntero entero n que es la cantidad de elementos del vector
//postcondicion: elimina el vehiculo del usuario de la lista
void eliminar_tuvehiculo(T_Vehiculos *vehiculos, int *n, int Id_usuario);
#endif

#ifndef ELIMINAR_VEHICULO_H
#define ELIMINAR_VEHICULO_H
//cabecera: void eliminar_vehiculo(T_vehiculos *vehiculos, int *n)
//precondicion: estructura del vehiculo con los datos, un puntero entero n que es la cantidad de elementos del vector y la id del usuario
//postcondicion: el administrador elimina un vehiculo
void eliminar_vehiculo(T_vehiculos *vehiculos, int *n);
#endif

#ifndef ADMIN_VEHICULOS_H
#define ADMIN_VEHICULOS_H
//cabecera: void administrador_vehiculos(T_Vehiculos *vehiculos, int *n)
//precondicion: estructura del vehiculo con los datos y un puntero entero n que es la cantidad de elementos del vector
//postcondicion: muestra el menu del administrador

void administrador_vehiculos(T_Vehiculos *vehiculos, int *n);
#endif


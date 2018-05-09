#ifndef PERFILES_USUARIOS_H
#define PERFILES_USUARIOS_H
//cabecera: void perfiles_user(T_Usuarios *usuarios, int * n)
//precondicion: estructura de usuario con los datos y un puntero entero n que es la cantidad de elementos del vector
//postcondicion: muestra los datos del usuario y le permite modificar su perfil
void perfiles_user(T_Usuarios *usuarios, int * n);
#endif // PERFILES_USUARIOS_H

#ifndef PERFILES_ADMINISTRADOR_H
#define PERFILES_ADMINISTRADOR_H
//cabecera: void perfiles_admin(T_Usuarios *usuarios, int * n)
//precondicion: estructura de usuario con los datos y un puntero entero n que es la cantidad de elementos del vector
//postcondicion: permite al administrador ver la lista de usuarios, modificar un usuario, bloquearlos, o crearlos
void perfiles_admin(T_Usuarios *usuarios, int * n);
#endif




#ifndef LISTA_USUARIOS_H
#define LISTA_USUARIOS_H
//cabecera: void lista_usuarios(T_Usuarios * usuarios, int n)
//precondicion: estructura de usuario con los datos y un puntero entero n que es la cantidad de elementos del vector
//postcondicion: muestra en pantalla la lista de usuarios
void lista_usuarios(T_Usuarios * usuarios, int n);
#endif


#ifndef MOD_PERFIL_H
#define MOD_PERFIL_H
//cabecera: void mod_perfil(T_Usuarios * usuarios, int n, int id)
//precondicion: estructura de usuario con los datos, un puntero entero n que es la cantidad de elementos del vector y la id del usuario
//postcondicion: modifica los datos de usuario
void mod_perfil(T_Usuarios * usuarios, int n, int id);
#endif

#ifndef BLOQUEAR_USUARIO_H
#define BLOQUEAR_USUARIO_H
//cabecera: void bloquear_usuario(T_Usuarios * usuarios, int n, int id)
//precondicion: estructura de usuario con los datos, un puntero entero n que es la cantidad de elementos del vector y la id del usuario
//postcondicion: cambia el estado del usuario a "bloqueado"
void bloquear_usuario(T_Usuarios * usuarios, int n, int id);
#endif


#ifndef DESBLOQUEAR_USUARIO_H
#define DESBLOQUEAR_USUARIO_H
//cabecera: void desbloquear_usuario(T_Usuarios * usuarios, int n, int id)
//precondicion:  estructura de usuario con los datos, un puntero entero n que es la cantidad de elementos del vector y la id del usuario
//postcondicion: cambia el estado del usuario a "activo"
void desbloquear_usuario(T_Usuarios * usuarios, int n, int id);
#endif

#ifndef CREAR_USUARIO_H
#define CREAR_USUARIO_H
//cabecera: int crear_usuario (T_Usuarios ** usuarios,int n, char * perfil)
//precondicion: estructura de usuario con los datos, un puntero entero n que es la cantidad de elementos del vector y la cadena perfil
//postcondicion: introduce un nuevo usuario en la lista de usuarios
int crear_usuario (T_Usuarios ** usuarios,int n, char * perfil);
#endif

#ifndef ELIMINAR_USUARIO_H
#define ELIMINAR_USUARIO_H
//cabecera: void eliminar_usuario (T_Usuarios * usuarios, int *n)
//precondicion: estructura de usuario con los datos y un puntero entero n que es la cantidad de elementos del vector
//postcondicion: borra un usuario de la lista de usuarios
void eliminar_usuario (T_Usuarios * usuarios, int *n);
#endif

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

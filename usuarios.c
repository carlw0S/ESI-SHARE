#include <stdio.h>
#include <stdin.h>
#include <string.h>
#include <stdlib.h>
#ifndef T_USUARIOS_H
#define T_USUARIOS_H
typedef struct{
  int Id_usuario;           //Identificador de usuario
  char Nomb_usuario[21];    //Nombre y apellido, max 20 char.
  char Localidad[21];       //Localidad de residencia, max 20 char.
  char Perfil_usuario[15];  //administrador o usuario
  char User[6];             //nombre de usuarios para acceder, max 5char.
  char Login[9];            //contrasena 8 caracteres max
  char Estado[10];               //Estado: Activo; Bloqueado
}T_Usuarios;
#endif

void perfiles_user(T_Usuarios *usuarios, int * n) //funcion que escribe los datos del usuario
{
   char a;
   printf("%i", &Id_usuario);
   printf("%s", &Nomb_usuario);
   printf("%s", &Localidad);
   printf("%s", &Perfil_usuario);
   printf("¿Desea modificar su perfil? ('s' para modificar) \n"); //escriba "s" para modificar
   scanf("%c", &a) //lee el caracter introducido
   if(a=='S'||a=='s')
   {
   printf("modifique su nombre:\n"); //escribe que cambie el nombre
   fgets(usuarios[i].Nomb_usuario, 21, stdin); //lee el nuevo nombre
   printf("modifique su localidad:\n"); //escribe que cambie la localidad
   fgets(usuarios[i].Localidad, 21, stdin); //lee la nueva localidad
   printf("modifique su nombre de usuario (max: 5 caracteres):\n"); //escribe que cambie el nombre de usuario
   fgets(usuarios[i].User, 6, stdin); //lee el nuevo nombre de usuario
   printf("modifique su contrasena (max: 8 caracteres):\n"); //escribe que cambie la contraseña
   fgets(usuarios[i].Login, 9, stdin); //lee la nueva contraseña
   }

}

void perfiles_admin(T_Usuarios *usuarios, int * n) //funcion para las opciones de administrador
{
    int opcion;
  printf("¿Que desea modificar?: 1)Modificar un perfil\n 2)Ver lista de usuarios\n 3)Bloquear usuario\n 4)Desbloquear usuario\n 5)Crear usuario\n 6)Eliminar usuario\n");
  scanf("%i", &opcion); //lee el numero de opcion
  switch (opcion)
  {
  case 1: mod_perfil(T_Usuarios * usuarios, int n, int id);
   break;
  case 2: lista_usuarios(T_Usuarios * usuarios, int n);
   break;
  case 3: bloquear_usuario(T_Usuarios * usuarios, int n, int id);
   break;
  case 4: desbloquear_usuario(T_Usuarios * usuarios, int n, int id);
   break;
  case 5: crear_usuario(T_Usuarios * usuarios,int id);
   break;
  case 6: eliminar_usuario(T_Usuarios * usuarios,int id);
   break
  }
}

void lista_usuarios(T_Usuarios * usuarios, int n) //funcion que muestra la lista de usuarios
{
    int i;
    for (i=0; i < n; i++){
    printf("id: %i - Nombre: %s - Localidad: %s - Perfil: %s - Username: %s - Estado: %s\n", usuarios[i].Id_usuario,usuarios[i].Nomb_usuario,usuarios[i].Localidad,usuarios[i].Perfil_usuario,usuarios[i].User,usuarios[i].Estado);

}

void mod_perfil(T_Usuarios * usuarios, int n, int id) //funcion que permite a un administrador modificar usuarios ajenos

{
    id=pos_id(usuarios, n, id);
    printf("Nuevo nombre del usuario:");
   fgets(usuarios[i].Nomb_usuario, 21, stdin);
    printf("Nueva localidad:");
   fgets(usuarios[i].Localidad, 21, stdin);
    printf("Cambiar a administrador o a usuario:");
   fgets(usuarios[i].Perfil_usuario, 15, stdin);
    printf("Nuevo nombre de usuario (max: 5 caracteres):");
   fgets(usuarios[i].User, 6, stdin);
    printf("Nueva contraseña (max: 8 caracteres):");
   fgets(usuarios[i].Login, 9, stdin);
}

void bloquear_usuario(T_Usuarios * usuarios, int n, int id) //funcion  para bloquear usuarios
{
    int i;
    for (i=0; i < n; i++){
        if (id==usuarios[i].Id_usuario)
            strcpy(usuarios[i].Estado,"bloqueado");
    }
}

void desbloquear_usuario(T_Usuarios * usuarios, int n, int id) //funcion para desbloquear usuario
{
    for (i=0; i < n; i++){
        if (id==usuarios[i].Id_usuario)
            strcpy(usuarios[i].Estado,"activo");
    }
}

int crear_usuario (T_Usuarios ** usuarios,int n, char * perfil) //funcion que crea un nuevo usuario
{
int i, max;
int id;
 T_Usuarios * aux;
 aux = *usuarios;
  char user[6], char contrasena[9], char nombre[21], char localidad[21];
  printf("escriba el nombre de usuario y la contraseña\n");
  introducir_credenciales(user, contrasena);

  for(i=0, max=aux[0].Id_usuario, i<n, i++)
  {
      if (aux[i].Id_usuario>max) max=aux[i].Id_usuarios;
  }
  id=max+1;

 puts("Introduzca su nombre\n");
 fflush(stdin);
 fgets(nombre, 21, stdin);
 puts("introduzca su localidad\n");
 fflush(stdin);
 fgets(localidad, 21, stdin);

*usuarios=(T_Usuarios *)realloc(*usuarios, (*n+1)*sizeof(T_Usuarios))
*n=*n+1;

*(usuarios)[*n+1].id_usuario=id;
strcpy((*(usuarios)[*n+1].Nomb_usuario), nombre);
strcpy((*(usuarios)[*n+1].Localidad), localidad);
strcpy((*(usuarios)[*n+1].Perfil_usuario), perfil);
strcpy((*(usuarios)[*n+1].User), user);
strcpy((*(usuarios)[*n+1].Login), login);
strcpy((*(usuarios)[*n+1].Estado), Activo);
}



void eliminar_usuario (T_Usuarios * usuarios, int *n)
{
int i,id;
printf("introduzca la id del usuario que deseas eliminar:\n");
scanf("%i", &id);
 for(i= id; i< *n-1; i+=1){
        usuarios[i]= usuarios[i+1];
    }
    *n-=1;

}



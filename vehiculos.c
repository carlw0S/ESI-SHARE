#include <stdio.h>
#include <stdin.h>
#include <string.h>

#ifndef T_VEHICULOS_H
#define T_VEHICULOS_H
typedef struct{
  char Id_mat[8];     //matricula del vehiculo
  int Id_usuario;     //id usuario dueno vehiculo
  int Num_plazas;     //numero de plazas disponibles, sin contar conductor
  char Desc_veh[51];  //descripcion del vehiculo, max 50 char.
}T_Vehiculos;
#endif

void usuario_vehiculos(T_Vehiculos *vehiculos, int *n)
{
    int opcion;
    printf("¿Que desea hacer? 1) Ver lista de vehiculos 2) anadir vehiculo 3) eliminar vehiculo\n");
    scanf("%i", &opcion);
    switch (opcion)
    {
    case 1:lista_vehiculos(vehiculos, n);
    break
    case 2:anadir_vehiculo(vehiculos, n);
    break
    case 3:eliminar_tuvehiculo(vehiculos, n);
    break
    }

}

void lista_vehiculos (T_Vehiculos * vehiculos, int n)
{
     int i;
    for (i=0; i < n; i++){
    printf ("matricula: %s - usuario: %i - plazas: %i - descripcion: %s");
}
}


void anadir_vehiculo(T_vehiculos *vehiculos,int n)
{
int i, max;
int id;
 T_Vehiculos * aux;
 aux = *vehiculos;
  char Id_mat[8], int Id_usuario, int num_plazas, char Desc_veh[51];

  for(i=0, max=aux[0].Id_, i<n, i++)
  {
      if (aux[i].Id_usuario>max) max=aux[i].Id_usuarios;
  }
  id=max+1;

 puts("Introduzca la matricula\n");
 fflush(stdin);
 fgets(Id_mat, 8, stdin);
 puts("introduzca la descripcion del vehiculo\n");
 fflush(stdin);
 fgets(Desc_veh, 51, stdin);

*usuarios=(T_Vehiculos *)realloc(*vehiculos, (*n+1)*sizeof(T_Vehiculos))
*n=*n+1;

*(vehiculos)[*n+1].id_usuario=id;
strcpy((*(usuarios)[*n+1].Nomb_usuario), nombre);
strcpy((*(usuarios)[*n+1].Localidad), localidad);
strcpy((*(usuarios)[*n+1].Perfil_usuario), perfil);
}
void eliminar_tuvehiculo(T_Vehiculos *vehiculos, int *n, int Id_usuario);
{
    int n;
    printf("introduzca la matricula de su vehiculo\n");
    scanf("%i", &n);
    if (Id_usuario != vehiculos)
        printf("error: matricula e id no coinciden");
    else
     for(i= id; i< *n-1; i+=1){
        vehiculos[i]= vehiculos[i+1];
    }
    *n-=1;


}

void eliminar_vehiculo(T_vehiculos *vehiculos, int *n)
{
   int i,n;
printf("introduzca la matricula del vehiculo que deseas eliminar:\n");
scanf("%i", &n);
 for(i= id; i< *n-1; i+=1){
        vehiculos[i]= vehiculos[i+1];
    }
    *n-=1;
}

void administrador_vehiculos(T_Vehiculos *vehiculos, int *n)
{
    char opcion;
  printf("¿Que desea hacer?: 1)dar de alta\n 2)dar de baja\n 3)ver lista de vehiculos\n");
  scanf("%i", &opcion);
  switch (opcion)
  {
      case 1: anadir_vehiculo(T_vehiculos *vehiculos,int n)
      break
      case 2:eliminar_vehiculo(T_vehiculos *vehiculos,int n)
      break
      case 3: lista_vehiculos(T_Vehiculos * vehiculos, int n);
      break

  }
}




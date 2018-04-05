#include <stdio.h>
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

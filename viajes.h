#ifndef T_VIAJES_H
#define T_VIAJES_H
typedef struct{
  int Dia;
  int Mes;
  int Ano;
}T_Fecha;

typedef struct{
  int Hora;
  int Minutos;
}T_Hora;

typedef struct{
  int Id_viaje;
  char Id_mat[8];
  T_Fecha F_inic;
  T_Hora H_inic;
  T_Hora H_fin;
  int Plazas_libres;
  int usuarios_unidos;
  char Viaje[7];
  float Importe;
  char Estado[11];
}T_Viajes;
#endif

#ifndef T_PASOS_H
#define T_PASOS_H
typedef struct{
  int Id_viaje;
  char Poblacion[21];
}T_Pasos;
#endif

#ifndef MOD_VIAJ_H
#define MOD_VIAJ_H
//Cabecera: void mod_viaj (T_vehiculos*, T_Usuarios*, T_Viajes*, T_pasos*, int, int, int, int, int);
//Precondici�n: Recibe el vector de usuarios, veh�culos, viajes y pasos.
//              Tambien recibe el n�mero de veh�culos, viajes y pasos existentes; y el id
//              del usuario actual, en ese orden.
//Postconici�n: Dependiendo del tipo de usuario, llamar� a funciones privadas y efectur� las ordenes
//              correspondientes (crear, editar, eliminar o unirse a viajes, etc).

void mod_viaj (T_Vehiculos*, T_Usuarios*, T_Viajes**, T_Pasos**, int, int*, int*, int);

#endif

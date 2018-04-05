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
  char Viaje[7];
  float Importe;
  char Estado[8];
}T_Viajes;
#endif

#ifndef T_PASOS_H
#define T_PASOS_H
typedef struct{
  int Id_viaje;
  char Poblacion[21];
}T_Pasos;
#endif

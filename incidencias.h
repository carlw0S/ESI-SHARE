#ifndef T_INCIDENCIAS_H
#define T_INCIDENCIAS_H
typedef struct
{
  int Id_viaje;           //Id del viaje
  int Id_us_registra;     //Id del usuario que registra la incidecia
  int Id_us_incidencia;   //Id del usuario sobre el que recae la incidencia
  char Desc_incidencia[101];  //Descripcion de la incidencia, max 100 char.
  char Est_incidencia[9]; //Estado de la incidencia (abierta, validada, cerrada)
} T_Incidencias;
#endif

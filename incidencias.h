#ifndef INCIDENCAS_ADMIN_H
#define INCIDENCAS_ADMIN_H
 //cabecera: void incidencias_admin (T_Incidencias ** incidencia, int * NI)
 //precondicion: estructura incidencia inicializada
 //postcondicion: accede como administrador a toda la estructura
void incidencias_admin (T_Incidencias ** incidencia, int * NI);
#endif

#ifndef MOD_INCIDENCIAS_H
#define MOD_INCIDENCIAS_H
//cabecera: void mod_incidencias (T_Incidencias * incidencia, int * NI)
//precondicion: estructura incidencia inicializada
//postcondicion: modifica el estado de una incidencia concreta
void mod_incidencias (T_Incidencias * incidencia, int * NI);
#endif



 #ifndef INCIDENCIAS_USER_H
 #define INCIDENCIAS_USER_H
 //cabecera: void incidencias_user (T_Incidencias ** incidencia, int * NI)
 //precondicion: estructura incidencia inicializada
 //postcondicion: accede como usuario a toda la estructura
  void incidencias_user (T_Incidencias ** incidencia, int * NI);
 #endif

 #ifndef VER_INCIDENCIA_H
 #define VER_INCIDENCIA_H
 //cabecera: void ver_incidencias (T_Incidencias * incidencia)
 //precondicion: estructura incidencia definida
 //postcondicion: mostrara por pantalla todas las incidencias existentes
   void ver_incidencias (T_Incidencias * incidencia, int * NI);
 #endif

 #ifndef CREAR_INCIDENCIA_H
 #define CREAR_INCIDENCIA_H
 //cabecera: void crear_incidencia (T_Incidencias * incidencia, int * NI)
 //precondicion: estructura incidencia definda y recibido el parametro NI
 //postcondicion: se habrá creado una estructura definda por el usuario y se habra incrementado NI
  void crear_incidencia (T_Incidencias ** incidencia, int * NI);
 #endif

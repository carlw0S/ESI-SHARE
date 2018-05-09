#ifndef MOD_VIAJ_H
#define MOD_VIAJ_H
//Cabecera: void mod_viaj (T_vehiculos*, T_Usuarios*, T_Viajes*, T_pasos*, int, int, int, int, int);
//Precondici�n: Recibe el vector de usuarios, veh�culos, y la direccion viajes y pasos.
//              Tambien recibe el n�mero de usuarios, veh�culos, viajes y pasos existentes; y el id
//              del usuario actual, en ese orden.
//Postconici�n: Dependiendo del tipo de usuario, llamar� a funciones privadas y efectur� las ordenes
//              correspondientes (crear, editar, eliminar o unirse a viajes, etc).

void mod_viaj (T_Vehiculos*, T_Usuarios*, T_Viajes**, T_Pasos**, int, int, int*, int*, int);

#endif

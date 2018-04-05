#include "main.h"
int main(){
    T_Usuarios *v_usuarios;
    T_Vehiculos *v_vehiculos;
    T_Viajes *v_viajes;
    T_Pasos *v_pasos;
    T_Incidencias *v_incidencias;

    int N_usuarios, N_vehiculos, N_viajes, N_pasos, N_incidencias;

    v_usuarios=cargar_usuarios(v_usuarios, &N_usuarios);
    v_vehiculos=cargar_vehiculos(v_vehiculos, &N_vehiculos);
    v_viajes=cargar_viajes(v_viajes, &N_viajes);
    v_pasos=cargar_pasos(v_pasos, &N_pasos);
    v_incidencias=cargar_incidencias(v_incidencias, &N_incidencias);


    guardar_usuarios(v_usuarios, N_usuarios);
    guardar_vehiculos(v_vehiculos, N_vehiculos);
    guardar_viajes(v_viajes, N_viajes);
    guardar_pasos(v_pasos, N_pasos);
    guardar_incidencias(v_incidencias, N_incidencias);

    return 0;
}

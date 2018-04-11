#include <stdio.h>

#include "usuarios.h"
#include "vehiculos.h"
#include "viajes.h"
#include "incidencias.h"
#include "cargar_guardar_estructuras.h"
#include "control_inicio.h"

int main(){
    T_Usuarios *v_usuarios;
    T_Vehiculos *v_vehiculos;
    T_Viajes *v_viajes;
    T_Pasos *v_pasos;
    T_Incidencias *v_incidencias;

    int N_usuarios, N_vehiculos, N_viajes, N_pasos, N_incidencias;
    int id_user;

    cargar_usuarios(&v_usuarios, &N_usuarios);
    cargar_vehiculos(&v_vehiculos, &N_vehiculos);
    cargar_viajes(&v_viajes, &N_viajes);
    cargar_pasos(&v_pasos, &N_pasos);
    cargar_incidencias(&v_incidencias, &N_incidencias);

    //comprobacion_horas_viajes();

    titulo();

    id_user=login(v_usuarios, N_usuarios);
    if(id_user < 0) pantalla_err_login(v_usuarios, N_usuarios, &id_user);

    check_usuario_bloqueado(v_usuarios, N_usuarios, &id_user);

    menu_principal(v_usuarios, N_usuarios, id_user);

    guardar_usuarios(v_usuarios, N_usuarios);
    guardar_vehiculos(v_vehiculos, N_vehiculos);
    guardar_viajes(v_viajes, N_viajes);
    guardar_pasos(v_pasos, N_pasos);
    guardar_incidencias(v_incidencias, N_incidencias);

    return 0;
}

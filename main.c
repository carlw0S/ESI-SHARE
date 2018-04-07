#include "main.h"
int main(){
    T_Usuarios *v_usuarios;
    T_Vehiculos *v_vehiculos;
    T_Viajes *v_viajes;
    T_Pasos *v_pasos;
    T_Incidencias *v_incidencias;

    int N_usuarios, N_vehiculos, N_viajes, N_pasos, N_incidencias;
    int id_user;
    int opt;

    v_usuarios=cargar_usuarios(&N_usuarios);
    v_vehiculos=cargar_vehiculos(&N_vehiculos);
    v_viajes=cargar_viajes(&N_viajes);
    v_pasos=cargar_pasos(&N_pasos);
    v_incidencias=cargar_incidencias(&N_incidencias);

    //comprobacion_horas_viajes();

    titulo();

    id_user=login(v_usuarios, N_usuarios);
    if(id_user < 0) pantalla_err_login(v_usuarios, N_usuarios, &id_user);

    if(id_user > 0) do{
      opt=menu_principal(v_usuarios, N_usuarios, id_user);
      switch (opt) {
        case 1:   puts("perfiluser");//perfil_user();
        break;
        case -1:  puts("perfiladmin");//perfil_admin();
        break;
        case 2:   puts("vehiculosuser");//vehiculos_user();
        break;
        case -2:  puts("vehiculosadmin");//vehiculos_admin();
        break;
        case 3:   puts("viajesuser");//viajes_user();
        break;
        case -3:  puts("viajesadmin");//viajes_admin();
        break;
        case 4:   puts("incidenciasuser");//incidencias_user();
        break;
        case -4:  puts("incidencias_admin");//incidencias_admin();
        break;
        case 5: case -5:
        break;
        default: puts("**Esta opcion no existe**");
        break;
      }
      puts("  -->Ha vuelto al menu principal");
    }while(opt!=5&&opt!=-5&&opt);

    guardar_usuarios(v_usuarios, N_usuarios);
    guardar_vehiculos(v_vehiculos, N_vehiculos);
    guardar_viajes(v_viajes, N_viajes);
    guardar_pasos(v_pasos, N_pasos);
    guardar_incidencias(v_incidencias, N_incidencias);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "cargar_guardar_estructuras.h"
#include "control_inicio.h"

//Funciones privadas

//Cabecera:void most_viaj(T_Viajes *, int )
//Precondición: Recibe un vector de viajes y el numero de estos
//Postcondición: Muestra los viajes abierto o iniciados
void most_viaj(T_Viajes *, int );

//Cabecera: void tipo_viaje(T_Viajes **viajes, int num_v)
//Precondición: Recibe la dirección del vector de viajes
//Postcondición:Escoge si el tipo de viaje es de ida o vuelta
void tipo_viaje(T_Viajes **viajes, int num_v);

//Cabecera:void escribir_fecha (T_Viajes**, int)
//Precondición: Recibe la dirección de un vector de viajes, la posición del viaje actual.
//Postcondición: Escribe la fecha y hora de salida del viaje; escribe la hora estimada de
//               llegada. No permite fechas ya pasadas ni horas muy prontas.
void escribir_fecha_hora (T_Viajes**, int);

//Cabecera: int escog_coche (T_Usuarios*, T_Vehiculos*, int, int)
//Precondición: Recibe un vector de usuario y un vector de vehículos ya inicializados.
//Postcondición: Si se encuentra al menos un coche registrado del usuarios, la función
//                devolverá "0". En caso contrario, devolverá 1
int ver_coche (T_Usuarios*, T_Vehiculos*, int, int);

//Cabecera: void escog_coche (T_Usuarios*, T_Vehiculos*, T_Viajes**, int, int, int)
//Precondición: Recibe un vector de usuarios, vehículos y la dirección del vector de
//              viajes. Tambien recibe el numero de vehiculos, la posición viaje actual
//              y la posicion del usuario actual.
//Postcondición: Escoje el coche que se usará en el viaje y selecciona las plazas.
void escog_coche (T_Usuarios*, T_Vehiculos*, T_Viajes**, int, int, int);        //num veh, num viaj y pos id.

//Cabecera: void esc_pas (T_Pasos**, int*, int)
//Precondición: Recibe la dirección de un vector de pasos, el número de estos y la id del
//              viaje actual
//Postcondición: Escribe los pasos en el vector,que se relacionarán con el viaje por la id
void esc_pas (T_Pasos**, int*, int);

//Cabecera:void cr_viaj_u (T_Usuarios*, T_Vehiculos*, T_Viajes**, T_Pasos**, int, int, int*, int*, int)
//Precondición: Recibe vectores de los registros de usuarios, viajes, vehiculos y pasos.
//              también recibe la cantidad de cada vector (excepto del de usuarios) y la
//              posición en el vector del usuario actual.
//Postcondición: Comprueba si hay coches dados de alta del usuario y, en caso afirmativo,
//               crea un nuevo viaje.
void cr_viaj_u (T_Usuarios*, T_Vehiculos*, T_Viajes**, T_Pasos**, int, int*, int*, int);

//Cabecera:cr_viaj_a (T_Usuarios*, T_Vehiculos*, T_viajes**, T_pasos**, int, int, int*, int*)
//Precondición:Recibe vectores de los registros de usuarios, viajes, vehiculos y pasos.
//              también recibe la cantidad de cada vector
//Postcondición: Comprueba si hay coches dados de alta del usuario y, en caso afirmativo,
//               crea un nuevo viaje.
void cr_viaj_a (T_Usuarios*, T_Vehiculos*, T_viajes**, T_pasos**, int, int, int*, int*);

//Cabecera: void ed_viaj_u (T_Usuarios*, T_Vehiculos*, T_Viajes**, T_Pasos**, int, int, int*, int)
//Precondición:Recibe vectores de los registros de usuarios, viajes, vehiculos y pasos.
//              también recibe la cantidad de cada vector (excepto del de usuarios) y la
//              posición en el vector del usuario actual.
//Postcondición: Comprueba el existencia de un viaje. En caso afirmativo, permite la edición
//               En caso de que ya se haya unido una persona, no permite la edición
void ed_viaj_u (T_Usuarios*, T_Vehiculos*, T_viajes**, T_pasos**, int, int, int*, int );

//Cabecera:
//Precondición:Recibe vectores de los registros de usuarios, viajes, vehiculos y pasos.
//              también recibe la cantidad de cada vector.
//Postcondición:Pide un id de usuario y un id de viaje. Si este coincide con el creador del viaje,
//              se le podrá editar.
void ed_viaj_a(T_Usuarios*, T_Vehiculos *vehiculos, T_viajes **viajes, T_pasos **pasos, int num_us, int num_vehic, int *num_viaj, int *num_pas);                        //AUN POR DEFINIR

//Cabecera:void un_viaj(T_Viajes **, int)
//Precondición: Recibe la dirección de un vector de viajes y el numero de estos
//Postcondición: Une al usuario al viaje
void un_viaj(T_Viajes **, int);

//Cabecera:void elim_viaj(T_Viajes **, int )
//Precondición: Recibe la dirección de un vector de viajes y el numero de estos
//Postcondición: Elimina un viaje
void elim_viaj(T_Viajes **, int );

//Cabecera:void inspec_viaj(T_Viajes *, int)
//Precondición: Recibe un vector de viajes y la cantidad de estos
//Postcondición: Da detalles sobre el viaje que el usuario desee
void inspec_viaj(T_Viajes *, int);
//Cabecera:
//Precondición: Recibe un vector de viajes y el numero de estos
//Postcondición:Muestra todos los viajes existentes
void list_viaj(T_Viajes *vi, int numvi);

//Fin de funcionesprivadas

void mod_viaj (T_vehiculos *vehiculos, T_Usuarios *usuarios, T_Viajes **viajes, T_pasos **pasos,
               int num_us, int num_veh, int *num_viaj, int *num_pas int id){
    int pos, op;
    most_viaj(*viajes, *num_viaj);
    if (id>0){
        pos=pos_id(usuarios, num_us, id);
        most_viaj();                                                //AUN POR DEFINIR
        if (strcmp(usuario[pos].Perfil_usuario, "usuario")==0){
            puts("\n \nSeleccione una opcion \n");
            puts("  1-Crear viaje \n");
            puts("  2-Editar mis viajes \n");
            puts("  3-Unirme al viaje \n");
            puts("  4-Inspeccionar un viaje \n");
            puts("  5-Volver al menu \n");
            fflush (stdin);
            do{
                scanf("%i", &op);
                switch (op){
                    case 1: cr_viaj_u(usuarios, vehiculos, viajes, pasos, num_veh, num_viaj, num_pas, pos);
                    break;
                    case 2: ed_viaj_u(usuarios, vehiculos, viajes, pasos, num_veh, *num_viaj, num_pas, pos);
                    break;
                    case 3: un_viaj(viajes, *num_viaj);
                    break;
                    case 4: inspec_viaj(*viajes, *pasos, *num_viaj, *num_pas);
                    break;
                    case 5: return;
                    break;
                    default: printf("Opcion no existente");
                    break;
                }
            }while (op<1&&op>5);
        }else{
            puts("\n \nSeleccione una opcion \n");
            puts("  1-Crear viaje \n");
            puts("  2-Editar viaje \n");
            puts("  3-Eliminar viaje \n");
            puts("  4-Listar viajes \n");
            puts("  5-Volver al menu \n");
            fflush (stdin);
            scanf("%i", &op);
            do{
                scanf("%i", &op);
                switch (op){
                    case 1: cr_viaj_a(usuarios, vehiculos, viajes, pasos, num_us, num_veh, num_viaj, num_pas);
                    break;
                    case 2: ed_viaj_a(usuarios, vehiculos, viajes, pasos, num_us, num_veh, *num_viaj, num_pas);
                    break;
                    case 3: elim_viaj(viajes, );
                    break;
                    case 4: list_viaj(*viajes, *num_viaj);
                    break;
                    case 5: return;
                    break;
                    default: printf("Opcion no existente");
                    break;
                }
            }while (op<1&&op>5);
        }
    }
}

//IMPLEMENTACIÓN FUNCIONES PRIVADAS

void cr_viaj_u (T_Usuarios *usuarios, T_Vehiculos *vehiculos, T_viajes **viajes, T_pasos **pasos,
               int num_vehic, int *num_viaj, int *num_pas, int pos){
    T_Viajes *aux_v;
    T_Pasos *aux_p;
    int nueva_id, hay_v;
    float din;
    hay_v= ver_coche(usuarios, vehiculos, num_vehic, pos);
    if (hay_v==1){
        printf("\nNo se ha encontrado ningún coche registrado");
        printf("\nVolviendo al menu principal");
        return;
    }
    aux_v=*viajes;
    *num_viaj=*num_viaj+1;
    aux_v=(T_Viajes*) realloc (*aux_v, (*num_viaj)*sizeof(T_Viajes));
    if (aux_v==NULL) {
        printf("\nError de asignación de memoria");
        exit(1);
    }
    else{
        nueva_id=(aux_v[*num_viaj].Id_viaje)+1;
        aux_v[*num_viaj].Id_viaje=nueva_id;
        *viajes= aux_v;
        *pasos= aux_p;
        tipo_viaje(viajes, *num_viaj);
        esc_pas(pasos, num_pas, nueva_id);
        escog_coche(usuarios, vehiculos, viajes, num_vehic, *num_viaj, pos);
        printf("\n")
        printf("\nEscoja fecha y hora de salida, y hora estimada de llegada");
        escribir_fecha_hora(viajes, *num_viaj);
        aux_v[*num_viaj].Importe= din;
        strcpy(aux_v[*num_viaj].Estado, "abierto");
        aux_v[*num_viaj].usuarios_unidos=0;
        *viajes=aux_v;
        printf("\nEl viaje ha sido creado con exito");
    }
}

void cr_viaj_a(T_Usuarios *usuarios, T_Vehiculos *vehiculos, T_viajes **viajes, T_pasos **pasos,
               int num_us, int num_vehic, int *num_viaj, int *num_pas){
    T_Viajes *aux_v;
    T_Pasos *aux_p;
    int nueva_id, id, pos, hay_v, i, j, aux;
    float din;
    printf("\n\nEscriba la id del usuario al que se le editara el viaje");
    scanf("%d", &id);
    for(i=0, j=0; i<num_us&&j==1; i++){
        if(id==usuarios[i].Id_usuario){
            printf("\nUsuario encontrado: %s\nEs este el usuario deseado?\n\n1-Si \n\n2-No", usuarios[i].Nomb_usuario)
            do{
               scanf("%d", &aux);
               switch (aux){
                    case 1: printf("\n\nSe ha seleccionado al usuario.");
                            pos=i;
                            j==1;
                    break;
                    case 2: printf("\n\nEscoja otra id");
                            scanf("%d", &id);
                            i=0;
                    break;
                    default:: printf("\n\nOpcion incorrecta.");
                    break;
               }
            }while (aux!=1||aux!=2);
        }
        if (i==num_us){
            printf("\n\nNo se ha encontrado al usuario. Intentelo de nuevo.");
            scanf("%d", &id);
            i=0;
        }
    }
    hay_v= ver_coche(usuarios, vehiculos, num_vehic, pos);
    if (hay_v==1){
        printf("\nNo se ha encontrado ningún coche registrado para este usuario.");
        printf("\nVolviendo al menu principal");
        return;
    }
    aux_v=*viajes;
    *num_viaj=*num_viaj+1;
    aux_v=(T_Viajes*) realloc (*aux_v, (*num_viaj)*sizeof(T_Viajes));
    if (aux_v==NULL) {
        printf("\nError de asignación de memoria");
        exit(1);
    }
    else{
        nueva_id=(aux_v[*num_viaj].Id_viaje)+1;
        aux_v[*num_viaj].Id_viaje=nueva_id;
        *viajes= aux_v;
        *pasos= aux_p;
        tipo_viaje(viajes, *num_viaj);
        esc_pas(pasos, num_pas, nueva_id);
        escog_coche(usuarios, vehiculos, viajes, num_vehic, *num_viaj, pos);
        printf("\n")
        printf("\nEscoja fecha y hora de salida, y hora estimada de llegada");
        escribir_fecha_hora(viajes, *num_viaj);
        aux_v[*num_viaj].Importe= din;
        strcpy(aux_v[*num_viaj].Estado, "abierto");
        aux_v[*num_viaj].usuarios_unidos=0;
        *viajes=aux_v;
        printf("\nEl viaje ha sido creado con exito");
    }
}

void ed_viaj_u(T_Usuarios *usuarios, T_Vehiculos *vehiculos, T_viajes **viajes, T_pasos **pasos,
               int num_vehic, int num_viaj, int *num_pas, int pos){
    T_Viajes *aux_vi;
    int i, j, id_viaj, pos_vi, aux;
    float impo;
    aux_vi=*viajes;
    printf("\n\nEscriba el id del viaje a editar");
    scanf("%d", &id_viaj);
    for(i=0, j=0; i<num_viaj&&j==1; i++){
        if(id_viaj==aux_vi[i].Id_viaje){
            printf("\nViaje encontrado");
            pos_vi=i;
            j=1;
        }
        if (i==num_viaj){
            printf("\n\nNo se ha encontrado el viaje. Volviendo al menu");
            return;
        }
    }
    if (aux_vi[pos_vi].usuarios_unidos>1){
        printf("\n\nNo se puede editar el viaje porque ya hay al menos un usuario dentro.\n\nVolviendo al menu");
        return;
    }
    for (i=0; i<num_vehic; i++){
        if (usuarios[pos].Id_usuario==vehiculos[i].Id_usuario){
            if (strcmp(vehiculos[i].Id_mat, aux_vi[pos_vi].Id_mat)==0){
                printf("\n\nElija una opcion");
                printf("\n\n1-Cambiar coche");
                printf("\n\n2-Cambiar fechas y horas");
                printf("\n\n3-Cambiar el tipo de viaje");
                printf("\n\n4-Cambiar importe");
                printf("\n\n5-Anadir pasos");
                do{
                    scanf("%d", &aux);
                    switch (aux){
                    case 1: escog_coche(usuarios, vehiculos, aux_vi, num_vehic, pos_vi, pos);
                        break;
                    case 2: escribir_fecha_hora(aux_vi, pos_vi);
                        break;
                    case 3: tipo_viaje(viajes, pos_vi);
                        break;
                    case 4:
                        printf("\n\nTeclee el nuevo importe");
                        scanf("%f", &impo);
                        aux_vi[pos_vi].Importe=impo;
                        break;
                    case 5: esc_pas(pasos, num_pas, id_viaj);
                        break;
                    default: printf("\n\nOpcion erronea, intentelo de nuevo");
                        break;
                    }
                }while (aux<1||aux>5);
                *viajes=aux_vi;
                printf("\n\nSe ha editado el viaje");
                return;
            }
        }
    }
}

void ed_viaj_a(T_Usuarios *usuarios, T_Vehiculos *vehiculos, T_viajes **viajes, T_pasos **pasos,
               int num_us, int num_vehic, int *num_viaj, int *num_pas){
    T_Viajes *aux_vi;
    int i, j, id_viaj, pos_vi, pos, aux;
    float impo;
    aux_vi=*viajes;
    printf("\n\nEscriba la id del usuario al que se le editara el viaje");
    scanf("%d", &id);
    for(i=0, j=0; i<num_us&&j==1; i++){
        if(id==usuarios[i].Id_usuario){
            printf("\nUsuario encontrado: %s\nEs este el usuario deseado?\n\n1-Si \n\n2-No", usuarios[i].Nomb_usuario)
            do{
               scanf("%d", &aux);
               switch (aux){
                    case 1: printf("\n\nSe ha seleccionado al usuario.");
                            pos=i;
                            j==1;
                    break;
                    case 2: printf("\n\nEscoja otra id");
                            scanf("%d", &id);
                            i=0;
                    break;
                    default:: printf("\n\nOpcion incorrecta.");
                    break;
               }
            }while (aux!=1||aux!=2);
        }
        if (i==num_us){
            printf("\n\nNo se ha encontrado al usuario. Intentelo de nuevo.");
            scanf("%d", &id);
            i=0;
        }
    }
    printf("\n\nEscriba el id del viaje a editar");
    scanf("%d", &id_viaj);
    for(i=0, j=0; i<num_viaj&&j==1; i++){
        if(id_viaj==aux_vi[i].Id_viaje){
            printf("\nViaje encontrado");
            pos_vi=i;
            j=1;
        }
        if (i==num_viaj){
            printf("\n\nNo se ha encontrado el viaje. Volviendo al menu");
            return;
        }
    }
    if (aux_vi[pos_vi].usuarios_unidos>1){
        printf("\n\nNo se puede editar el viaje porque ya hay al menos un usuario dentro.\n\nVolviendo al menu");
        return;
    }
    for (i=0; i<num_vehic; i++){
        if (usuarios[pos].Id_usuario==vehiculos[i].Id_usuario){
            if (strcmp(vehiculos[i].Id_mat, aux_vi[pos_vi].Id_mat)==0){
                printf("\n\nElija una opcion");
                printf("\n\n1-Cambiar coche");
                printf("\n\n2-Cambiar fechas y horas");
                printf("\n\n3-Cambiar el tipo de viaje");
                printf("\n\n4-Cambiar importe");
                printf("\n\n5-Anadir pasos");
                do{
                    scanf("%d", &aux);
                    switch (aux){
                    case 1: escog_coche(usuarios, vehiculos, aux_vi, num_vehic, pos_vi, pos);
                        break;
                    case 2: escribir_fecha_hora(aux_vi, pos_vi);
                        break;
                    case 3: tipo_viaje(viajes, pos_vi);
                        break;
                    case 4:
                        printf("\n\nTeclee el nuevo importe");
                        scanf("%i", &impo);
                        aux_vi[pos_vi].Importe=impo;
                        break;
                    case 5: esc_pas(pasos, num_pas, id_viaj);
                        break;
                    default: printf("\n\nOpcion erronea, intentelo de nuevo");
                        break;
                    }
                }while (aux<1||aux>5);
                *viajes=aux_vi;
                printf("\n\nSe ha editado el viaje");
                return;
            }
        }
    }
}

void un_viaj(T_Viajes **vi, int num_viaj){
    T_Viajes *aux_v;
    int, id, pos_v, i, j;
    aux_v= *vi;
    printf("\n\nEcriba la id del viaje al que se quiera unir");
    scanf("%i", &id);
    for (i=0, j=0; i<num_viaj&&j==1; i++){
        if (aux_v[i].Id_viaje==id){
            pos_v=i;
            j=1
        }
        if (i==num_viaj){
            printf("\n\nNo se ha encontrado el viaje. Intentelo de nuevo");
            scanf("%i", &id);
            i=0;
        }
    }
    if (aux_v[pos_v].Plazas_libres==aux_v[pos_v].usuarios_unidos){
        printf("\n\nTodas las plazas estan llenas, no se puede unir");
        return;
    }
    else{
       aux_v[pos_v].usuarios_unidos=aux_v[pos_v].usuarios_unidos+1;
    }
    *vi=aux_v;
    printf("\n\nUnido al viaje con exito");
}

void inspec_viaj(T_Viajes *viajes, T_Pasos *pas, int numvi, int nump){
    int i, j, id_viaj, pos_vi;
    T_Viajes *aux_v;
    aux_v=vi;
    printf("\n\nEscriba el id del viaje que quiere inspeccionar");
    scanf("%i", &id_viaj);
    for(i=0, j=0; i<numvi&&j==1; i++){
        if(id_viaj==aux_vi[i].Id_viaje){
            printf("\nViaje encontrado");
            pos_vi=i;
            j=1;
        }
        if (i==numvi){
            printf("\n\nNo se ha encontrado el viaje. Volviendo al menu");
            return;
        }
    }
    printf("\n\n--Id: %i ", aux_v[pos_vi].Id_viaje);
    printf("\n\n--Matricula del vehiculo: %s", aux_v[pos_vi].Id_mat);
    printf("\n\n--Fecha: %i/%i/%i ", aux_v[pos_vi].F_inic.Dia, aux_v[pos_vi].F_inic.Mes, aux_v[pos_vi].F_inic.Ano);
    printf("\n\n--Hora de salida: %i:%i ", aux_v[pos_vi].H_inic.Hora, aux_v[pos_vi].H_inic.Minutos);
    printf("\n\n-Hora de llegada: %i:%i ", aux_v[pos_vi].H_fin.Hora, aux_v[pos_vi].H_fin.Minutos);
    printf("\n\n--Plazas: %i ", aux_v[pos_vi].Plazas_libres);
    printf("\n\n--Usuarios unidos: %i ", aux_v[pos_vi].usuarios_unidos);
    printf("\n\n--Tipo de viaje: %s", aux_v[pos_vi].Viaje);
    printf("\n\n--Importe: %f", aux_v[pos_vi].Importe);
    printf("\n\n--Estado: %s", aux_v[pos_vi].Estado);
    printf("\n\n--Pasos:")
    for (i=0; i<nump; i++){
        if (pas[i].Id_viaje==aux_v[pos_vi].Id_viaje){
            printf("\n %s", pas[i].Poblacion);
        }
    }
}

void most_viaj(T_Viajes *vi, int numv){
    int, i;
    printf("\n\n============Lista de viajes============");
    for (i=0, j=0; i<numv; i++){
        if (strcmp(vi[i].Estado, "abierto")==0||strcmp(vi[i].Estado, "iniciado")==0){
            printf("\n\n--Id: %i ", vi[i].Id_viaje);
            printf("\n\n--Fecha: %i/%i/%i ", vi[i].F_inic.Dia, vi[i].F_inic.Mes, vi[i].F_inic.Ano);
            printf("\n\n--Hora de salida: %i:%i ", vi[i].H_inic.Hora, vi[i].H_inic.Minutos);
            printf("\n\n-Hora de llegada: %i:%i ", vi[i].H_fin.Hora, vi[i].H_fin.Minutos);
            printf("\n\n--Plazas: %i ", vi[i].Plazas_libres);
            printf("\n\n--Tipo de viaje: %s", vi[i].Viaje);
            printf("\n\n--Importe: %f \n\n", vi[i].Importe);
        }
    }
    printf("\n\n=======================================");
}

void elim_viaj(T_Viajes **viaj, int num_vj){
    int i, id_v, pos;
    T_Viajes *aux_v;
    printf("\n\nEscriba el id del viaje a eliminar");
    do{
        scanf("%i", &id_v);
        for(i=0; i<num_vj; i++){
            if (id_v==aux_v[i].Id_viaje){
                pos=i;
                printf("\nSe borrara el viaje");
                aux_v[pos].Id_viaje=0;
                aux_v[pos].H_inic.Hora=0;
                aux_v[pos].H_inic.Minutos=0;
                aux_v[pos].H_fin.Hora=0;
                aux_v[pos].H_fin.Minutos=0;
                aux_v[pos].F_inic.Ano=0;
                aux_v[pos].F_inic.Mes=0;
                aux_v[pos].F_inic.Dia=0;
                aux_v[pos].Plazas_libres=0;
                aux_v[pos].usuarios_unidos=0;
                aux_v[pos].Importe=0;
                strcpy(aux_v[pos].Id_mat, "");
                strcpy(aux_v[pos].Viaje, "");
                strcpy(aux_v[pos].Estado, "");
            }
        }
    }
    *viaj=aux_v;
    printf("\n\nSe ha borrado el viaje con exito");
}

void list_viaj(T_Viajes *vi, int numvi){
    int i, j;
    for (i=0; i<numvi; i++){
        printf("\n\n--Id: %i ", vi[i].Id_viaje);
        printf("\n\n--Fecha: %i/%i/%i ", vi[i].F_inic.Dia, vi[i].F_inic.Mes, vi[i].F_inic.Ano);
        printf("\n\n--Hora de salida: %i:%i ", vi[i].H_inic.Hora, vi[i].H_inic.Minutos);
        printf("\n\n-Hora de llegada: %i:%i ", vi[i].H_fin.Hora, vi[i].H_fin.Minutos);
        printf("\n\n--Plazas: %i ", vi[i].Plazas_libres);
        printf("\n\n--Tipo de viaje: %s", vi[i].Viaje);
        printf("\n\n--Importe: %f ", vi[i].Importe);
        printf("\n\n--Estado: %s \n\n", vi[i].Estado);
    }
}

int ver_coche(T_Usuarios *us, T_Vehiculos *vh, int numv, int pos){
    int i ;
    for (i=0; i<numv; i++){
        if (strcmp(us[pos].Id_usuario, vh[i].Id_usuario)==0) return 0;
        else {
            if (numv==(i+1)) return 1;
        }
    }
}

void tipo_viaje(T_Viajes **viajes, int num_v){
    int aux;
    T_Viajes *aux_v;
    aux_v=*viajes;
    printf("\nEscoja el tipo de viaje: \n1-Ida \n2-Vuelta");
        do{
            scanf("%i", &aux);
            switch (aux){
                case 1: strcpy(aux_v[num_v].Viaje, "ida");
                break;
                case 2: strcpy(aux_v[num_v].Viaje, "vuelta");
                break;
                default: printf("\nOpcion erronea. Intente otra vez");
                break;
            }
        }while (aux!=1&&aux!=2);
    printf("\n\nTipo de viaje añadido con exito");
    *viajes=aux_v;
}

void esc_pas(T_Pasos **pasos, int* num_pas, int id){
    T_pasos *aux_p;
    char aux_str[21];
    int selec;
    aux_p=*pasos;
    *num_pas=*num_pas+1;
    aux_p= (T_Pasos*) realloc(aux_p, (*num_pas)*sizeof(T_Pasos));
    aux_p[*num_pas].Id_viaje=id;
    printf("\n Escriba por qué pueblos pasara");
    scanf("%s" &aux_str);
    strcpy(aux_p[*num_pas].Poblacion, aux_str);
    printf("\nDesea añadir más pasos? Escoja una opcion con el numero. \n1-Si \n2-No");
    do{
        scanf("%i", %selec);
        switch (selec){
            case 1: esc_pas(pasos, num_pas, id);
            break;
            case 2: printf("\nSe ha/han añadido el/los paso/s con exito");
            default: printf("\nOpcion erronea. Intente otra vez.");
            break;
        }
    }while (selec!=1&&selec!=2);
    *pasos=aux_p;
    return;
}

void escog_coche(T_usuarios *us, T_Vehiculos *veh, T_Viajes **vi, int nveh, int pos_v, int pos_u){
    int i, j=1, aux, plazas;
    char aux_string_1[8];
    T_Viajes *aux_vi;
    aux_vi=*vi;
    printf("\n=============Lista de coches=============");
    for (i=0; i<nveh; i++){
        if (strcmp(us[pos_u].Id_usuario, veh[i].Id_usuario)==0){
            printf("\n\n%i- Matricula: %s \nDescripcion: %s", j, veh[i].Id_mat, veh[i].Desc_veh);
            j++;
        }
    }
    printf("\n=========================================");
    printf("\nEscriba la matricula del coche que desee usar exactamente como aparece en pantalla.");
    do{
        scanf("%s", &aux_string_1);
        for (i=0; i<nveh; i++){
            aux=strcmp(aux_string_1, veh[i].Id_mat);
            if (aux==0) {
                strcpy(aux_vi[pos_v].Id_mat, veh[i].Id_mat);
            j=i;
            }
        }
        if (aux!=0) printf("\nNo se ha encontrado la matricula introducida, intentelo de nuevo.");
    } while (aux!=0);
    printf("\nSe ha seleccionado el coche con la matricula %s", veh[j].Id_mat);
    aux_vi[pos_v].Plazas_libres= veh[j].Num_plazas;
    printf("\nSe han asignado %i plazas libres por defecto. Desea cambiar las plazas? \nEscoja con el numero \n\n1-Si \n2-No", aux_vi[pos_v].Plazas_libres);
    do{
        scanf("%i", &aux);
        switch (aux){
            case 1:
                printf("\n\nIntroduzca el numero de plazas libres deseado");
                scanf("%i", &plazas);
                while(plazas>aux_vi[pos_v].Plazas_libres){
                    printf("\nNo se pueden colocar más plazas que las existentes en el vehiculo. Intentelo de nuevo.");
                    scanf("%i", &plazas);
                }
                aux_vi[pos_v].Plazas_libres=plazas;
                printf("\n\nSe han asignado las plazas correctamente");
            break;
            case 2:
                printf("\n\nSe han asignado las plazas correctamente");
            break;
            default: printf("\n\nOpcion erronea. Intentelo otra vez")
            break;
        }
    }while(aux!=1&&aux!=2);
    *vi=aux_vi;
    return;
}

void escribir_fecha_hora(T_Viajes **vi, int pos_vi){
    int dia, mes, anyo, hora, minutos, aux;
    T_Viajes *aux_vi;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    axu_vi=*vi;
    printf("\n\nEscriba el año de salida (no puede crear viajes para dentro de dos años)");
    scanf("%d", &anyo);
    while (anyo<tm.tm_year||anyo>tm.tm_year+1){
        printf("\n\nFecha erronea. Intentelo de nuevo.");
        scanf("%d", &anyo);
    }
    aux_vi[pos_vi].F_inic.Ano=anyo;
    printf("\n\nEscriba el numero del mes de salida");
    scanf("%d", &mes);
    while (mes<tm.tm_mon||mes>12){
        printf("\n\nFecha erronea. Intentelo de nuevo.");
        scanf("%d", &mes);
    }
    aux_vi[pos_vi].F_inic.Mes=mes;
    printf("\n\nEscriba la fecha del dia");
    scanf("%d", &dia);
    while (dia<tm.tm_mday||dia>31){
        printf("\n\nFecha erronea. Intentelo de nuevo.");
        scanf("%d", &dia);
    }
    while ((mes==4||mes==6||mes==9||mes==11)&&(dia>30||dia<tm.tm_mday)){
        printf("\n\nFecha erronea. Intentelo de nuevo.");
        scanf("%d", &dia);
    }
    while (mes==2&&(dia>28||dia<tm.tm_mday)){
        if (anyo/4!=0&&dia>28){
            printf("\n\nFecha erronea. Intentelo de nuevo.");
            scanf("%d", &dia);
        }
        if (anyo/4==0&&dia>29){
            printf("\n\nFecha erronea. Intentelo de nuevo.");
            scanf("%d", &dia);
        }
    }
    aux_vi[pos_vi].F_inic.Dia=dia;
    printf("\n\nEscriba la hora de salida");
    scanf("%d", &hora);
    do{
        while (hora>24||hora<0){
            printf("Hora no valida. Intentelo de nuevo");
            scanf("%d", &hora);
        }
        while (anyo==tm.tm_year&&mes==tm.tm_mon&&dia==tm.tm_mday&&hora<tm.tm_hour+1){
            printf("\n\nLa hora escogida ya paso o es muy pronta. Intentelo de nuevo");
            scanf("%d", &hora);
        }
    } while (hora>24||hora<0);
    aux_vi[pos_vi].H_inic.Hora=hora;
    printf("\n\nEscriba el/los minutos de salida");
    scanf("%d", &minutos);
    do{
        while (minutos>59||minutos<0){
            printf("Minuto/s no valido/s. Intentelo de nuevo");
            scanf("%d", &minutos);
        }
        while (anyo==tm.tm_year&&mes==tm.tm_mon&&dia==tm.tm_mday&&hora==tm.tm_hour+1&&(minutos-tm.tm_min>0))){
            printf("\n\nLos minutos escogidos ya pasaron o son muy pronts. Intentelo de nuevo");
            scanf("%d", &minutos);
        }
    } while (minutos>59||minutos<0);
    aux_vi[pos_vi].H_inic.Minutos=minutos;
    printf("\n\nEscriba la hora estimada de llegada")
    scanf("%d", &hora);
    do{
        while (hora>24||hora<0){
            printf("Hora no valida. Intentelo de nuevo");
            scanf("%d", &hora);
        }
        while (anyo==tm.tm_year&&mes==tm.tm_mon&&dia==tm.tm_mday&&hora<aux_vi[pos_vi].H_inic.Hora){
            printf("\n\nLa hora escogida no es valida. Intentelo de nuevo");
            scanf("%d", &hora);
        }
    } while (hora>24||hora<0);
    aux_vi[pos_vi].H_fin.Hora=hora;
    printf("\n\nEscriba lel/los minuto/s estimado/s de llegada")
    scanf("%d", &minutos);
    do{
        while (minutos>59||minutos<0){
            printf("Minuto/s no valido/s. Intentelo de nuevo");
            scanf("%d", &minutos);
        }
        while (anyo==tm.tm_year&&mes==tm.tm_mon&&dia==tm.tm_mday&&hora==aux_vi[pos_vi].H_inic.Hora&&(minutos<aux_vi[pos_vi].H_inic.Minutos))){
            printf("\n\nLos minutos escogidos ya pasaron o son muy pronts. Intentelo de nuevo");
            scanf("%d", &minutos);
        }
    } while (minutos>59||minutos<0);
    aux_vi[pos_vi].H_fin.Minutos=minutos;
    *vi=aux_vi;
    printf("\n\nSe han añadido la fecha y hora de salida y llegada exitosamente");
    return;
}

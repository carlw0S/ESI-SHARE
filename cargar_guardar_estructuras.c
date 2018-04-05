#include "cargar_guardar_estructuras.h"

/* Como todas las funciones cargar son casi iguales, solo que cambia lo que
carga, voy a comentar solo cargar_usuarios() ya que el comentario de las demas
es similar*/

T_Usuarios * cargar_usuarios(T_Usuarios *usuarios, int *N){
  //apertura de fichero en lectura y escritura
  FILE* fichero;
  fichero = fopen("usuarios.txt", "r+");
  if(fichero==NULL){
    puts("No se puede abrir el fichero");
    exit(1);
  }
  //reserva de espacio de tantos elementos como lineas haya en el fichero
  *N=contar_elementos_fichero(fichero);
  usuarios=(T_Usuarios *)malloc((*N)*sizeof(T_Usuarios));
  if(usuarios==NULL){
    puts("Error en la reserva de memoria");
    exit(1);
  }

  int i=0;
  char auxstring[100];  //cadena auxiliar
  do {
    fgets(auxstring, 100, fichero); //guardo una linea del fichero en auxstrin

    intercambiar_espacios(auxstring); /*para que luego pueda usar sscanf de
                  manera sencilla, intercambio los guiones por espacios para que
                  el sscanf diferencie las distintas cadenas de caracteres. Para
                  más detalles mirar el comentario de esta funcion en concreto*/

    //Leo los datos de las cadenas y los guardo en sus respectivos lugares
    sscanf(auxstring, "%i %s %s %s %s %s %s", &(usuarios[i].Id_usuario)
                                          ,usuarios[i].Nomb_usuario
                                          , usuarios[i].Localidad
                                        , usuarios[i].Perfil_usuario
                                          , usuarios[i].User, usuarios[i].Login
                                          , usuarios[i].Estado);

    //Vuelvo atras los cambios en los espacios realizados para usar sscanf
    intercambiar_espacios(usuarios[i].Nomb_usuario);
    intercambiar_espacios(usuarios[i].Localidad);
    intercambiar_espacios(usuarios[i].Perfil_usuario);
    intercambiar_espacios(usuarios[i].User);
    intercambiar_espacios(usuarios[i].Login);
    intercambiar_espacios(usuarios[i].Estado);

    i++;
  } while(i<*N);  //repito esta secuencia hasta que acabe el fichero

  fclose(fichero);  //cierro el fichero

  return usuarios;  //devuelvo la direccion de memoria en la que estan todos los
                    //datos cargados.
}


T_Vehiculos * cargar_vehiculos(T_Vehiculos *vehiculos, int *N){
  FILE* fichero;
  fichero = fopen("vehiculos.txt", "r+");
  if(fichero==NULL){
    puts("No se puede abrir el fichero");
    exit(1);
  }
  *N=contar_elementos_fichero(fichero);
  vehiculos=(T_Vehiculos *)malloc((*N)*sizeof(T_Vehiculos));
  if(vehiculos==NULL){
    puts("Error en la reserva de memoria");
    exit(1);
  }

  int i=0;
  char auxstring[100];
  do {
    fgets(auxstring, 100, fichero);

    intercambiar_espacios(auxstring);

    sscanf(auxstring, "%s %i %i %s", vehiculos[i].Id_mat
                                    , &(vehiculos[i].Id_usuario)
                                    ,&(vehiculos[i].Num_plazas)
                                    , vehiculos[i].Desc_veh);

    intercambiar_espacios(vehiculos[i].Id_mat);
    intercambiar_espacios(vehiculos[i].Desc_veh);

    i++;
  } while(i<*N);

  fclose(fichero);

  return vehiculos;
}

T_Viajes * cargar_viajes(T_Viajes *viajes, int *N){
  FILE* fichero;
  fichero = fopen("viajes.txt", "r+");
  if(fichero==NULL){
    puts("No se puede abrir el fichero");
    exit(1);
  }

  *N=contar_elementos_fichero(fichero);
  viajes=(T_Viajes *)malloc((*N)*sizeof(T_Viajes));
  if(viajes==NULL){
    puts("Error en la reserva de memoria");
    exit(1);
  }

  int i=0;
  char auxstring[100];
  do {
    fgets(auxstring, 100, fichero);
    
    intercambiar_espacios(auxstring);

    sscanf(auxstring, "%i %s %i %i %i %i %i %i %i %i %s %f %s"
                    , &viajes[i].Id_viaje, viajes[i].Id_mat
                    , &viajes[i].F_inic.Dia, &viajes[i].F_inic.Mes
                    , &viajes[i].F_inic.Ano, &viajes[i].H_inic.Hora
                    , &viajes[i].H_inic.Minutos, &viajes[i].H_fin.Hora
                    , &viajes[i].H_fin.Minutos, &viajes[i].Plazas_libres
                    , viajes[i].Viaje, &viajes[i].Importe, viajes[i].Estado);

    intercambiar_espacios(viajes[i].Id_mat);
    intercambiar_espacios(viajes[i].Viaje);
    intercambiar_espacios(viajes[i].Estado);

    i++;
  } while(i<*N);

  return viajes;
}

T_Pasos * cargar_pasos(T_Pasos *pasos, int *N){
  FILE* fichero;
  fichero = fopen("pasos.txt", "r+");
  if(fichero==NULL){
    puts("No se puede abrir el fichero");
    exit(1);
  }

  *N=contar_elementos_fichero(fichero);
  pasos=(T_Pasos *)malloc((*N)*sizeof(T_Pasos));
  if(pasos==NULL){
    puts("Error en la reserva de memoria");
    exit(1);
  }

  int i=0;
  char auxstring[50];
  do {
    fgets(auxstring, 50, fichero);

    intercambiar_espacios(auxstring);

    sscanf(auxstring, "%i %s", &(pasos[i].Id_viaje), pasos[i].Poblacion);

    intercambiar_espacios(pasos[i].Poblacion);

    i++;
  } while(i<*N);

  fclose(fichero);

  return pasos;
}

T_Incidencias * cargar_incidencias(T_Incidencias *incidencias, int *N){
  FILE* fichero;
  fichero = fopen("incidencias.txt", "r+");
  if(fichero==NULL){
    puts("No se puede abrir el fichero");
    exit(1);
  }

  *N=contar_elementos_fichero(fichero);
  incidencias=(T_Incidencias *)malloc((*N)*sizeof(T_Incidencias));
  if(incidencias==NULL){
    puts("Error en la reserva de memoria");
    exit(1);
  }

  int i=0;
  char auxstring[150];
  do {
    fgets(auxstring, 150, fichero);

    intercambiar_espacios(auxstring);

    sscanf(auxstring, "%i %i %i %s %s", &(incidencias[i].Id_viaje)
                                    , &(incidencias[i].Id_us_registra)
                                    , &(incidencias[i].Id_us_incidencia)
                                    , incidencias[i].Desc_incidencia
                                    , incidencias[i].Est_incidencia);

    intercambiar_espacios(incidencias[i].Desc_incidencia);
    intercambiar_espacios(incidencias[i].Est_incidencia);

    i++;
  } while(i<*N);

  fclose(fichero);

  return incidencias;
}
/*
####################  GUARDAR   ######################################
*/

void guardar_usuarios(T_Usuarios *usuarios, int N){
  FILE * fichero;
  fichero = fopen("usuarios.txt", "w");
  if(fichero == NULL){
    puts("Error al abrir el fichero");
    exit(1);
  }

  int i;
  for(i=0; i<N; i++){
    fprintf(fichero, "%.4i-%s-%s-%s-%s-%s-%s\n", usuarios[i].Id_usuario
                                              , usuarios[i].Nomb_usuario
                                              , usuarios[i].Localidad
                                              , usuarios[i].Perfil_usuario
                                              , usuarios[i].User
                                              , usuarios[i].Login
                                              , usuarios[i].Estado);
  }

  fclose(fichero);

  free(usuarios);
}

void guardar_vehiculos(T_Vehiculos *vehiculos, int N){
  FILE * fichero;
  fichero = fopen("vehiculos.txt", "w");
  if(fichero == NULL){
    puts("Error al abrir el fichero");
    exit(1);
  }

  int i;
  for(i=0; i<N; i++){
    fprintf(fichero, "%s-%.4i-%i-%s\n", vehiculos[i].Id_mat
                                    , vehiculos[i].Id_usuario
                                    , vehiculos[i].Num_plazas
                                    , vehiculos[i].Desc_veh);
  }

  fclose(fichero);

  free(vehiculos);
}

void guardar_viajes(T_Viajes *viajes, int N){
  FILE * fichero;
  fichero = fopen("viajes.txt", "w");
  if(fichero == NULL){
    puts("Error al abrir el fichero");
    exit(1);
  }

  int i;
  for(i=0; i<N; i++){
    fprintf(fichero, "%.6i-%s-%.2i/%.2i/%.2i-%.2i:%.2i-%.2i:%.2i-%i-%s-%g-%s\n"
                          , viajes[i].Id_viaje, viajes[i].Id_mat
                          , viajes[i].F_inic.Dia, viajes[i].F_inic.Mes
                          , viajes[i].F_inic.Ano, viajes[i].H_inic.Hora
                          , viajes[i].H_inic.Minutos, viajes[i].H_fin.Hora
                          , viajes[i].H_fin.Minutos, viajes[i].Plazas_libres
                          , viajes[i].Viaje, viajes[i].Importe
                          , viajes[i].Estado);
  }

  fclose(fichero);

  free(viajes);
}

void guardar_pasos(T_Pasos *pasos, int N){
  FILE * fichero;
  fichero = fopen("pasos.txt", "w");
  if(fichero == NULL){
    puts("Error al abrir el fichero");
    exit(1);
  }

  int i;
  for(i=0; i<N; i++){
    fprintf(fichero, "%.6i-%s\n", pasos[i].Id_viaje, pasos[i].Poblacion);
  }

  fclose(fichero);

  free(pasos);
}

void guardar_incidencias(T_Incidencias *incidencias, int N){
  FILE * fichero;
  fichero = fopen("incidencias.txt", "w");
  if(fichero == NULL){
    puts("Error al abrir el fichero");
    exit(1);
  }

  int i;
  for(i=0; i<N; i++){
    fprintf(fichero, "%.6i-%.4i-%.4i-%s-%s\n", incidencias[i].Id_viaje
                                            , incidencias[i].Id_us_registra
                                            , incidencias[i].Id_us_incidencia
                                            , incidencias[i].Desc_incidencia
                                            , incidencias[i].Est_incidencia);
  }

  fclose(fichero);

  free(incidencias);
}

//funcion que se usa localmente
static void intercambiar_espacios(char *str){
  int i;
  //para cada caracter de la cadena, hasta que acaba, realizo:
  for(i=0; str[i]!='\0'; i++){          //si es '-', '/' o ':', pongo un espacio
    if(str[i]=='-'||str[i]=='/'||str[i]==':') str[i] = ' ';
    else if(str[i]==' ') str[i] = '_';  //si no, si es un espacio, pongo una _
    else if(str[i]=='_') str[i] = ' ';  //si tampoco, si es una _, pongo un ' '
  }
}

static int contar_elementos_fichero(FILE* fichero){
  int n=0;
  char c;
  fpos_t pos;

  fgetpos(fichero, &pos); //guardo la posicion antes de entrar en la funcion

  do {
    c=fgetc(fichero);
    if(c=='\n') n++;
  } while(!feof(fichero));

  fsetpos(fichero, &pos); //retorno a la posicion del fichero antes de entrar
  return n;               //en la funcion
}

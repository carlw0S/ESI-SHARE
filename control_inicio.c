#include "control_inicio.h"

//DEFINICION DE FUNCIONES PRIVADAS

/*Funcion privada
Cabecera: char * rm_fin_linea(char *, int n);

Precondicion: recibe una cadena de n caracteres

Postcondicion: sustituye el primer caracter '\n' que encuentre por un '\0'.
      Ademas devuelve la cadena.
*/
char * rm_fin_linea(char *, int );

void incicio_sesion(T_Usuarios * usuarios, int N, int *id){
  *id=login(usuarios, N);
  if(*id < 0) pantalla_err_login(usuarios, N, id);
}

int login(T_Usuarios * usuarios, int N){
  char in_user[6], in_pass[9];
  int i, encontrado, correcto, id;

  //pido al usuario que introduzca los datos de inicio de sesion
  puts("Inicie sesion:");
  introducir_credenciales(in_user, in_pass);
  //recorro el vector de los usuarios
  for(i=0, encontrado=0, correcto=0; i<N && encontrado==0; i++){
    if(strcmp(in_user, usuarios[i].User)==0){     //si existe el usuario:
      encontrado=1;                 //marco para salir en la siguiente iteracion
      if(strcmp(in_pass, usuarios[i].Login)==0){  //pruebo la contraseña
        correcto=1;                               //marco que es correcta
        id=usuarios[i].Id_usuario;                //guardo la id del usuario
      }
    }
  }

  if(encontrado==1){          //si el usuario existe
    if(correcto==1){                //si la pass es correcta
      return id;                          //devuelvo a id
    }else return -1;                //si no, devuelvo -1
  }else return -2;            //si no, devuelvo -2
}

void pantalla_err_login(T_Usuarios * usuarios, int N, int * id){
  int o;
  while(*id < 0){ //repito mientras la id sea incorrecta (0, salida)
    if(*id == -1){      //si la contrasena es incorrecta
      puts("**Pass incorrecta**");
      do {
      puts("Que desea hacer?:");
      puts("  1.Volver a intentarlo");
      puts("  2.Salir");
      fflush(stdin);
      scanf("%i", &o);
        switch(o){
          case 1: *id=login(usuarios, N);
          break;
          case 2: *id=0;
          break;
          default: puts("**Opcion Incorrecta**");
        }
      }while(o!=1&&o!=2);
    }else {           //si el usuario no existe
      puts("**El usuario no existe**");
      do {          //imprimo el menu
      puts("Que desea hacer?:");
      puts("  1.Volver a intentarlo");
      puts("  2.Crear un nuevo usuario");
      puts("  3.Salir");
      fflush(stdin);
      scanf("%i", &o);
        switch (o) {        //segun lo que elija
          case 1: *id=login(usuarios, N);   //relogea
          break;
          case 2: puts("crearusuario"); //crear_usuario();
          break;
          case 3: *id=0;      //marco la id para salida
          break;
          default: puts("**Opcion Incorrecta**");   //repite
        }
      } while(o!=1&&o!=2&&o!=3);
    }
  }
}

void menu_principal(T_Usuarios * usuarios, int N, int id){

  int pos, o, perfil;

  if(id > 0){   //si la id es correcta
    do{
      pos=pos_id(usuarios, N, id);

      printf("\n\n  %s\n", usuarios[pos].Nomb_usuario);//imprimo Nomb_usuario

      //segun sea admin o user
      if (strcmp(usuarios[pos].Perfil_usuario, "usuario")==0){
        perfil=1;                       //si es user la salida sera positiva
        puts("\nElija una opcion: ");   //menu para user
        puts("  1.Perfil");
        puts("  2.Mis vehiculos");
        puts("  3.Viajar");
        puts("  4.Incidencias");
        puts("  5.Salir");
        fflush(stdin);            //tomo la opcion elegida
        scanf("%i", &o);
      }else{
        perfil=-1;                      //si es admin la salida sera negativa
        puts("\nElija una opcion: ");     //menu para admin
        puts("  1.Usuarios");
        puts("  2.Vehiculos");
        puts("  3.Viajes");
        puts("  4.Incidencias");
        puts("  5.Salir");
        fflush(stdin);                    //tomo la opcion elegida
        scanf("%i", &o);
      }

      llamadas_menu(usuarios, N, id, o*perfil);//funcion que llama a las demas
                                              //del programa
      puts("  -->Ha vuelto al menu principal");
    }while(o!=5);
  }
}

void llamadas_menu(T_Usuarios * usuarios, int N, int id, int opt){
  //si es negativo sera de admin y si es positivo de user
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
}

void titulo(){
  puts("---------------------------------");    //imprime el titulo del programa
  puts("|           ESI-SHARE           |");
  puts("---------------------------------");
}

void check_usuario_bloqueado(T_Usuarios * usuarios, int N, int * id){
  int pos;

  pos=pos_id(usuarios, N, *id);

  if(strcmp(usuarios[pos].Estado, "bloqueado")==0){//pruebo si esta bloqueado
    puts("**Este usuario esta bloqueado**");
    *id = 0;            //marco la id para salida si lo esta
  }
}

void check_horas_viajes(T_Viajes * viajes, int n){
  time_t chora, vhora;      //variables de hora en segundos desde 1970
  int i;
  double diferencia;
  struct tm haux;         //estrucuta auxiliar para sacar la hora en time_t

  time(&chora);         //guardo el tiempo actual

  for(i=0; i<n; i++){     //para cada viaje:
    if(strcmp(viajes[i].Estado, "abierto")==0){   //si esta abierto:
      haux.tm_sec = 0;                               //relleno la estructura aux
      haux.tm_min = viajes[i].H_fin.Minutos;
      haux.tm_hour = viajes[i].H_fin.Hora;
      haux.tm_mday = viajes[i].F_inic.Dia;
      haux.tm_mon = (viajes[i].F_inic.Mes - 1);
      haux.tm_year = (viajes[i].F_inic.Ano - 1900);

      vhora = mktime(&haux);      //la transformo en time_t

      diferencia = difftime(chora, vhora);      //calculo la diferencia en seg

      if(diferencia >= 3600.0){     //si es mas de una hora:
        strcpy(viajes[i].Estado, "finalizado");    //finalizo el viaje
      }
    }
  }

}

void introducir_credenciales(char user[6], char pass[9]){
  int err;
  char aux[15];

  do {
    if(err==1){     //si hubo un error lo notifico
      puts("**User o pass demasiado largos**");
    }
    err=0;          //reset del error
    printf("  User (5 caracteres): ");     //pido y almaceno el usuario en aux
    fflush(stdin);
    fgets(aux, 15, stdin);
    rm_fin_linea(aux, 15);
    if(strlen(aux)>5){        //si es demasiado largo hay un error
      err=1;
    }else strcpy(user, aux);  //si no, guardo en user

    printf("  Pass (8 caracteres): ");    //igual que antes pero con pass
    fflush(stdin);
    fgets(aux, 15, stdin);
    rm_fin_linea(aux, 15);
    if(strlen(aux)>8){
      err=1;
    }else strcpy(pass, aux);
  } while(err==1);    //mientras la longitud sea excesiva
}

int pos_id(T_Usuarios * usuarios, int n, int id){
  int i, pos, f;
  for(i=0, f=0; i<n&&f==0; i++){
    if(id==usuarios[i].Id_usuario){
      pos=i;
      f=1;
    }
  }
  return pos;
}

//PRIVADA
char * rm_fin_linea(char *str, int n){
  int i, salida;
  char c;
  //recorro la cadena hasta el final o hasta la marca de salida
  for (i=0, salida=0; i<n && salida==0; i++) {
    c=str[i];         //voy tomando los caracteres de la cadena
    if (c=='\n') {    //si es '\n':
      str[i] = '\0';        //lo sustituyo por un '\0'
      salida = 1;           //marco para la salida
    }else if (i==(n-1)) str[i] = '\0';    //si no, en el ultimo caracter pongo
                                          // '\0' por si acaso
  }
  return str;
}

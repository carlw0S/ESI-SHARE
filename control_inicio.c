#include "control_inicio.h"

int login(T_Usuarios * usuarios, int N){
  char in_user[6], in_pass[9];
  int i, encontrado, correcto, id;

  //pido al usuario que introduzca los datos de inicio de sesion
  printf("Inicie sesion:\n");
  printf("  User: ");
  fflush(stdin);
  fgets(in_user, 6, stdin);
  printf("  Pass: ");
  fflush(stdin);
  fgets(in_pass, 9, stdin);

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

  if(encontrado==1){                 //si el usuario existe:
    if(correcto==1){                      //si la contraseña es correcta
      return id;                              //devuelvo la id del usuario
    }else return -1;                      //si no, devuelvo -1
  }else return -2;                   //si no, devuelvo -2
}

void pantalla_err_login(T_Usuarios * usuarios, int N, int * id){
  int o;
  int err=0;
  do {      //repito mientras la id sea incorrecta (0 marca salida del programa)
    if (*id == -1){       //en el caso de que la contraseña sea incorrecta
      puts("\n**PASS INCORRECTA**");

      do{
        err=0;                                //presento el menu y guardo la
        puts("Que desea hacer?");             //opcion del usuario
        puts("  1.Volver a intentar");
        puts("  2.Salir");

        fflush(stdin);
        scanf("%i", &o);

        switch (o) {                          //segun sea esta opcion:
          case 1: {
            puts("\n");
            *id=login(usuarios, N);           //vuevlo a intentar el login
          }
          break;

          case 2: {
            *id=0;                            //marco la id para salir
          }
          break;

          default: {
            err=1;                            //si lo introducido no es correcto
            puts("**Esta opcion no existe**");
          }
          break;
        }
      }while(err==-1);   //repito esto mientras el usuario no elija algo posible

    }else{puts("\n**EL USUARIO NO EXISTE**");   //si el usuario no existe:

    do{
      err=0;                                  //presento el menu
      puts("Que desea hacer?");
      puts("  1.Volver a intentar");
      puts("  2.Crer un nuevo usuario");
      puts("  3.Salir");

      fflush(stdin);                          //guardo la opcion del usuario
      scanf("%i", &o);

      switch (o) {                            //segun sea la opcion:
        case 1: {
          puts("\n");
          *id=login(usuarios, N);             //vuelvo a intentar el login
        }
        break;

        case 2: {
          puts("crearusuario");//crear_usuario();   //creo un nuevo usuario
          puts("\n");
          *id=login(usuarios, N);              //y vuelvo a intentar el login
        }
        break;

        case 3: {
          *id=0;                              //marco la id para la salida
        }
        break;

        default: {
          err=1;                              //si la opcion no es correcta
          puts("**Esta opcion no existe**");
        }
        break;
      }
    }while(err==1);       //repito mientras las opcion no sea correcta

    }
  } while(*id < 0);       //repito todo esto mientras la id sea incorrecta y no
                          //este marcada para salida con un 0
}

int menu_principal(T_Usuarios * usuarios, int N, int id){

  int i, pos, f, o, perfil;

  for(i=0, f=0; i<N&&f==0; i++){          //busco la posicion segun la id
    if (usuarios[i].Id_usuario==id) {
      pos=i;
      f=1;
    }
  }

  printf("%s\n", usuarios[pos].Nomb_usuario);    //imprimo el nombre de usuario

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
  return o*perfil;            //devuelvo la opcion con el correspondiente signo
}

void titulo(){
  puts("---------------------------------");    //imprime el titulo del programa
  puts("|           ESI-SHARE           |");
  puts("---------------------------------");
}

void check_usuario_bloqueado(T_Usuarios * usuarios, int N, int * id){
  int i, f, pos;

  for(i=0, f=0; i<N&&f==0; i++){          //hallo la posicion segun la id
    if (usuarios[i].Id_usuario==*id) {
      pos=i;
      f=1;
    }
  }

  if(strcmp(usuarios[pos].Estado, "bloqueado")){   //compruebo si esta bloqueado
    puts("**Este usuario esta bloqueado**");
    *id = 0;            //marco la id para salida si lo esta
  }
}

char * rm_fin_linea(char *str, int n){
  int i, salida;
  char aux;
  //recorro la cadena hasta el final o hasta la marca de salida
  for (i=0, salida=0; i<n && salida==0; i++) {
    aux=str[i];         //voy tomando los caracteres de la cadena
    if (aux=='\n') {    //si es '\n':
      str[i] = '\0';        //lo sustituyo por un '\0'
      salida = 1;           //marco para la salida
    }else if (i==(n-1)) str[i] = '\0';    //si no, en el ultimo caracter pongo
                                          // '\0' por si acaso
  }
  return str;
}

#include "control_inicio.h"

int login(T_Usuarios * usuarios, int N){
  char in_user[6], in_pass[9];
  int i, encontrado, correcto, id;

  printf("Inicie sesion:\n");
  printf("  User: ");
  fflush(stdin);
  fgets(in_user, 6, stdin);
  printf("  Pass: ");
  fflush(stdin);
  fgets(in_pass, 9, stdin);

  for(i=0, encontrado=0, correcto=0; i<N && encontrado==0; i++){
    if(strcmp(in_user, usuarios[i].User)==0){
      encontrado=1;
      if(strcmp(in_pass, usuarios[i].Login)==0){
        correcto=1;
        id=usuarios[i].Id_usuario;
      }
    }
  }

  if(encontrado==1){
    if(correcto==1){
      return id;
    }else return -1;
  }else return -2;
}

void pantalla_err_login(T_Usuarios * usuarios, int N, int * id){
  int o;
  int err=0;
  do {
    if (*id == -1){
      puts("\n**PASS INCORRECTA**");

      do{
        err=0;
        puts("Que desea hacer?");
        puts("  1.Volver a intentar");
        puts("  2.Salir");

        fflush(stdin);
        scanf("%i", &o);

        switch (o) {
          case 1: {
            puts("\n");
            *id=login(usuarios, N);
          }
          break;

          case 2: {
            *id=0;
          }
          break;

          default: {
            err=1;
            puts("**Esta opcion no existe**");
          }
          break;
        }
      }while(err==-1);

    }else{puts("\n**EL USUARIO NO EXISTE**");

    do{
      err=0;
      puts("Que desea hacer?");
      puts("  1.Volver a intentar");
      puts("  2.Crer un nuevo usuario");
      puts("  3.Salir");

      fflush(stdin);
      scanf("%i", &o);

      switch (o) {
        case 1: {
          err=0;
          puts("\n");
          *id=login(usuarios, N);
        }
        break;

        case 2: {
          puts("crearusuario");//crear_usuario();
          puts("\n");
          *id=login(usuarios, N);
        }
        break;

        case 3: {
          *id=0;
        }
        break;

        default: {
          err=1;
          puts("**Esta opcion no existe**");
        }
        break;
      }
    }while(err==1);

    }
  } while(*id < 0);
}

int menu_principal(T_Usuarios * usuarios, int N, int id){

  int i, pos, f, o, perfil;

  for(i=0, f=0; i<N&&f==0; i++){
    if (usuarios[i].Id_usuario==id) {
      pos=i;
      f=1;
    }
  }

  printf("%s\n", usuarios[pos].Nomb_usuario);

  if (strcmp(usuarios[pos].Perfil_usuario, "usuario")==0){
    perfil=1;
    puts("\nElija una opcion: ");
    puts("  1.Perfil");
    puts("  2.Mis vehiculos");
    puts("  3.Viajar");
    puts("  4.Incidencias");
    puts("  5.Salir");
    fflush(stdin);
    scanf("%i", &o);
  }else{
    perfil=-1;
    puts("\nElija una opcion: ");
    puts("  1.Usuarios");
    puts("  2.Vehiculos");
    puts("  3.Viajes");
    puts("  4.Incidencias");
    puts("  5.Salir");
    fflush(stdin);
    scanf("%i", &o);
  }
  return o*perfil;
}

void titulo(){
  puts("---------------------------------");
  puts("|           ESI-SHARE           |");
  puts("---------------------------------");
}

void check_usuario_bloqueado(T_Usuarios * usuarios, int N, int * id){
  int i, f, pos;

  for(i=0, f=0; i<N&&f==0; i++){
    if (usuarios[i].Id_usuario==*id) {
      pos=i;
      f=1;
    }
  }

  if(strcmp(usuarios[pos].Estado, "bloqueado")){
    puts("**Este usuario esta bloqueado**");
    *id = 0;
  }
}

void rm_fin_linea(char *str, int n){
  int i, salida;
  char aux;
  for (i=0, salida=0; i<n && salida==0; i++) {
    aux=str[i];
    if (aux=='\n') {
      str[i] = '\0';
      salida = 1;
    }else if (i==(n-1)) str[i] = '\0';
  }
}

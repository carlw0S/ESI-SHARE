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
        puts("Que desea hacer?");
        puts("  1.Volver a intentar");
        puts("  2.Salir");

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
            err=0;
            exit(0);
          }
          break;

          default: {
            err=1;
            puts("**Esta opcion no existe**");
          }
        }
      }while(err==-1);

    }else{puts("\n**EL USUARIO NO EXISTE**");

    do{
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
          err=0;
/*
#######################################################################
funcion de piña
          crear_usuario();

#######################################################################
*/

          puts("\n");
          *id=login(usuarios, N);
        }
        break;

        case 3: {
          err=0;
          exit(0);
        }

        default: {
          err=1;
          puts("**Esta opcion no existe**");
        }
      }
    }while(err==1);

    }
  } while(*id < 0);
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

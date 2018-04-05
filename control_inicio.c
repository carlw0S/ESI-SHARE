#include "control_inicio.h"

void comprobacion_horas_viajes(T_Viajes * viajes){

}

//WIP, pendiente de probar
int login(T_Usuarios * usuarios, int N){
  char in_login[6], in_pass[9];
  int i, salida, correcto;

  printf("\nInicie sesion:\n");
  printf("\nUser: ");

  fgets(in_login, 6, stdin);
  rm_fin_linea(in_login, 6);

  for(i=0, salida=0, correcto=0; i<N && salida==0; i++){
    if(strcmp(usuarios[i].User, in_login)){
      salida = 1;
      printf("\nPass: ");

      fgets(in_pass, 9, stdin);
      rm_fin_linea(in_pass, 9);

      if(strcmp(usuarios[i].Login, in_pass)==0){
        correcto=1;
      }
    }
  }

  if(salida==1&&correcto==1){       //si user y pass correctos, devuelve id
    return usuarios[i].Id_usuario;
  }else if(salida==1&&correcto==0){ //si user encontrado y pass mal, devuelve
    return -1;                      //-1
  }else return -2;                  //si user no encontrado, devuelve -2
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

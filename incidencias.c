 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 #include "cargar_guardar_estructuras.h"
 #include "usuarios.h"
 #include "incidencias.h"

 //cabecera: void incidencias_admin (T_Incidencias * incidencia, int * NI)
 //precondicion: estructura incidencia inicializada
 //postcondicion: accede como administrador a toda la estructura
  void incidencias_admin (T_Incidencias * incidencia, int * NI)
  {
    int opcion, salir=0;
    do{
      printf ("Elija una opcion\n 1 - Modificar el estado de una incidencia\n 2 - Bloquear a un usuario\n 3 - volver");
      scanf ("%d",&opcion);
      switch (opcion){
        case 1 :
        mod_incidencias (incidencia, NI);
        break;
        case 2 :
        bloquear_usuario (usuarios, n, id);
        break;
        case 3: salir=1;
        break;
      }
    }while(salir!=1);
  }

 //cabecera: void mod_incidencias (T_Incidencias * incidencia, int * NI)
 //precondicion: estructura incidencia inicializada
 //postcondicion: modifica el estado de una incidencia concreta
 void mod_incidencias (T_Incidencias * incidencia, int * NI)
 {
   int i, mod=1;
   printf ("A contnuacion se listaran todas las incidencias existentes\n\n");
   for (i=0;i<*NI;i++){
     printf ("[%d] %d -",mod,incidencia[i].Id_viaje);
     printf ("%d -",incidencia[i].Id_us_registra);
     printf ("%d\n",incidencia[i].Id_us_incidencia);
     printf ("%s\n",incidencia[i].Desc_incidencia);
     printf (" - %s -\n\n",incidencia[i].Est_incidencia);
     mod++;
   }
   printf ("Seleccione una incidencia\n");
   scanf ("%d",&mod);
   mod--;
   printf("Modifique a continuacion el estado de la incidencia (abierta, valdada, cerrada)\n");
   fgets (incidencia[mod].Est_incidencia, 9, stdin);
   printf("Estado de la incidencia modificada con exito");
 }


 //cabecera: void incidencias_user (T_Incidencias * incidencia)
 //precondicion: estructura incidencia inicializada
 //postcondicion: accede como usuario a toda la estructura
  void incidencias_user (T_Incidencias ** incidencia, int * NI)
  {
   int opcion, salir=0;
   do{
    printf ("Elija una opcion\n 1 - Ver una incidencia existente\n 2 - Crear  una nueva incidencia\n 3 - Salir\n");
    scanf ("%d",&opcion);
    switch (opcion){
        case 1 :
        ver_incidencias (*incidencia, NI);
        break;
        case 2 :
        crear_incidencia (incidencia, NI);
        break;
        case 3 : salir=1;
        break;
      }
    }while(salir!=1);
  }

 //cabecera: void ver_incidencias (T_Incidencias * incidencia)
 //precondicion: estructura incidencia definida
 //postcondicion: mostrara por pantalla todas las incidencias existentes
   void ver_incidencias (T_Incidencias * incidencia, int * NI)
   {
    int i;
    for (i=0;i<*NI;i++){
      printf ("%d -",incidencia[i].Id_viaje);
      printf ("%d -",incidencia[i].Id_us_registra);
      printf ("%d\n",incidencia[i].Id_us_incidencia);
      printf ("%s\n",incidencia[i].Desc_incidencia);
      printf (" - %s -\n\n",incidencia[i].Est_incidencia);
    }
   }

 //cabecera: void crear_incidencia (T_Incidencias * incidencia, int * NI)
 //precondicion: estructura incidencia definda y recibido el parametro NI
 //postcondicion: se habrá creado una estructura definda por el usuario y se habra incrementado NI
  void crear_incidencia (T_Incidencias ** incidencia, int * NI)
   {
    T_Incidencias * aux;
    aux=*incidencia;
    aux=(T_Incidencias *) realloc (aux, ((*NI)+1)*sizeof(T_Incidencias));
    printf ("Introduzca el identificador del viaje (4 digitos)\n");
    fflush(stdin);
    scanf ("%d", &(aux[*NI]).Id_viaje);
    printf ("Introduzca su identificador de usuario y el del usuario afectado\n");
    fflush(stdin);
    scanf ("%d%d", &(aux[*NI]).Id_us_registra, &aux[*NI].Id_us_incidencia);
    printf ("Explica brevemente que ha sucedido (maximo 100 caracteres)\n");
    fflush(stdin);
    fgets (aux[*NI].Desc_incidencia, 101, stdin);
    strcpy(aux[*NI].Est_incidencia, "abierta");
    *NI = *NI+1;
    *incidencia=aux;
    printf ("Se ha archivado con exito, sera revisada por un administrador\n");
   }
